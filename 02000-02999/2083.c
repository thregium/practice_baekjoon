#include <stdio.h>

/*
���� : �� ȸ������ û�ҳ�ο� ���κη� ������. ���κη� ���� ������ ���̰� 17������ ���ų� �����԰� 80kg �̻��� ���̴�.

�ذ� ��� : ���̰� 17���� �Ѱų� �����԰� 80kg �̻����� Ȯ���ϸ� �ȴ�.

�ֿ� �˰��� : ����

��ó : NZPC 2005 B��
*/

char s[16];

int main(void) {
    int a, w;
    while (1) {
        scanf("%s %d %d", s, &a, &w);
        if (s[0] == '#') break;
        if (a > 17 || w >= 80) printf("%s Senior\n", s);
        else printf("%s Junior\n", s);
    }
    return 0;
}