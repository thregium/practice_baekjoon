#include <stdio.h>

/*
문제 : N(N <= 100) 길이의 배열을 반으로 접는 것을 반복할 때, 마지막 남은 두 원소 중 어느 것이 더 큰지 확인한다.

해결 방법 : 시뮬레이션을 통해 배열을 반으로 접는것을 실제로 반복해보면 된다. 배열을 접은 다음에는 N을 절반으로 줄인 다음
다시 반복하여 N이 2가 될 때 까지 반복한다.

주요 알고리즘 : 구현, 시뮬레이션

출처 : LCPC 2011 A번
*/

int a[128];

int main(void) {
    int t, n;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        while (n > 2) {
            for (int i = 0, j = n - 1; i <= j; i++, j--) {
                a[i] += a[j];
            }
            n = (n + 1) >> 1;
        }
        if (a[0] > a[1]) printf("Case #%d: Alice\n", tt);
        else printf("Case #%d: Bob\n", tt);
    }
    return 0;
}