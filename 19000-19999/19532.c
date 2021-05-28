#include <stdio.h>

/*
문제 : Ax + By = C, Dx + Ey = F가 성립하는 x, y의 값을 구한다. 단, x와 y는 -999 이상 999 이하의 자연수이고, 유일하다.

해결 방법 : x와 y의 범위가 충분히 작으므로 브루트 포스를 통해 가능한 모든 x와 y값에 대해 가능한 값이 나올 때 까지 확인한다.

주요 알고리즘 : 브루트 포스

출처 : UCPC 2020예 A번
*/

int main(void) {
    int a, b, c, d, e, f;
    scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);
    for (int x = -999; x <= 999; x++) {
        for (int y = -999; y <= 999; y++) {
            if (a * x + b * y == c && d * x + e * y == f) {
                printf("%d %d", x, y);
                return 0;
            }
        }
    }
    return 0;
}