#include <stdio.h>

/*
���� : C(C <= 2 * 10^6) ������ �ڿ��� �� N(N <= 100)���� �ڿ��� ��� �ϳ� �̻����� ������ �������� ���� ������ ���Ѵ�.

�ذ� ��� : ���� ���غ���.

�ֿ� �˰��� : ���Ʈ ����, ����

��ó : USACO 2007M B1��
*/

int a[128];

int main(void) {
    int n, c, t, r = 0;
    scanf("%d %d", &n, &c);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= c; i++) {
        t = 0;
        for (int j = 0; j < n; j++) {
            if (i % a[j] == 0) {
                t++;
                break;
            }
        }
        if (t) r++;
    }
    printf("%d", r);
    return 0;
}