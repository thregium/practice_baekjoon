#include <stdio.h>
#include <stdlib.h>

/*
문제 : 자연수 N(N <= 10^8)의 배수 가운데 자릿수의 합이 홀수인 것을 구한다. 이를 T(T <= 1000)번 해야 한다.
단, 답은 10^18 이내가 되어야 한다.

해결 방법 : 곱하는 값이 작은 경우에는 N의 배수 가운데 자릿수의 합이 홀수인 것을 찾는 데 오래 걸리는 경우가 생긴다.
(예: 99999999, 10000001 등) 하지만, 값이 커진다면 자릿수의 합이 홀수와 짝수일 확률이 거의 1:1이 되기 때문에
무작위로 매우 큰 값들을 곱하며 자릿수의 합이 홀수인 것을 찾더라도 빠른 시간 내에 답을 찾을 수 있다.

주요 알고리즘 : 수학, 무작위화

출처 : 고려대 2018B H번 / 2018I F번
*/

int main(void) {
	int t;
	long long n, mul, val, cnt;
	scanf("%d", &t);
	for (int tt = 1; tt <= t; tt++) {
		scanf("%lld", &n);
		while (1) {
			mul = (((long long)rand() << 16) + rand()) & ((1LL << 31) - 1);
			val = mul * n;
			cnt = 0;
			for (long long i = val; i; i /= 10) cnt += i % 10;
			if (cnt & 1) {
				printf("%lld\n", val);
				break;
			}
		}

	}
}