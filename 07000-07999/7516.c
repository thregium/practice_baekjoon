#include <stdio.h>

/*
문제 : N(N <= 10^9)이 주어질 때, 두 단위 분수를 합쳐서 1/N이 되도록 하는 분수의 개수를 구한다.

해결 방법 : N을 소인수분해 한 다음, 각 소인수의 개수 * 2 + 1을 각각 해서 결과에 곱한 다음
N으로 나누어 주면 된다. 이렇게 되는 이유는 이러한 경우를 식으로 정리하면 pq = N^2로,
해의 개수는 N^2의 약수 개수와 같아지기 때문이다.

주요 알고리즘 : 수학, 정수론, 소인수분해

출처 : TUD 2006 1번
*/

int main(void) {
	int t, n, tmp, pcnt;
	long long res = 1;
	scanf("%d", &t);
	for (int tt = 1; tt <= t; tt++) {
		scanf("%d", &n);
		res = 1;
		tmp = n;
		for (int j = 2; j * j <= tmp; j++) {
			pcnt = 0;
			while (tmp % j == 0) {
				tmp /= j;
				pcnt++;
			}
			res *= pcnt * 2LL + 1;
		}
		if (tmp > 1) res *= 3;
		res = res / 2 + 1;
		printf("Scenario #%d:\n%lld\n\n", tt, res);
	}
	return 0;
}