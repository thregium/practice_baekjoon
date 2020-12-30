#include <stdio.h>

long long int p[100000];
long long int m[1000001];

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