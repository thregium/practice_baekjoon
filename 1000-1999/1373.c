#include <stdio.h>
#include <string.h>

/*
문제 : 10^6 이하 자리의 이진수가 나올 때, 8진수로 바꾸어 출력한다.

해결 방법 : 3 자리씩 끊어서 8진수로 바꾸어 출력한다.
단, 맨 앞 자리의 길이는 전체 길이를 보고 미리 확인한 후, 2번째 자리의 위치까지 잡아놓아야 한다.

주요 알고리즘 : 수학, 구현
*/

char s[1048576];

int main(void) {
	scanf("%s", s);
	int l = strlen(s);
	if(l % 3 == 2) printf("%d", (s[0] - '0') * 2 + s[1] - '0');
	if(l % 3 == 1) printf("%d", s[0] - '0');
	for(int i = l % 3; i < l; i += 3) {
		printf("%d", (s[i + 0] - '0') * 4 + (s[i + 1] - '0') * 2 + s[i + 2] - '0');
	}
	return 0;
}
