#include <stdio.h>

/*
문제 : N(N <= 10000)일동안 필요한 초의 수를 P(P <= 10000)번 구한다.

해결 방법 : N에 1부터 N까지의 합(= N * (N + 1) / 2)을 더한 것과 같다. 이를 반복해서 구해주면 된다.

주요 알고리즘 : 수학

출처 : GNY 2017 A번
*/

int main(void) {
	int p, k, n;
	scanf("%d", &p);
	for (int pp = 0; pp < p; pp++) {
		scanf("%d %d", &k, &n);
		printf("%d %d\n", k, n + ((n * (n + 1)) >> 1));
	}
}
