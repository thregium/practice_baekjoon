#include <stdio.h>
#include <string.h>

/*
���� : �־����� ���� ����(<120��)�� �������� �־����� ���ǿ� �°� �����Ͽ� ����Ѵ�.

�ذ� ��� : ������ �Ľ��Ѵ�. �ڼ��� ������ �߰� ����

�ֿ� �˰��� : ���ڿ�, �Ľ�

��ó : NEERC 2008 I��
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