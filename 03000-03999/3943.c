#include <stdio.h>

/*
���� : N(N <= 100000)���� �����ϴ� ���Ͻ��� �������� 1�� ������ ������ ���� ū ���� ���Ѵ�.

�ذ� ��� : ���Ͻ��� ������ ������ ���� ū ���� ã���� �ȴ�.

�ֿ� �˰��� : ����, �ùķ��̼�

��ó : GNY 2012 A��
*/

int main(void) {
    int t, n, r;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &n);
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