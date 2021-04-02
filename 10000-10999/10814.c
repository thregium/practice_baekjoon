#include <stdio.h>
#include <string.h>

char s[120000][120], t[120000][120];
int u[120000], v[120000];

int main() {
	int n, l, h, j, z = 1;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d %s", &u[i], &s[i]);
	while (z < n) {
		for (int i = 0; i < n; i += 2 * z) {
			l = i;
			h = i + z;
			j = 0;
			if (h >= n) h = n - 1;
			while (l < i + z || (h < i + 2 * z && h < n)) {
				if (h < n && (u[l] > u[h] && h < i + 2 * z || l >= i + z || l >= h)) {
					v[i + j] = u[h];
					strcpy(t[i + j], s[h]);
					h++;
				}
				else {
					v[i + j] = u[l];
					strcpy(t[i + j], s[l]);
					l++;
				}
				j++;
			}
		}
		for (int i = 0; i < n; i++) {
			u[i] = v[i];
			strcpy(s[i], t[i]);
		}
		z *= 2;
	}

	for (int i = 0; i < n; i++) printf("%d %s\n", u[i], s[i]);
	return 0;
}