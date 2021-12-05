#include <stdio.h>

/*
문제 : K(K <= 20)가 주어질 때 (1 + x)(1 + x + x^2)(1 + x + ... + x^k)의 값에서 N(N <= K * (K - 1) / 2)차항을 구한다.

해결 방법 : 간단한 다이나믹 프로그래밍을 통해 답을 구할 수 있다. K가 올라갈 때 마다 해당하는 값을 곱해나가면 된다.

주요 알고리즘 : 수학, DP

출처 : 연세대 2015 D번
*/

long long mem[32][256];

int main(void) {
    int t, k, n;
    mem[1][0] = 1, mem[1][1] = 1;
    for (int i = 2; i <= 20; i++) {
        for (int j = 0; j <= i; j++) {
            for (int k = 0; k <= ((i - 1) * i) >> 1; k++) mem[i][j + k] += mem[i - 1][k];
        }
    }
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d %d", &k, &n);
        printf("%lld\n", mem[k][n]);
    }
    return 0;
}