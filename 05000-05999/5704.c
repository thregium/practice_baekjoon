#include <stdio.h>
#include <ctype.h>

/*
���� : �־��� 200�� ������ ���ڿ�(�ҹ���, ����)�� �ұ׷�(��� ���ĺ��� ���)���� ���Ѵ�.

�ذ� ��� : ���ڿ����� �� ���ĺ��� ���� ���θ� üũ�Ѵ�. �� �� ��� ���ĺ��� �����Ͽ����� ���Ǹ� �ȴ�.

�ֿ� �˰��� : ���ڿ�, ����

��ó : Latin 2009 PA��
*/

char s[256], chk[26];

int main(void) {
    int r;
    while (1) {
        fgets(s, 240, stdin);
        if (s[0] == '*') break;
        for (int i = 0; s[i]; i++) {
            if (islower(s[i])) chk[s[i] - 'a'] = 1;
            else if (s[i] != ' ' && s[i] != '\n') return 1;
        }
        r = 1;
        for (int i = 0; i < 26; i++) {
            if (chk[i]) chk[i] = 0;
            else r = 0;
        }
        printf("%c\n", r ? 'Y' : 'N');
    }
    return 0;
}