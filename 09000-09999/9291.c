#include <stdio.h>

/*
문제 : 스도쿠를 푼 것이 주어질 때, 주어진 것이 제대로 푼 것인지 확인한다. 단, 수는 1부터 9까지로 제대로 적었다고 한다.

해결 방법 : 각 행, 열, 사각형마다 같은 수가 나오지 않는지 확인하면 된다.

주요 알고리즘 : 구현

출처 : UVaH 2013 F번
*/

int sudo[9][9], chk[16];

int main(void) {
    int t, n, r;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                scanf("%d", &sudo[i][j]);
            }
        }

        r = 1;
        for (int i = 0; i < 9; i++) {
            for (int j = 1; j <= 9; j++) chk[j] = 0;
            for (int j = 0; j < 9; j++) {
                if (chk[sudo[i][j]]) r = 0;
                else chk[sudo[i][j]] = 1;
            }
            for (int j = 1; j <= 9; j++) chk[j] = 0;
            for (int j = 0; j < 9; j++) {
                if (chk[sudo[j][i]]) r = 0;
                else chk[sudo[j][i]] = 1;
            }
        }
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 1; k <= 9; k++) chk[k] = 0;

                for (int ii = 0; ii < 3; ii++) {
                    for (int jj = 0; jj < 3; jj++) {
                        if (chk[sudo[i * 3 + ii][j * 3 + jj]]) r = 0;
                        else chk[sudo[i * 3 + ii][j * 3 + jj]] = 1;
                    }
                }
            }
        }
        printf("Case %d: %s\n", tt, r ? "CORRECT" : "INCORRECT");
    }
    return 0;
}