#include <stdio.h>
#include <string.h>

/*
문제 : 길이 1000 이하의 두 문자열이 주어질 때, 두 문자열 사이 공통인 가장 긴 부분 문자열 가운데
사전순으로 가장 빠른 것을 구한다. 단, 두 문자열은 빈 문자열일 수 있다.

해결 방법 : 문자열들을 입력받은 후 개수를 세고, 둘 중 더 작은 것을 기준으로 사전순으로 출력하면 된다.
빈 문자열일 수 있으므로 fgets() 함수를 이용해야 한다.

주요 알고리즘 : 구현, 문자열

출처 : Alberta 1999 F번
*/

int cnt1[26], cnt2[26];
char s1[1024], s2[1024];

int small(int a, int b) {
	return a < b ? a : b;
}

int main(void) {
	int t;
	while (fgets(s1, 1013, stdin)) {
		fgets(s2, 1013, stdin);
		if (s1[strlen(s1) - 1] == '\n') s1[strlen(s1) - 1] = '\0';
		if (s2[strlen(s2) - 1] == '\n') s2[strlen(s2) - 1] = '\0';

		for (int i = 0; s1[i]; i++) cnt1[s1[i] - 'a']++;
		for (int i = 0; s2[i]; i++) cnt2[s2[i] - 'a']++;
		for (int i = 0; i < 26; i++) {
			t = small(cnt1[i], cnt2[i]);
			for (int j = 0; j < t; j++) {
				printf("%c", (char)(i + 'a'));
			}
		}
		printf("\n");
		for (int i = 0; i < 26; i++) {
			cnt1[i] = 0, cnt2[i] = 0;
		}
	}
	return 0;
}