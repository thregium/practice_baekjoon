#include <stdio.h>

/*
문제 : Lm * Cm(Lm, Cm <= 32) 크기의 격자에서 주어진 Li * Ci(Li, Ci <= 12) 크기의 부분과 일치하는 부분을
몇 개 찾을 수 있는 지 구한다.

해결 방법 : Lm, Cm, Li, Ci의 크기가 작으므로 4중 for문으로 모든 경우를 찾아보면 된다.

주요 알고리즘 : 브루트 포스

출처 : NZPC 2012 F번
*/

char rig[16][16], map[48][48];

int main(void) {
    int t, li, ci, lm, cm, r, ok;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d %d", &li, &ci);
        for (int i = 0; i < li; i++) {
            scanf("%s", rig[i]);
        }
        scanf("%d %d", &lm, &cm);
        for (int i = 0; i < lm; i++) {
            scanf("%s", map[i]);
        }

        r = 0;
        for (int i = 0; i <= lm - li; i++) {
            for (int j = 0; j <= cm - ci; j++) {
                ok = 1;
                for (int ii = 0; ii < li; ii++) {
                    for (int jj = 0; jj < ci; jj++) {
                        if (rig[ii][jj] != map[i + ii][j + jj]) ok = 0;
                    }
                }
                r += ok;
            }
        }
        printf("%d\n", r);
    }
    return 0;
}