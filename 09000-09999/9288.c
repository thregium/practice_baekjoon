#include <stdio.h>

/*
문제 : 주사위 2개를 던져 합이 N이 되는 쌍을 전부 구한다. 순서만 다른 것은 같은 것으로 본다.

해결 방법 : i <= j인 1 ~ 6 사이 쌍을 전부 확인해 합이 N이 되는 쌍을 모두 출력한다.

주요 알고리즘 : 브루트 포스, 수학

출처 : UVa 2013 C번
*/

int main(void) {
    int t, n;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        scanf("%d", &n);
        printf("Case %d:\n", tt);
        for (int i = 1; i <= 6; i++) {
            for (int j = i; j <= 6; j++) {
                if (i + j == n) {
                    printf("(%d,%d)\n", i, j);
                }
            }
        }
    }
    return 0;
}