#include <stdio.h>

/*
문제 : N(N <= 100)개의 소시지를 M(M <= 100)등분 하려고 할 때, 필요한 최소한의 칼질 횟수를 구한다.

해결 방법 : 먼저 소시지를 N / M 크기로 자른다. 그 다음으로 남은 (M - N) / M 크기 소시지들은 또다시
M등분 하고, 이를 반복하면 총 M - gcd(N, M)회 자르게 된다.

주요 알고리즘 : 수학, 정수론

출처 : COCI 13/14#1 2번
*/

int gcd(int a, int b) {
    if (a == 0) return b;
    if (b == 0) return a;
    return a > b ? gcd(a % b, b) : gcd(a, b % a);
}

int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);
    printf("%d", m - gcd(n, m));
    return 0;
}