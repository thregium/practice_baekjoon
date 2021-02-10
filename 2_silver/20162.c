#include <stdio.h>

int a[1024], mem[1024];

int main(void) {
	int n, h;
	scanf("%d", &n);
	scanf("%d", &a[0]);
	mem[0] = a[0];
	for (int i = 1; i < n; i++) {
		scanf("%d", &a[i]);
		h = a[i];
		for (int j = i; j >= 0; j--) {
			if (a[i] > a[j] && mem[j] + a[i] > h) {
				h = mem[j] + a[i];
			}
		}
		mem[i] = h;
	}
	h = -65536;
	for (int i = 0; i < n; i++) {
		if (mem[i] > h) h = mem[i];
	}
	printf("%d", h);
	return 0;
}
