#include <stdio.h>

/*
���� : ù N(N <= 10000)���� �ڿ���, Ȧ��, ¦���� ���� ���� ���� ���Ѵ�.

�ذ� ��� : N�� ������ �����Ƿ� ���� ���� ���غ� ���� ���� ����ϸ� �ȴ�.

�ֿ� �˰��� : ����, ����

��ó : IIPC 2015 A��
*/

int main(void) {
    int p, k, n, r1, r2, r3;
    scanf("%d", &p);
    for (int pp = 0; pp < p; pp++) {
        scanf("%d", &n);
        r1 = 0, r2 = 0, r3 = 0;
        for (int i = 1; i <= n; i++) {
            r1 += i;
            r2 += i * 2 - 1;
            r3 += i * 2;
        }
        printf("%d %d %d\n", r1, r2, r3);
    }
    return 0;
}