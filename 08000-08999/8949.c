#include <stdio.h>

/*
���� : �־��� �� �ڿ��� A, B(A, B <= 10^6)�� �ڸ��� ������ ���� ���� ���Ѵ�.

�ذ� ��� : �� ���� �ڸ��� ������ ������ ����, ���� ���Ѵ�. �� ����, ���ڸ����� �ٽ� ����ϸ� �ȴ�.

�ֿ� �˰��� : ����, ����

��ó : CHCI 2007RS 1��
*/

int sa[8], sb[8], s[8];

int main(void) {
    int a, b, p = 7;
    scanf("%d %d", &a, &b);
    for (int i = 0; a; i++) {
        sa[i] = a % 10;
        a /= 10;
    }
    for (int i = 0; b; i++) {
        sb[i] = b % 10;
        b /= 10;
    }
    for (int i = 0; i < 8; i++) {
        s[i] = sa[i] + sb[i];
    }
    while (!s[p]) p--;
    while (p >= 0) {
        printf("%d", s[p]);
        p--;
    }
    return 0;
}