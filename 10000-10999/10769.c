#include <stdio.h>

/*
���� : 255�� ������ ���ڿ����� ":-)"�� ":-(" �� ��� ���� �� ������ ���Ѵ�.

�ذ� ��� : ���ڿ��� ������ Ȯ���ϸ� �� �κ� ���ڿ��� ������ �� ���� ���� ������ ���ϸ� �ȴ�.

�ֿ� �˰��� : ���ڿ�, ����

��ó : CCC 2015 J2��
*/

char buff[320];

int main(void) {
    int h = 0, s = 0;
    fgets(buff, 300, stdin);
    for (int i = 0; buff[i]; i++) {
        if (buff[i] == ':' && buff[i + 1] == '-') {
            if (buff[i + 2] == ')') h++;
            else if (buff[i + 2] == '(') s++;
        }
    }
    if (h == 0 && s == 0) printf("none");
    else if (h > s) printf("happy");
    else if (h == s) printf("unsure");
    else printf("sad");
    return 0;
}