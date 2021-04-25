#include <stdio.h>

/*
문제 : min과 max 사이에서 2 * 2 이상의 제곱수로 나누어 떨어지지 않는 수의 갯수를 구한다. (min <= 10^9, max <= min + 1000000)

해결 방법 : 각 수가 제곱수로 나누어 떨어지기 위해서는 소수의 제곱수로 나누어 떨어져야 한다.
따라서, (max)^0.5 범위에서 미리 소수의 제곱수들을 저장해둔 다음, 에라토스테네스의 체를 응용해서 모든 소수 제곱에 대해
나누어 떨어지는지 여부를 확인하면 제곱수로 나누어 떨어지는지 여부를 알 수 있다. min에서 max의 범위가 비교적 작은 편이기에
배열에 모든 숫자를 저장해 놓고 확인이 끝난 다음 나누어 떨어지지 않는 수를 세면 된다.

주요 알고리즘 : 수학, 정수론, 에라토스테네스의 체
*/

long long int p[100000]; //소수의 제곱을 저장
long long int m[1000001]; //min과 max 사이의 각 숫자를 저장

int main() {
	int x, qp = 0, c = 0;
	long long int t;
	for (int i = 2; i < 1001000; i++) {
		x = 1;
		for (int j = 2; j * j <= i; j++) {
			if (i % j == 0) {
				x = 0;
				break;
			}
		}
		if (x) {
			p[qp] = (long long int)i * i;
			qp++;
		}
	}
	long long int min, max;
	scanf("%lld %lld", &min, &max);
	for (long long int i = 0; i <= max - min; i++) m[i] = i + min;
	for (int i = 0; i < qp; i++) {
		t = min / p[i] * p[i];
		while (t <= max) {
			if (t >= min) m[t - min] = 0;
			t += p[i];
			if(t <= max) m[t - min] = 0;
		}
	}
	for (long long int i = 0; i <= max - min; i++) {
		if (m[i]) {
			c++;
		}
	}
	printf("%d", c);
	return 0;
}