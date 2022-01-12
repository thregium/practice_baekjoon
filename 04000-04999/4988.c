#include <stdio.h>
#include <ctype.h>

/*
���� : 1000�� 'm', 100�� 'c', 10�� 'x', 1�� 'i'�� ��Ÿ����, 2 �̻� 9 ������ ����� �տ� ���� �������
������� �� ǥ���(mcxi ǥ���)���� ������ ���ڿ��� �־�����, �� ���� mcxi ǥ������� ��Ÿ���� ����Ѵ�.

�ذ� ��� : �־��� �� ���ڿ��� ���� �ٲ� ����, ���� ���Ѵ�. �̸� �ٽ� mcxi ǥ������� �ٲپ� ����ϸ� �ȴ�.
���ڿ��� ���� �ٲ� ������ m, c, x, i�� �� �� �� �� ���ڰ� ������ �� Ȯ���ϰ� ���ڸ� �׸�ŭ ����ؼ� ���ϸ� �ȴ�.
��½ÿ��� �� �ڸ��� 2 �̻����� Ȯ���ϸ� �ڸ����� ���ڸ� ����Ѵ�.

�ֿ� �˰��� : ���ڿ�, �Ľ�

��ó : JDC 2005 C��
*/

char s1[16], s2[16], res[16];

int chartonum(char c) {
    if (c == 'm') return 1000;
    if (c == 'c') return 100;
    if (c == 'x') return 10;
    if (c == 'i') return 1;
    return 0;
}

int mcxitonum(char* s) {
    int r = 0;
    for (int i = 0; s[i]; i++) {
        if (s[i] == 'm' || s[i] == 'c' || s[i] == 'x' || s[i] == 'i') {
            if (i == 0 || !isdigit(s[i - 1])) r += chartonum(s[i]);
            else r += chartonum(s[i]) * (s[i - 1] - '0');
        }
    }
    return r;
}

void printmcxi(int n) {
    if (n / 1000) {
        if (n / 1000 > 1) printf("%d", n / 1000);
        printf("m");
    }
    if (n / 100 % 10) {
        if (n / 100 % 10 > 1) printf("%d", n / 100 % 10);
        printf("c");
    }
    if (n / 10 % 10) {
        if (n / 10 % 10 > 1) printf("%d", n / 10 % 10);
        printf("x");
    }
    if (n % 10) {
        if (n % 10 > 1) printf("%d", n % 10);
        printf("i");
    }
    printf("\n");
}

int main(void) {
    int t, r;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%s %s", s1, s2);
        r = mcxitonum(s1) + mcxitonum(s2);
        printmcxi(r);
    }
    return 0;
}