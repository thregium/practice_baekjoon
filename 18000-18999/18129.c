#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
���� : ���� 2000 ������ ��ҹ��ڷ� �̷���� ���ڿ��� �־�����. �� ���ڿ��� ��ҹ��ڸ� ������� �ʰ�
���� ���ĺ����� �̷���� �׷����� ���� �� �տ������� �� ���ĺ��� ó�� ������ �׷��� ũ�Ⱑ
K �̻��� ��� 1, �̸��� ��� 0���� ��Ÿ�� ���ڿ��� ����Ѵ�.

�ذ� ��� : ������ �־������ �����Ѵ�. tolower()�Լ��� �湮 �迭�� ����ϴ� ���� ����.

�ֿ� �˰��� : ����, ���ڿ�

��ó : ���縯�� 1ȸ 6��
*/

char s[2048], chk[26];

int main(void) {
    int k, len, last = 0;
    scanf("%s %d", s, &k);
    len = strlen(s);
    for (int i = 0; i < len; i++) {
        s[i] = tolower(s[i]);
    }
    for (int i = 1; i < len; i++) {
        if (s[i] != s[i - 1]) {
            if (!chk[s[i - 1] - 'a']) {
                printf("%d", i - last >= k);
                chk[s[i - 1] - 'a'] = 1;
            }
            last = i;
        }
    }
    if (!chk[s[len - 1] - 'a']) {
        printf("%d", len - last >= k);
    }
    return 0;
}