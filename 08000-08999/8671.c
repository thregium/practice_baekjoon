#include <stdio.h>
#define INF 1012345678

/*
���� : N(N <= 10^6)���� �ڿ����� �̷���� �������� ���ӵ� 1�� �̻��� �κ� ���ڿ� ��� ���� ����� ���� ���� ����� ���Ѵ�.

�ذ� ��� : �ּڰ����� ����� �۾��� ���� �����Ƿ� ���� �ּڰ��� ����.

�ֿ� �˰��� : �׸��� �˰���, ����

��ó : ILOCAMP 2011B 4-1��
*/

int main(void) {
    int n, a, best = INF;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        if (a < best) best = a;
    }
    printf("%d.00", best);
    return 0;
}
