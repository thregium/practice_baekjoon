#include <stdio.h>
#include <stdlib.h>

/*
���� : 7�� ������ A���� ���� B�������� ����Ѵ�. ��, 7�ڸ� �Ѵ� ��� ERROR�� ����Ѵ�.

�ذ� ��� : strtoll �Լ��� �̿��� ���������� �ٲ��� ����, �̸� �������� ���ذ��� ���� ã�Ƴ�����.
�̶� 7�ڸ� ���� ����߾ ���� 0�� �ƴ϶�� ERROR�� ����ؾ� �Ѵ�.

�ֿ� �˰��� : ����, ����, ���ڿ�

��ó : MidC 1995 5��
*/

char s[16], e[16];

int main(void) {
    int a, b, x;
    while (scanf("%s %d %d", s, &a, &b) != EOF) {
        x = strtoll(s, NULL, a);
        for (int i = 0; i < 7; i++) e[i] = ' ';
        for (int i = 6; i >= 0; i--) {
            if (x % b < 10) e[i] = x % b + '0';
            else e[i] = x % b - 10 + 'A';
            x /= b;
            if (x == 0) break;
        }
        if (x) printf("  ERROR\n");
        else printf("%s\n", e);
    }
    return 0;
}