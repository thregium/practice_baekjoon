#include <stdio.h>

/*
���� : �־��� 20�� ������ �ҹ��ڷ� �̷���� �ܾ �Ǳ׶�ƾ��� �ٲ� ����� ����Ѵ�.
�Ǳ׶�ƾ��� ù ���� ������ ���ڵ��� �� ��, �� ���� ���ڵ��� ����, ay�� ���̴� ������� �����.

�ذ� ��� : ������ �־������ �����Ѵ�.

�ֿ� �˰��� : ���ڿ�, ����

��ó : NZPC 2002 A��
*/

char s[32], back[32];

int isvowel(char c) {
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return 1;
    return 0;
}

int main(void) {
    int p, r;
    while (1) {
        scanf("%s", s);
        if (s[0] == '#') break;
        p = 0, r = 0;
        for (int i = 0; s[i]; i++) {
            if (isvowel(s[i])) r++;
            if (r) printf("%c", s[i]);
            else back[p++] = s[i];
        }
        back[p] = '\0';
        printf("%say\n", back);
    }
    return 0;
}