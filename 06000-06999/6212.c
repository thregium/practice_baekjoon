#include <stdio.h>

/*
문제 : M부터 N(M <= N <= 2 * 10^9, N - M <= 500000)까지의 수들에 있는 각 숫자의 개수를 구한다.

해결 방법 : M부터 N까지의 모든 수에 대해 각 숫자를 세면 된다.

주요 알고리즘 : 브루트 포스, 수학

출처 : USACO 2006D B3번
*/

int cnt[10];

int main(void) {
    int m, n;
    scanf("%d %d", &m, &n);
    for (int i = m; i <= n; i++) {
        for (int j = i; j; j /= 10) cnt[j % 10]++;
    }
    for (int i = 0; i < 10; i++) printf("%d ", cnt[i]);
    return 0;
}