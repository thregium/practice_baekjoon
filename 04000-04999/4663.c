#include <stdio.h>
#include <string.h>

/*
문제 : 주어진 문자열 정보를 바탕으로 표를 만든다. 첫 줄에는 각 열의 정렬 방식이,
이후 줄들에는 각 칸의 데이터가 주어진다.

해결 방법 : 먼저 각 칸의 데이터를 파싱하여 각각 저장한다. 그 후, 각 열마다 길이와 시작점을 구한 다음,
표의 틀을 결과 배열에 저장한다. 그 후 글자들을 결과 배열에 추가하고, 데이터를 저장하면 된다.

주요 알고리즘 : 구현, 문자열, 파싱

출처 : MidC 2000 F번
*/

char buff[128], layout[32], data[32][32][128], res[32][128];
int len[32], start[32];

void cpyto(int x, int y, int len, char* from, char layout) {
    //해당 지점에 주어진 정렬 방식대로 문자열을 추가한다.
    int l = strlen(from), s = 0;
    if (layout == '<') s = y + 2;
    else if (layout == '>') s = y + len - l + 2;
    else if (layout == '=') {
        s = y + ((len - l) >> 1) + 2;
    }
    else return;
    for (int i = 0; from[i]; i++) {
        res[x][s + i] = from[i];
    }
}

int main(void) {
    int n, m;
    char* c;
    //freopen("E:\\PS\\ICPC\\North America\\Mid Central\\mcpc2000\\fab\\fab.in", "r", stdin);
    //freopen("E:\\PS\\ICPC\\North America\\Mid Central\\mcpc2000\\fab\\fab_t.out", "w", stdout);
    fgets(buff, 100, stdin);
    strcpy(layout, buff);
    if (layout[strlen(layout) - 1] == '\n') layout[strlen(layout) - 1] = '\0';
    while (1) {
        n = 0;
        m = strlen(layout);
        while (1) {
            //주어진 데이터를 파싱한다.
            fgets(buff, 100, stdin);
            if (buff[strlen(buff) - 1] == '\n') buff[strlen(buff) - 1] = '\0';
            if (strchr(buff, '<') || strchr(buff, '=') || strchr(buff, '>') || strchr(buff, '*')) break;
            c = strtok(buff, "&");
            strcpy(data[n][0], c);
            for (int i = 1; i < m; i++) {
                c = strtok(NULL, "&");
                strcpy(data[n][i], c);
            }
            n++;
        }
        for (int i = 0; i < m; i++) {
            //각 열의 길이를 구한다.
            len[i] = 0;
            for (int j = 0; j < n; j++) {
                if (strlen(data[j][i]) > len[i]) len[i] = strlen(data[j][i]);
            }
        }
        start[0] = 0;
        for (int i = 1; i <= m; i++) start[i] = start[i - 1] + len[i - 1] + 3;
        
        for (int i = 0; i <= n + 2; i++) {
            //표의 틀을 잡는다.
            for (int j = 0; j <= start[m]; j++) {
                if ((i == 0 && j == 0) || (i == n + 2 && j == 0) ||
                    (i == 0 && j == start[m]) || (i == n + 2 && j == start[m])) res[i][j] = '@';
                else if (j == 0 || j == start[m]) res[i][j] = '|';
                else if (i == 0 || i == 2 || i == n + 2) res[i][j] = '-';
                else res[i][j] = ' ';
            }
            res[i][start[m] + 1] = '\0';
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j <= n + 1; j++) res[j][start[i]] = '|';
            res[2][start[i]] = '+';
        }

        for (int i = 0; i < m; i++) {
            //표에 데이터를 추가한다.
            cpyto(1, start[i], len[i], data[0][i], layout[i]);
            for (int j = 1; j < n; j++) {
                cpyto(j + 2, start[i], len[i], data[j][i], layout[i]);
            }
        }

        for (int i = 0; i <= n + 2; i++) {
            //표를 출력한다.
            printf("%s\n", res[i]);
        }
        if (!strcmp(buff, "*")) break;
        strcpy(layout, buff);
    }
    return 0;
}