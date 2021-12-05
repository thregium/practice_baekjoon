#include <stdio.h>

/*
문제 : N(N <= 10^6)개의 동전의 앞, 뒷면 여부가 주어질 때, 모든 동전을 같은 면으로 만들기 위해 뒤집어야 하는 최소 횟수를 구한다.

해결 방법 : 모든 동전을 앞면으로 만들 때와 뒷면으로 만들 때를 비교해서 더 많은 쪽으로 하면 된다.

주요 알고리즘 : 그리디 알고리즘?

출처 : ILO 2010B 2-1번
*/

int main(void) {
    int n, x, u = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        u += x;
    }
    if (u > n - u) printf("%d", n - u);
    else printf("%d", u);
    return 0;
}