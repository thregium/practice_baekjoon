#include <stdio.h>
#include <ctype.h>

/*
���� : 250�� ������ ����� �ҹ��� �ϳ��� �־��� ��, �־��� ���ĺ��� ���忡 �� ȸ �������� ���Ѵ�.
�빮���� ��쿡�� ���� ���ĺ��� ��� ���� �Ѵ�.

�ذ� ��� : tolower�Լ��� ���� �� ���ڵ��� �ҹ��ڷ� ���� ����, �־��� ���ڿ� ������ Ȯ���ϰ� ���� ���� ���� ���� �ȴ�.

�ֿ� �˰��� : ����, ���ڿ�

��ó : NZPC 2004 W��
*/

char s[256];

int main(void) {
    int r;
    char c;
    while (1) {
        scanf(" %c", &c);
        if (c == '#') break;
        fgets(s, 253, stdin);
        r = 0;
        for (int i = 0; s[i]; i++) {
            if (tolower(s[i]) == c) r++;
        }
        printf("%c %d\n", c, r);
    }
    return 0;
}