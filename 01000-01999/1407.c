#include <stdio.h>

/*
문제 : [A, B](A, B <= 10^15)에서 각 자연수의 LSB의 합을 구한다.

해결 방법 : 큰 비트부터 A와 B의 몫 차이를 구하면서 그 비트의 합을 더해나가면 된다. 단, 이미 쓴 비트의 합은 빼야 한다.

주요 알고리즘 : 수학

출처 : CHCI 2005O 1번
*/

int main(void) {
	long long a, b, t, r = 0, s = 0;
	scanf("%lld %lld", &a, &b);
	a--;

	for (long long i = 50; i >= 0; i--) { 
		t = b / (1LL << i) - a / (1LL << i);
		t -= s;
		s += t;
		r += t * (1LL << i);
	}

	printf("%lld", r);
}