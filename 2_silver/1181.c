#include <stdio.h>

int main() {
	int n, l, h, j, z = 1;
	char s[12000][20], t[12000][20];
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