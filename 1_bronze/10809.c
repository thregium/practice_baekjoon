#include <stdio.h>
#include <string.h>

int main() {
	int a[26];
	for (int i = 0; i < 26; i++) a[i] = -1;
	char c[256];
	scanf("%s", c);
	for (int i = 0; i < strlen(c); i++) {
		printf("c[i] - a = %d\n", c[i] - 'a');
		if (a[(c[i] - 'a')] < 0) {
			a[(c[i] - 'a')] = i;
			printf("a[%d] = %d\n", c[i] - 'a', i);
		}
	}
	for (int i = 0; i < 26; i++) printf("%d ", a[i]);
	return 0;
}