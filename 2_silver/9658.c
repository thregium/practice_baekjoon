#include <stdio.h>

char mem[1024];

int main(void) {
	int n;
	scanf("%d", &n);
	mem[0] = 1;
	mem[1] = 0;
	mem[2] = 1;
	mem[3] = 0;
	mem[4] = 1;
	for (int i = 5; i <= n; i++) {
		mem[i] = !(mem[i - 1] && mem[i - 3] && mem[i - 4]);
	}
	if (mem[n]) printf("SK");
	else printf("CY");
	return 0;
}
