#include <stdio.h>

/*
문제 : 두 정수 X, Y(-10^9 <= X, Y <= 10^9)가 주어질 때, X + Y를 구한다.

해결 방법 : X + Y를 계산한다.

주요 알고리즘 : 구현

출처 : CERC 2008 PA번
*/

int main(void) {
    int t, x, y;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d %d", &x, &y);
        printf("%d\n", x + y);
    }
    return 0;
}