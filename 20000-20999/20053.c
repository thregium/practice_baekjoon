#include <stdio.h>
#define INF 1012345678

/*
���� : N(N <= 10^6)���� �ڿ����� ��� �ּڰ��� �ִ��� ���� ���Ѵ�.

�ذ� ��� : �ּڰ��� �ִ��� ���� ���Ѵ�� -���Ѵ�� �ʱ�ȭ��Ų ��, ���� ���� �� ���� �ּڰ����� �۰ų� �ִ񰪺��� ũ�ٸ�
�� ������ ���Ž����ش�. �������� ������ ���� ���� ��ü�� �ּڰ��� �ִ��̴�.

�ֿ� �˰��� : ����
*/

int main(void) {
    int t, n, x, lo, hi;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &n);
        lo = INF;
        hi = -INF;
        for (int i = 0; i < n; i++) {
            scanf("%d", &x);
            if (x > hi) hi = x;
            if (x < lo) lo = x;
        }
        printf("%d %d\n", lo, hi);
    }
    return 0;
}