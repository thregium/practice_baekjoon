#include <stdio.h>
#include <string.h>

/*
문제 : 주어지는 변수 선언문(<120자)을 문제에서 주어지는 조건에 맞게 변형하여 출력한다.

해결 방법 : 적절히 파싱한다. 자세한 내용은 추가 예정

주요 알고리즘 : 문자열, 파싱

출처 : NEERC 2008 I번
*/

char s[128], buff[128];
const char* delim = " ,;\0";

int main(void) {
	int cnt;
	char* c, *d;

	fgets(s, 125, stdin);
	if (s[strlen(s) - 1] == '\n') s[strlen(s) - 1] = '\0';

	c = strtok(s, delim);
	d = strtok(NULL, delim);
	while (d != NULL) {
		cnt = 0;
		for (int i = strlen(d) - 1; i >= 0; i--) {
			if (d[i] == '*' || d[i] == '&') {
				buff[cnt++] = d[i];
			}
			else if (d[i] == '[' || d[i] == ']') {
				buff[cnt++] = '[';
				buff[cnt++] = ']';
				i--;
			}
			else {
				buff[cnt] = '\0';
				d[i + 1] = '\0';
				break;
			}
		}
		printf("%s%s %s;\n", c, buff, d);
		d = strtok(NULL, delim);
	}
	return 0;
}