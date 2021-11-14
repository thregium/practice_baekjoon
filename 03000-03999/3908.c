#include <stdio.h>

/*
문제 : N(N <= 1120)과 K(K <= 14)가 주어질 때, N을 서로 다른 K(K <= 14)개의 소수의 합으로 만드는 방법의 수를 구한다.

해결 방법 : 각 소수마다 DP를 해 나가면 된다.

주요 알고리즘 : DP, 수학, 소수 판정

출처 : Yokohama 2006 D번
*/

int sieve[1280], mem[1280][16];

int main(void) {
    int t, n, k;
    mem[0][0] = 1;
	for (int i = 2; i <= 1120; i++) {
		for (int j = i * 2; j <= 1120; j += i) sieve[j] = 1;
		if (!sieve[i]) {
			for (int j = 1120; j >= i; j--) {
				for (int k = 1; k <= 14; k++) {
					mem[j][k] += mem[j - i][k - 1];
				}
			}
		}
	}

    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d %d", &n, &k);
		printf("%d\n", mem[n][k]);
    }
    return 0;
}