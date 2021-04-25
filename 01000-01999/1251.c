#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
문제 : 길이 N(N <= 50)의 문자열이 주어지면, 이 문자열을 3 부분으로 나눈 후 각 조각들을 뒤집고 다시 붙였을 때
사전순으로 가장 앞서는 것을 찾는다.

해결 방법 : N의 크기가 작으므로 모든 위치에서 3 부분으로 나눈 것을 저장해둔 다음
저장한 문자열을 사전순으로 정렬해 가장 앞선 것을 출력한다.

주요 알고리즘 : 문자열, 브루트 포스, 정렬
*/

char s[64], ns[2560][64];
int nsp = 0;

int main(void) {
	scanf("%s", s);
	int l = strlen(l);
	for (int i = 1; i < l; i++) {
		for (int j = 1; j < l; j++) {
			if (i + j + 1 > l) continue;
			for (int k = 0; k < i; k++) {
				ns[nsp][k] = s[i - k - 1]; //앞쪽
			}
			for (int k = i; k < i + j; k++) {
				ns[nsp][k] = s[i * 2 + j - k - 1]; //가운데
			}
			for (int k = i + j; k < l; k++) {
				ns[nsp][k] = s[i + j + l - k - 1]; //뒤쪽
			}
			nsp++;
		}
	}
	qsort(ns, nsp, sizeof(char) * 64, strcmp);
	printf("%s", ns[0]);
	return 0;
}
