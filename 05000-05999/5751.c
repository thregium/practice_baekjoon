#include <stdio.h>

/*
���� : N(N <= 10000)���� �� ��� 0�� 1�� ���� Ƚ���� ���� ���Ѵ�.

�ذ� ��� : ���� ������ �ȴ�.

�ֿ� �˰��� : ����

��ó : Latin 2005 PA��
*/

int main(void) {
    int n, r, m, j;
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        m = 0, j = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &r);
            if (r) j++;
            else m++;
        }
        printf("Mary won %d times and John won %d times\n", m, j);
    }
    return 0;
}