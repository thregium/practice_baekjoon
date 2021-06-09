#include <stdio.h>
#include <string.h>

/*
문제 : 100자 이하의 1로 시작하는 2진수 문자가 주어진다. 이를 8진수로 바꾸어 출력한다.

해결 방법 : 각 자리 수를 뒤에서부터 3자리씩 끊어 처리한다.

주요 알고리즘 : 문자열

출처 : COCI 07/08#3 2번
*/

char s[128];

int main(void) {
	scanf("%s", s);
	int l = strlen(s);
	if (l % 3 == 2) printf("%d", (s[0] - '0') * 2 + s[1] - '0');
	if (l % 3 == 1) printf("%d", s[0] - '0');
	for (int i = l % 3; i < l; i += 3) {
		printf("%d", (s[i + 0] - '0') * 4 + (s[i + 1] - '0') * 2 + s[i + 2] - '0');
	}
	return 0;
}