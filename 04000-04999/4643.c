#include <stdio.h>
#include <string.h>

/*
문제 : 최대 16팀, 4라운드로 구성된 토너먼트의 경기 결과가 주어진다. 각 경기가 어떤 라운드에 있었는지를 알아낸 다음 대진표를 출력한다.
단, 토너먼트에서 2라운드 또는 그 이후부터 경기에 들어가는 팀들이 존재할 수 있다.
대진표는 다음과 같이 작성한다. 팀의 이름을 적을 때에는 각 라운드별 팀의 이름 가운데 가장 긴 것에서 2칸씩 여유를 두고 나머지 칸에는
_를 쓴다. 1라운드의 각 팀들은(모든 팀들이 1라운드부터 있는 경우) 2줄씩 떼서 출력한다. 그리고 그 사이를 \과 /를 통해
대각선으로 이어야 하고 2라운드 이상의 팀들은 그 이어진 위치에서 출력하기 시작해야 한다.
예시 : 
5
apple banana
banana coconut
banana
Tournament 1
_apple__
        \_banana__
_banana_/         \
                   \_banana_
                   /
         _coconut_/

해결 방법 : 먼저, 각 경기가 몇 라운드의 몇 번째 경기였는지를 확인해야 한다.
이는 각 라운드에서 이후 라운드로 진출하는 팀이 생긴다는 점을 이용해 확인 가능하다. 해당 경기 이후의 경기들(또는 최종 승자)에서
해당 경기의 팀명 중 겹치는 것이 하나는 존재할 것이기 때문이다. 이 경기들 가운데 가장 먼저 나온 경기가 해당 경기의 승자가
진출한 다음 대회일 것이므로 그 라운드의 이전 라운드임을 알 수 있다. 또한, 경기 번호 역시 이름이 겹치는 곳의 위치에 따라
위쪽이면 해당 번호의 2배 - 1, 아래쪽이면 2배를 해주면 간단히 알 수 있다.(1부터 시작일 때)

이제 얻은 정보들을 통해 대진표를 작성한다.
이때, 위에서 각 라운드별로 가장 긴 팀명의 길이를 전처리 해두는 것이 좋다. 전처리가 끝나면 각 경기별로 대진을 작성한다.
각 대진의 가로와 세로 위치를 알아낸 다음, 각 줄에 _를 포함한 팀명을 출력한다. 그 다음 \과 /를 이용해 두 팀을 하나로 모으게
해야 한다. 마지막으로, 최종 승자를 끝에 출력하면 된다.
가로 위치는 비트 연산을 통해 각 라운드 별 팀간 간격과 해당 라운드의 최대 팀 수를 구하면 알아낼 수 있고,
세로 위치는 이전 라운드의 가장 긴 팀명의 길이의 합에 대각선 구간을 비트 연산을 통해 알아내서 더하면 된다.

주요 알고리즘 : 구현, 그리디 알고리즘

출처 : MidC 2003 H번
*/

typedef struct bracket {
    //각 경기의 정보들, 팀명1, 팀명2, 라운드(역순), 경기 번호
    char team1[16];
    char team2[16];
    int level;
    int ht;
} bracket;

char winner[16], result[128][128]; //최종 승자와 그려진 대진표
int longest[16], ends[128]; //라운드별 가장 긴 팀명의 길이와 각 높이 별로 출력해야 하는 길이
int n, hlv = 0, top = 0, bottom = 0; //N, 최고 라운드, 출력의 위쪽 끝, 아래쪽 끝
bracket compete[32];

int getlevel(int start, char* team) {
    //start 이후의 경기에서 해당 팀이 진출한 첫 경기의 라운드를 가져온다.
    for (int i = start + 1; i < n / 2; i++) {
        if (!strcmp(team, compete[i].team1) || !strcmp(team, compete[i].team2)) return compete[i].level;
    }
    if (!strcmp(team, winner)) return 0;
    else return -1;
}

int getht(int start, char* team) {
    //해당 경기의 경기 번호를 찾아낸다.
    for (int i = start + 1; i < n / 2; i++) {
        if (!strcmp(team, compete[i].team1)) return compete[i].ht * 2 - 1;
        if (!strcmp(team, compete[i].team2)) return compete[i].ht * 2;
    }
    return 1;
}

int getsize(int lv) {
    //각 레벨별 팀간 간격을 알아낸다.
    return 1 << (hlv - lv);
}

int getheight(int lv, int ht) {
    //해당 경기의 중간 높이를 알아낸다.
    int size = getsize(lv) * 2;
    int max = (1 << (lv - 1));
    return 64 + size * (ht * 2 - 1 - max);
}

int getcolumn(int lv) {
    //해당 경기의 시작 열을 알아낸다.
    int c = 0;
    for (int i = lv + 1; i <= hlv; i++) {
        c += longest[i] + 2 + (1 << (hlv - i));
    }
    return c;
}

int main(void) {
    int lt1, lt2, x, y, sz;
    //freopen("C:\\1_공부\\PS\\ICPC\\North America\\Mid Central\\mcpc2003\\tourn\\tourn.in", "r", stdin);
    //freopen("C:\\1_공부\\PS\\ICPC\\North America\\Mid Central\\mcpc2003\\tourn\\tourn_check.out", "w", stdout);
    for (int tt = 1;; tt++) {
        scanf("%d", &n);
        if (n < 0) break;
        hlv = 0, top = 64, bottom = 64;
        for (int i = 0; i < n / 2; i++) {
            scanf("%s %s", compete[i].team1, compete[i].team2);
        }
        scanf("%s", winner);
        for (int i = n / 2 - 1; i >= 0; i--) {
            //해당 경기의 두 팀이 진출한 라운드를 알아낸다.
            lt1 = getlevel(i, compete[i].team1);
            lt2 = getlevel(i, compete[i].team2);
            if (lt1 > lt2) {
                //첫 번째 팀이 진출한 경우
                compete[i].level = lt1 + 1;
                compete[i].ht = getht(i, compete[i].team1);
            }
            else {
                //두 번째 팀이 진출한 경우
                compete[i].level = lt2 + 1;
                compete[i].ht = getht(i, compete[i].team2);
            }

            //가장 많이 간 라운드와 각 라운드별 가장 긴 팀명 업데이트
            if (compete[i].level > hlv) hlv = compete[i].level;
            if (longest[compete[i].level] < strlen(compete[i].team1)) longest[compete[i].level] = strlen(compete[i].team1);
            if (longest[compete[i].level] < strlen(compete[i].team2)) longest[compete[i].level] = strlen(compete[i].team2);
        }
        for (int i = 0; i < n / 2; i++) {
            x = getheight(compete[i].level, compete[i].ht);
            y = getcolumn(compete[i].level);
            sz = getsize(compete[i].level);
            for (int j = y; j < y + longest[compete[i].level] + 2; j++) {
                //각 팀명을 출력한다.
                if (j > y && compete[i].team1[j - y - 1]) result[x - sz][j] = compete[i].team1[j - y - 1];
                else result[x - sz][j] = '_';
                if (j > y && compete[i].team2[j - y - 1]) result[x + sz][j] = compete[i].team2[j - y - 1];
                else result[x + sz][j] = '_';
            }
            y += longest[compete[i].level] + 2;
            if (ends[x - sz] < y - 1) ends[x - sz] = y - 1;
            if (ends[x + sz] < y - 1) ends[x + sz] = y - 1;
            for (int j1 = x - sz + 1, j2 = x + sz; j1 < j2; j1++, j2--) {
                //각 대각선들을 출력한다.
                result[j1][y] = '\\';
                result[j2][y] = '/';
                if (ends[j1] < y) ends[j1] = y;
                if (ends[j2] < y) ends[j2] = y;
                y++;
            }
            if (x - sz < top) top = x - sz;
            if (x + sz > bottom) bottom = x + sz;
        }
        for (int i = 0; i < strlen(winner) + 2; i++) {
            if (i == 0 || i == strlen(winner) + 1) result[64][i + getcolumn(0)] = '_';
            else result[64][i + getcolumn(0)] = winner[i - 1];
        }
        ends[64] = getcolumn(0) + strlen(winner) + 1;

        printf("Tournament %d\n", tt);
        for (int i = top; i <= bottom; i++) {
            for (int j = 0; j <= ends[i]; j++) {
                if (result[i][j]) printf("%c", result[i][j]); //위에서 저장된 출력들을 실제로 출력한다.
                else printf(" ");
                result[i][j] = '\0'; //출력이 끝나면 초기화한다.
            }
            ends[i] = 0;
            printf("\n");
        }
        for (int i = 0; i < n / 2; i++) {
            for (int j = 0; j < 16; j++) {
                //팀명이 겹칠 수 있으므로 팀명도 초기화한다.
                compete[i].team1[j] = '\0';
                compete[i].team2[j] = '\0';
            }
        }
        for (int i = 1; i <= hlv; i++) longest[i] = 0; //각 라운드별로 가장 긴 팀명도 초기화한다.
    }
    return 0;
}