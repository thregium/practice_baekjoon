#include <stdio.h>

/*
���� : N(N <= 500)���� �����ϴ� ���Ͻ��� �������� 1�� ������ ������ ���� ū ���� ���Ѵ�.

�ذ� ��� : ���Ͻ��� ������ ������ ���� ū ���� ã���� �ȴ�.

�ֿ� �˰��� : ����, �ùķ��̼�

��ó : Latin 2011 PB��
*/

int main(void) {
    int t, n, r;
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        r = n;
        while (n > 1) {
            if (n > r) r = n;
            if (n & 1) n = n * 3 + 1;
            else n >>= 1;
        }
        printf("%d\n", r);
    }
    return 0;
}