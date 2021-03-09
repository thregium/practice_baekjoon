#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char s[64], ns[2560][64];
int nsp = 0;

int main(void) {
	scanf("%s", s);
	int l = strlen(l);
	for (int i = 1; i < l; i++) {
		for (int j = 1; j < l; j++) {
			if (i + j + 1 > l) continue;
			for (int k = 0; k < i; k++) {
				ns[nsp][k] = s[i - k - 1];
			}
			for (int k = i; k < i + j; k++) {
				ns[nsp][k] = s[i * 2 + j - k - 1];
			}
			for (int k = i + j; k < l; k++) {
				ns[nsp][k] = s[i + j + l - k - 1];
			}
			nsp++;
		}
	}
	qsort(ns, nsp, sizeof(char) * 64, strcmp);
	printf("%s", ns[0]);
	return 0;
}
