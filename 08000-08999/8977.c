#include <stdio.h>

/*
문제 : N(N <= 100)개의 자연수(<= 100)가 주어질 때, 순서대로 돌면서 B(B <= 10^9)번째부터 K(K <= 100)개의 수의 합을 구한다.

해결 방법 : 나머지 연산을 통해 시작점을 구하고, 그 점부터 K개의 수의 합은 직접 더해나가면 된다.

주요 알고리즘 : 수학

출처 : CHCI 2008RS 1번
*/

int a[128];

int main(void) {
    int n, k, b, r = 0;
    scanf("%d %d %d", &n, &k, &b);
    b--;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < k; i++) {
        r += a[(b + i) % n];
    }
    printf("%d", r);
    return 0;
}