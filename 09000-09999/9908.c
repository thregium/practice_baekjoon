#include <stdio.h>

/*
문제 : R(R <= 40) * C(C <= 20) 크기의 직사각형에서 N(N < 100)개의 지점이 포함되지 않는
가장 넓은 평행한 직사각형의 넓이를 구한다.

해결 방법 : R과 C의 범위가 작기 때문에 브루트 포스로 모든 경우를 살펴보면 된다.

주요 알고리즘 : 브루트 포스

출처 : NOIS 2002 2번
*/

int a[64][64];

int main(void) {
    int r, c, n, x, y, t, res = 0;
    scanf("%d %d", &r, &c);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &x, &y);
        a[x][y] = 1;
    }
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            for (int ii = i; ii <= r; ii++) {
                for (int jj = j; jj <= c; jj++) {
                    t = 0;
                    for (int iii = i; iii <= ii; iii++) {
                        for (int jjj = j; jjj <= jj; jjj++) t |= a[iii][jjj];
                    }
                    if (!t && (ii - i + 1) * (jj - j + 1) > res) res = (ii - i + 1) * (jj - j + 1);
                }
            }
        }
    }

    printf("%d", res);
    //if (r == 6 && c == 10) return 1;
    return 0;
}