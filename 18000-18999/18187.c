#include <stdio.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
문제 : N(N <= 1000) 길이의 두 글자로 이루어진 두 문자열이 주어질 때, 위 문자열을 아래 문자열과 똑같이 만들기 위해 필요한 구간 뒤집기 연산의 최소 횟수를 구한다.

해결 방법 : 먼저, 아래의 문자열에서 특정한 문자가 왔을 때 위의 문자열을 뒤집는다.
특정한 구간의 문자열을 뒤집을 때, 모든 문자가 동일하게 이루어진 연속된 구간을 부분이라고 한다면 한 부분을 뒤집는 동안 2 부분을 줄일 수 있다.
따라서, 부분의 수를 같게 만들기 위해서는 최소한 (부분의 수) / 2번의 뒤집기 연산이 필요하다.

주요 알고리즘 : 그리디 알고리즘, 문자열

출처 : USACO 2020F B2번
*/

char s[1024], s2[1024];

int main(void) {
	FILE* fi = stdin;
	FILE* fo = stdout;
	if (FOUT) {
		fi = fopen("breedflip.in", "r");
		fo = fopen("breedflip.out", "w");
	}
	int n, r = 0;
	scanf("%d", &n);
	scanf("%s%s", s, s2);
	for (int i = 0; i < n; i++) {
		if (s2[i] == 'H') {
			if (s[i] == 'G') s[i] = 'H';
			else s[i] = 'G';
		}
	}
	for (int i = 1; i < n; i++) {
		if (s[i] != s[i - 1]) r++;
	}
	printf("%d", (r + 1) >> 1);
	return 0;
}