#include <stdio.h>
#include <string.h>

/*
���� : ���ڿ��� �־��� ��, �� ���ڿ��� �Ӹ�������� Ȯ���Ѵ�.

�ذ� ��� : ó�� ���ں��� ������ ���ڱ��� ���� �ݴ� ��ġ�� �ִ� ���ڿ� ���� �ٸ��ٸ� �Ӹ������ �ƴϰ� ���ٸ� �Ӹ�����̴�.

�ֿ� �˰��� : ���ڿ�, ����

��ó : AIPO 2016P 2��
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