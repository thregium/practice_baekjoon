#include <stdio.h>

/*
���� : N(N <= 100)�� ���׽��� �־��� ��, �� ���׽��� �̺��� ����� ���Ѵ�.

�ذ� ��� : ���׽��� ������ N - 1�� �ǰ�, �� ���� ����� �� ������ ��� * (�� ����)�̴�.

�ֿ� �˰��� : ����, ��������

��ó : UVa 2012 D��
*/

int main(void) {
    int t, n, x, l;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        scanf("%d", &n);
        printf("Case %d: %d ", tt, n - 1);
        l = 0;
        for (int i = n; i >= 0; i--) {
            scanf("%d", &x);
            if (i < n) printf("%d ", (i + 1) * l);
            l = x;
        }
        printf("\n");
    }
    return 0;
}