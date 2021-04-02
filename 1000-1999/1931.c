#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int s[102400][2] = { 0, }, t[102400][2] = { 0, };

int main() {
	int tm = 0, ct = 0;
	int n, l, h, j, z = 1;
	scanf("%d", &n);
	srand(time(NULL));
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &s[i][0], &s[i][1]);
		/*
		s[i][0] = rand() * 65536 + rand();
		s[i][1] = rand() * 65536 + rand();
		srand(rand() + 39);
		*/
	}
	while (z <= n) {
		for (int i = 0; i < n; i += 2 * z) {
			l = i;
			h = i + z;
			j = 0;
			if (h >= n) h = n - 1;
			while (l < i + z || (h < i + 2 * z && h < n)) {
				if (h < n && (s[l][0] > s[h][0] && h < i + 2 * z || l >= i + z || l >= h)) {
					t[i + j][0] = s[h][0];
					t[i + j][1] = s[h][1];
					h++;
				}
				else {
					t[i + j][0] = s[l][0];
					t[i + j][1] = s[l][1];
					l++;
				}
				j++;
			}
		}
		for (int i = 0; i < n; i++) {
			s[i][0] = t[i][0];
			s[i][1] = t[i][1];
		}
		z *= 2;
	}
	z = 1;
	while (z <= n) {
		for (int i = 0; i < n; i += 2 * z) {
			l = i;
			h = i + z;
			j = 0;
			if (h >= n) h = n - 1;
			while (l < i + z || (h < i + 2 * z && h < n)) {
				if (h < n && (s[l][1] > s[h][1] && h < i + 2 * z || l >= i + z || l >= h)) {
					t[i + j][0] = s[h][0];
					t[i + j][1] = s[h][1];
					h++;
				}
				else {
					t[i + j][0] = s[l][0];
					t[i + j][1] = s[l][1];
					l++;
				}
				j++;
			}
		}
		for (int i = 0; i < n; i++) {
			s[i][0] = t[i][0];
			s[i][1] = t[i][1];
		}
		z *= 2;
	}

	for (int i = 0; i < n; i++) {
		if (s[i][0] >= tm) {
			tm = s[i][1];
			ct++;
		}
	}
	printf("%d", ct);
	return 0;
}