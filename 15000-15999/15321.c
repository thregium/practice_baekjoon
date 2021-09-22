#include <stdio.h>
#include <math.h>
#define INF 987654321

int a[512], mem[512][512], to[512][512];

int big(int a, int b) {
	return a > b ? a : b;
}

int small(int a, int b) {
	return a < b ? a : b;
}

int main(void) {
	int n, b;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) mem[i][j] = INF;
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		mem[i][i] = 0;
	}
	for (int i = 0; i < n; i++) {
		b = 0;
		for (int j = i; j < n; j++) {
			b = big(a[j], b);
			to[i][j] = b;
		}
	}
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < n - i; j++) {
			for (int k = 0; k < i; k++) {
				mem[j][i + j] = small(mem[j][i + j], mem[j][j + k] + mem[j + k + 1][j + i] + abs(to[j][j + k] - to[j + k + 1][j + i]));
			}
		}
	}
	printf("%d", mem[0][n - 1]);
	return 0;
}
