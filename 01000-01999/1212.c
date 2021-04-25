#include <stdio.h>

/*
문제 : N(N <= 350000)자 이하의 8진수가 나올 때, 2진수로 변환하여 출력한다.

해결 방법 : 맨 앞 글자를 먼저 확인해서 0을 제외하고 출력한 다음, 이후 글자는 3자씩 그대로 이진수로 바꾼다.

주요 알고리즘 : 비트마스킹, 구현
*/

char s[409600];

int main(void) {
	scanf("%s", s);
	if (s[0] & 4) {
		printf("1");
		for(int j = 1; j >= 0; j--) printf("%c", s[0] & (1 << j) ? '1' : '0');
	}
	else {
		if(s[0] & 2) {
			printf("1");
			if(s[0] & 1) printf("1");
			else printf("0");
		}
		else if(s[0] & 1) printf("1");
		else printf("0");
	}
	for(int i = 1; s[i]; i++) {
		s[i] -= '0';
		for(int j = 2; j >= 0; j--) printf("%c", s[i] & (1 << j) ? '1' : '0');
	}
	return 0;
}
