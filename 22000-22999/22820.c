#include <stdio.h>

/*
문제 : 5 * 5 크기의 격자에 0과 1이 있다. 이때, 1로만 이루어진 가장 넓이가 넓은 직사각형의 넓이를 구한다.

해결 방법 : 격자의 크기가 작으므로 가능한 모든 범위를 살펴보면 된다.

주요 알고리즘 : 브루트 포스

출처 : JDC 2001 A번
*/

int grid[8][8];

int main(void) {
    int m, t, b;
    scanf("%d", &m);
    for (int mm = 0; mm < m; mm++) {
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                scanf("%d", &grid[i][j]);
            }
        }
        b = 0;
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                for (int k = i; k < 5; k++) {
                    for (int l = j; l < 5; l++) {
                        t = 1;
                        for (int x = i; x <= k; x++) {
                            for (int y = j; y <= l; y++) {
                                if (!grid[x][y]) t = 0;
                            }
                        }
                        if (t == 1 && (k - i + 1) * (l - j + 1) > b) b = (k - i + 1) * (l - j + 1);
                    }
                }
            }
        }
        printf("%d\n", b);
    }
    return 0;
}