#include <stdio.h>
#include <string.h>

/*
문제 : N개의(N <= 20000) 단어들이 주어지면 단어들의 길이순, 길이가 같다면 사전순으로 정렬해 출력한다.

해결 방법 : 문제에서 설명한대로 정렬한다.

주요 알고리즘 : 정렬
*/

int main() {
	int n, l, h, j, z = 1;
	char s[25000][64], t[25000][64];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%s", s[i]);
	while (z < n) {
		for (int i = 0; i < n; i += 2 * z) {
			l = i;
			h = i + z;
			j = 0;
			if (h >= n) h = n - 1;
			while (l < i + z || (h < i + 2 * z && h < n)) {
				if (h < n && (strcmp(s[l], s[h]) > 0 && h < i + 2 * z || l >= i + z || l >= h)) {
					strcpy(t[i + j], s[h]);
					h++;
				}
				else {
					strcpy(t[i + j], s[l]);
					l++;
				}
				j++;
			}
		}
		for (int i = 0; i < n; i++) strcpy(s[i], t[i]);
		z *= 2;
	}
	z = 1;
	while (z < n) {
		for (int i = 0; i < n; i += 2 * z) {
			l = i;
			h = i + z;
			j = 0;
			if (h >= n) h = n - 1;
			while (l < i + z || (h < i + 2 * z && h < n)) {
				if (h < n && (strlen(s[l]) > strlen(s[h]) && h < i + 2 * z || l >= i + z || l >= h)) {
					strcpy(t[i + j], s[h]);
					h++;
				}
				else {
					strcpy(t[i + j], s[l]);
					l++;
				}
				j++;
			}
		}
		for (int i = 0; i < n; i++) strcpy(s[i], t[i]);
		z *= 2;
	}
	for (int i = 0; i < n; i++) {
		if (n == 0) printf("%s\n", s[i]);
		else if (strcmp(s[i], s[i - 1]) != 0) printf("%s\n", s[i]);
	}
	return 0;
}