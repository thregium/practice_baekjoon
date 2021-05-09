#include <stdio.h>

/*
문제 : 야구에서 각 선수들이 이닝(N <= 50)별로 얻는 결과가 미리 정해져 있다고 가정한다.
이때, 4번 타자는 반드시 첫 번째 선수로 한다면 나머지 선수들의 타선을 조절해 가장 높은 점수를 낼 때의 점수를 구한다.
단, 각 이닝별로 아웃을 기록하는 타자가 한명은 존재하고 안타 이상의 결과가 나온 경우 모든 주자는 동일하게 진루한다고 가정한다.

해결 방법 : 브루트 포스를 통해 모든 타순을 조사해본다. 각 경우에서 얻는 점수를 확인할 때에는
현재 타자와 진루한 루, 아웃 횟수를 변수로 두고 게임 진행을 따라가면 된다.
아웃 카운트가 3 이하일 동안 계속 타자를 세우는 것을 반복한다. 아웃인 경우 아웃 카운트를 늘리고, 안타 이상인 경우에는 
각 주자들을 진루시킨 다음 홈에 도착한 주자들을 세어서 점수에 더해주면 된다. 또, 각 타자의 순서가 끝나면 다음 타자를 세우는 것도 잊지 말아야 한다.

주요 알고리즘 : 구현, 브루트 포스
*/

int inning[64][16], sel[9], chk[9] = { 1, 0 };
int n, highscore = 0;

int getscore(void) {
    int score = 0, out = 0, player = 0, bases[8] = { 0, };
    for (int i = 0; i < n; i++) {
        out = 0;
        for (int j = 0; j < 8; j++) bases[j] = 0;
        while (out < 3) {
            bases[0] = 1;
            switch (inning[i][sel[player]]) {
            case 0:
                out++;
                break;
            case 1:
            case 2:
            case 3:
            case 4:
                for (int j = 3 + inning[i][sel[player]]; j >= inning[i][sel[player]]; j--) {
                    bases[j] = bases[j - inning[i][sel[player]]];
                }
                for (int j = inning[i][sel[player]] - 1; j > 0; j--) bases[j] = 0;
                break;
            }
            for (int j = 4; j < 8; j++) {
                score += bases[j];
                bases[j] = 0;
            }
            player = (player + 1) % 9;
        }
    }
    return score;
}

void track(int n, int r) {
    if (n == r) {
        int score = getscore();
        if (score > highscore) {
            highscore = score;
        }
        return;
    }

    if (r == 3) {
        sel[r] = 0;
        track(n, r + 1);
        return;
    }

    for (int i = 1; i < n; i++) {
        if (chk[i]) continue;
        chk[i] = 1;
        sel[r] = i;
        track(n, r + 1);
        chk[i] = 0;
    }
}

int main(void) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 9; j++) {
            scanf("%d", &inning[i][j]);
        }
    }
    track(9, 0);
    printf("%d", highscore);
    return 0;
}