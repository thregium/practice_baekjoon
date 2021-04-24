#include <stdio.h>
#include <string.h>

/*
문제 : 문자열이 주어질 때, 이 문자열이 팰린드롬인지 확인한다.

해결 방법 : 처음 글자부터 마지막 글자까지 서로 반대 위치에 있는 글자와 비교해 다르다면 팰린드롬이 아니고 같다면 팰린드롬이다.

주요 알고리즘 : 문자열, 구현

출처 : AIPO 2016P 2번
*/

char s[128];

int main(void) {
	scanf("%s", s);
	int l = strlen(s);
	for (int i = 0; i < l; i++) {
		if (s[i] != s[l - i - 1]) {
			printf("false");
			return 0;
		}
	}
	printf("true");
	return 0;
}