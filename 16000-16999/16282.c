#include <stdio.h>
#include <math.h>

/*
문제 : N(N <= 10^18)개의 연결된 고리를 끊어서 1부터 N까지의 모든 개수를 갖는 집합을 만들기 위해 끊어야 할 최소 횟수를 구한다.

해결 방법 : 계산해보면 X개의 고리를 끊었을 때, (X + 1) * (X^(X + 1) - 1) + X개의 고리까지 만들 수 있다.
따라서, 이 값 이상이 될 때 까지 확인하면 된다.

주요 알고리즘 : 

출처 : Seoul 2018I A번
*/

int main(void) {
	long long n, r = 0;
	scanf("%lld", &n);
	while (1) {
		if ((powl(2, (r + 1)) - 1) * (r + 1) + r >= n) {
			break;
		}
		r++;
	}
	printf("%lld", r);
	return 0;
}