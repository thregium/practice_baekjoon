#include <stdio.h>

/*
문제 : 자연수 M(4 <= M <= 100000), A, B(1 <= A <= B <= 1000)가 주어질 때,
곱이 M 이하며 서로의 비율이 A / B 이상 1 이하인 두 소수 쌍 P, Q 가운데 서로의 곱이 가장 큰 것을 구한다.

해결 방법 : M의 범위가 크지 않으므로 먼저 에라토스테네스의 체를 이용해 100000 이하의 모든 소수의 값을
전처리한다. 그리고 브루트 포스를 통해 P * Q가 M 이내인 값들을 구하면 O(MlogM)의 시간 내에
모든 값들을 구할 수 있고, 소수들만 보는데다 A / B 이상으로 값이 나오는 수들도 제외되기 때문에
실제로는 매우 빠르게 답을 구할 수 있다.

주요 알고리즘 : 수학, 에라토스테네스, 브루트 포스

출처 : Kanazawa 2002 A번
*/

char sieve[103000];
int prime[16384];
int pp = 0;

int main(void) {
    int m, a, b, ba, bb;
    long long best;
    for (int i = 2; i <= 100000; i++) {
        if (sieve[i]) continue;
        prime[pp++] = i;
        for (int j = i * 2; j <= 100000; j += i) sieve[j] = 1;
    }
    while (1) {
        scanf("%d %d %d", &m, &a, &b);
        if (m == 0) break;

        best = 0, ba = -1, bb = -1;
        for (int i = 0; i < pp; i++) {
            if (prime[i] > m) break;
            for (int j = i; j < pp; j++) {
                if ((long long)prime[i] * prime[j] > m || prime[i] * b < prime[j] * a) break;
                if ((long long)prime[i] * prime[j] > best) {
                    best = (long long)prime[i] * prime[j];
                    ba = prime[i], bb = prime[j];
                }
            }
        }
        if (ba < 0) return 1;
        printf("%d %d\n", ba, bb);
    }
    return 0;
}