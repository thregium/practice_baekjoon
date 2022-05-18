#include <stdio.h>

/*
문제 : N(N <= 2222222)개의 자연수(<= 2222222)가 주어질 때, 하나의 수를 빼고 XOR한 값이
가장 큰 것의 값을 구한다.

해결 방법 : 모든 수를 XOR한 것에서 하나씩 XOR을 해 가면서 그 중 가장 결과가 큰 것을 고르면 된다.

주요 알고리즘 : 수학, 비트마스킹, 브루트 포스

출처 : 가톨릭대 2회 B번
*/

int a[2228224];

int main(void) {
    int n, xsum = 0, best = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        xsum ^= a[i];
    }
    if (xsum > best) best = xsum;
    for (int i = 0; i < n; i++) {
        if ((xsum ^ a[i]) > best) best = (xsum ^ a[i]);
    }
    printf("%d%d", best, best);
    return 0;
}