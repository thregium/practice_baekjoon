#include <stdio.h>
#include <string.h>

/*
문제 : 길이 10^6 이하의 P와 A로만 이루어진 문자열이 주어질 때, 이 문자열이 P에서 P를 PPAP로 바꾸는 연산을 반복하여
만들 수 있는 문자열인지 구한다.

해결 방법 : 스택을 이용해 문자를 하나씩 추가하다 최근 문자들이 "PPAP"가 되면 지우고 "P"로 바꾸는 것을 반복한다.
남은 문자열이 "P"인 경우 조건을 만족하고 그 외의 경우에는 조건을 만족하지 않는다.

주요 알고리즘 : 그리디 알고리즘, 스택

출처 : 서울대 2018D1 C / 2018D2 G번
*/

char s[1048576], t[1048576], x[64];
int p = 0;

int main(void) {
	scanf("%s", s);
	strcpy(x, "PPAP");
	int l = strlen(x);
	for (int i = 0; s[i]; i++) {
		t[p++] = s[i];
		while (p >= l && !strcmp(&t[p - l], x)) {
			p -= l;
			for (int j = 0; j < l; j++) t[p + j] = '\0';
			t[p++] = 'P';
		}
	}
	if (strcmp(t, "P")) printf("NP");
	else printf("PPAP");
	return 0;
}