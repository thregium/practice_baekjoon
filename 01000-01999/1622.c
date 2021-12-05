#include <stdio.h>
#include <string.h>

/*
���� : ���� 1000 ������ �� ���ڿ��� �־��� ��, �� ���ڿ� ���� ������ ���� �� �κ� ���ڿ� ���
���������� ���� ���� ���� ���Ѵ�. ��, �� ���ڿ��� �� ���ڿ��� �� �ִ�.

�ذ� ��� : ���ڿ����� �Է¹��� �� ������ ����, �� �� �� ���� ���� �������� ���������� ����ϸ� �ȴ�.
�� ���ڿ��� �� �����Ƿ� fgets() �Լ��� �̿��ؾ� �Ѵ�.

�ֿ� �˰��� : ����, ���ڿ�

��ó : Alberta 1999 F��
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