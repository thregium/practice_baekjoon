#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
���� : �� ����� �̸��� �ִ� B�� G�� ������ ���ؼ� �� ���� ���� ã�´�. ��ҹ��ڸ� �������� �ʾƾ� �Ѵ�. �̸��� �ִ� 25���̴�.

�ذ� ��� : �̸��� ��� ���ڿ� ���� �ҹ��ڷ� �ٲپ� b�� g�� ������ ���� �� ���� ���� ������ ���ϸ� �ȴ�.

�ֿ� �˰��� : ����, ���ڿ�

��ó : PacNW 2011 A��
*/

char s[64];

int main(void) {
    int n, b, g;
    scanf("%d\n", &n);
    for (int i = 0; i < n; i++) {
        fgets(s, 60, stdin);
        b = 0, g = 0;
        if (s[strlen(s) - 1] == '\n') s[strlen(s) - 1] = '\0';
        for (int i = 0; s[i]; i++) {
            if (tolower(s[i]) == 'b') b++;
            else if (tolower(s[i]) == 'g') g++;
        }
        if (b > g) printf("%s is A BADDY\n", s);
        else if (b < g) printf("%s is GOOD\n", s);
        else printf("%s is NEUTRAL\n", s);
    }
    return 0;
}