#include <stdio.h>

/*
문제 : 두 자연수 N과 C(N, C <= 1000)가 주어질 때, 1000 이하의 소수 중 가운데부터 양쪽으로 C개를 차례로 출력한다.
이때, 1은 소수로 계산하고, 범위를 넘어가는 경우 범위 내의 소수만 출력한다.

해결 방법 : 먼저 1000 이내의 소수를 전부 구한 다음, 경우를 나누어 소수들을 출력하면 된다.

주요 알고리즘 : 구현, 수학, 소수 판정

출처 : SCUSA 1996 1번
*/

int sieve[1024], prime[256];
int pp = 0;

int big(int a, int b) {
    return a > b ? a : b;
}

int main(void) {
    int n, c, p, m;
    //freopen("E:\\PS\\ICPC\\North America\\South Central\\1996\\cuts.in", "r", stdin);
    prime[pp++] = 1;
    for (int i = 2; i <= 1024; i++) {
        if (sieve[i]) continue;
        prime[pp++] = i;
        for (int j = i * 2; j <= 1024; j += i) sieve[j] = 1;
    }
    while (scanf("%d %d", &n, &c) != EOF) {
        for (p = 0; prime[p] <= n; p++);
        m = (p - 1) >> 1;
        printf("%d %d: ", n, c);
        for (int i = big(0, m - c + 1); i < p && ((p & 1) ? i < m + c : i <= m + c); i++) {
            printf("%d ", prime[i]);
        }
        printf("\n\n");
    }
    return 0;
}