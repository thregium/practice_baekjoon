#include <stdio.h>

/*
문제 : C(C <= 2 * 10^6) 이하의 자연수 중 N(N <= 100)개의 자연수 가운데 하나 이상으로 나누어 떨어지는 수의 개수를 구한다.

해결 방법 : 직접 구해본다.

주요 알고리즘 : 브루트 포스, 구현

출처 : USACO 2007M B1번
*/

int a[128];

int main(void) {
    int n, c, t, r = 0;
    scanf("%d %d", &n, &c);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= c; i++) {
        t = 0;
        for (int j = 0; j < n; j++) {
            if (i % a[j] == 0) {
                t++;
                break;
            }
        }
        if (t) r++;
    }
    printf("%d", r);
    return 0;
}