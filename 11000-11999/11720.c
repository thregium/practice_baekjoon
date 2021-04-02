#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int n, s = 0;
	char c[256];
	scanf("%d", &n);
	for (int i = 0; i <= n; i++) scanf("%c", &c[i]);
	for (int i = 1; i <= n; i++) s += c[i] - 48;
	printf("%d", s);
	return 0;
}