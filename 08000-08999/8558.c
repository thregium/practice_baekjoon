#include <stdio.h>

/*
���� : N!(N <= 10000)�� ���� �ڸ� ���� ���Ѵ�.

�ذ� ��� : 1���� N������ ���� �Ź� 10���� ������� Ǯ�� �ȴ�.

�ֿ� �˰����� : ����, ��Ģ����

��ó : PA 2001 0-1��
*/

int main(void) {
    int n, r = 1;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        r *= i;
        r %= 10;
    }
    printf("%d", r);
    return 0;
}