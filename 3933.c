#include <stdio.h>

int squares[192], lgrj[32768];

int main(void) {
	int n, r = 0;
	for (int i = 1; i < 192; i++) {
		squares[i] = i * i;
	}
	
	for (int i = 1; i * i <= 32768; i++) {
		lgrj[i * i]++;
		for (int j = i; (i * i) + (j * j) <= 32768; j++) {
			lgrj[(i * i) + (j * j)]++;
			for (int k = j; (i * i) + (j * j) + (k * k) <= 32768; k++) {
				lgrj[(i * i) + (j * j) + (k * k)]++;
				for (int l = k; (i * i) + (j * j) + (k * k) + (l * l) <= 32768; l++) {
					lgrj[(i * i) + (j * j) + (k * k) + (l * l)]++;
				}
			}
		}
	}

	while (1) {
		scanf("%d", &n);
		if (n == 0) break;
		//r = mem[1][n] + mem[2][n] + mem[3][n] + mem[4][n];
		printf("%d\n", lgrj[n]);
	}
	return 0;
}
