#include <stdio.h>
#include <ctype.h>

/*
���� : �־��� ���� 250 ������ ���ڿ��� ���ĺ��� �� ���� �ִ��� ���Ѵ�. ��ҹ��ڴ� �������� �ʴ´�.

�ذ� ��� : ���ڿ��� Ȯ���ϸ� ���� ���ĺ��� �ִ� ��� �� ���ĺ��� ���� ����. ��ҹ��ڸ� ���� �� �� �ֵ��� ��츦 ������.
�� ���� ��� ���ĺ��� ���� 1ȸ �̻� ���� ���ĺ��� ���� ���� �ȴ�.

�ֿ� �˰��� : ���ڿ�

��ó : NZPC 2008 F��
*/

char s[512];
int cnt[26];

int main(void) {
    int r;
    while (1) {
        fgets(s, 256, stdin);
        if (s[0] == '#') break;
        r = 0;
        for (int i = 0; s[i]; i++) {
            if (isupper(s[i])) cnt[s[i] - 'A']++;
            if (islower(s[i])) cnt[s[i] - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (cnt[i]) r++;
            cnt[i] = 0;
        }
        printf("%d\n", r);
    }
    return 0;
}