#include <stdio.h>
#include <string.h>

/*
문제 : 9 * 9 크기로 각 위치에 있는 병력의 종류가 주어진다. 가로, 세로, 3 * 3 크기 사각형으로
각 병력을 나누었을 때 모든 경우 각 칸의 병력 종류가 모두 다르게 되는 지 구한다.
병력은 모두 9가지로 문제에 주어진다.

해결 방법 : 각 병력의 종류를 확인하고 수로 그 값을 바꾼다. 그 다음 스도쿠 규칙을 따르는 지 확인하면 된다.

주요 알고리즘 : 구현

출처 : Manila 2016 G번
*/

char buff[8];
char* p[9] = { "O", "WO", "WS", "ES", "MS", "CS", "IS", "OS", "SS" };
int sdk[9][9], cnt[9];

int main(void) {
    int n, r, t;
    scanf("%d", &n);
    for (int tt = 0; tt < n; tt++) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                scanf("%s", buff);
                t = 0;
                for (int k = 0; k < 9; k++) {
                    if (!strcmp(buff, p[k])) {
                        t++;
                        sdk[i][j] = k;
                    }
                }
                if (t != 1) return 1;
            }
        }

        r = 1;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cnt[sdk[i][j]]++;
            }
            for (int j = 0; j < 9; j++) {
                if (cnt[j] != 1) r = 0;
                cnt[j] = 0;
            }
        }
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cnt[sdk[j][i]]++;
            }
            for (int j = 0; j < 9; j++) {
                if (cnt[j] != 1) r = 0;
                cnt[j] = 0;
            }
        }
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cnt[sdk[i / 3 * 3 + j / 3][i % 3 * 3 + j % 3]]++;
            }
            for (int j = 0; j < 9; j++) {
                if (cnt[j] != 1) r = 0;
                cnt[j] = 0;
            }
        }
        printf("%s\n", r ? "all 3" : "not");
    }
    return 0;
}