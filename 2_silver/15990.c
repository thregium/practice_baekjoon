#include <stdio.h>
#define DIV 1000000007

int mem[102400][3];

int big(int a, int b) {
	return a > b ? a : b;
}

int main(void) {
	int t, n, r = 0, f = 1;
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++) {
		scanf("%d", &n);
		if (f == 1) {
			mem[1][0] = 1;
			mem[1][1] = 0;
			mem[1][2] = 0;
			mem[2][0] = 0;
			mem[2][1] = 1;
			mem[2][2] = 0;
			mem[3][0] = 1;
			mem[3][1] = 1;
			mem[3][2] = 1;
			f = 4;
		}
		for (int i = big(f, 4); i <= n; i++) {
			mem[i][0] = (mem[i - 1][1] + mem[i - 1][2]) % DIV;
			mem[i][1] = (mem[i - 2][0] + mem[i - 2][2]) % DIV;
			mem[i][2] = (mem[i - 3][0] + mem[i - 3][1]) % DIV;
		}
		f = n;
		r = ((mem[n][0] + mem[n][1]) % DIV + mem[n][2]) % DIV;
		printf("%d\n", r);
	}
	return 0;
}
