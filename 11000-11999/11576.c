#include <stdio.h>

int main(void) {
	int a, b, m, t, x, c = 0, d = 0;
	scanf("%d %d", &a, &b);
	scanf("%d", &m);
	for (int i = m - 1; i >= 0; i--) {
		t = 1;
		for (int j = 0; j < i; j++) t *= a;
		scanf("%d", &x);
		d += t * x;
	}
	t = 1;
	while (t * b <= d) {
		t *= b;
		c++;
	}
	for (int i = c; i >= 0; i--) {
		t = 1;
		for (int j = 0; j < i; j++) t *= b;
		printf("%d ", d / t);
		d %= t;
	}
	return 0;
}
