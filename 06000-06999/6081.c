#include <stdio.h>

/*
���� : N(N <= 500)���� �ڿ����� �̷���� ������ �־��� ��, Q(Q <= 500)���� ������ �����Ѵ�.
[S, E] ������ ���� ���Ѵ�.

�ذ� ��� : N�� Q�� ũ�Ⱑ �����Ƿ� ���� ���� ���ذ��� Ǯ�� �ȴ�.

�ֿ� �˰��� : ����

��ó : USACO 2008D B3��
*/

int hay[512];

int main(void) {
    int n, q, s, e, r;
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &hay[i]);
    }
    for (int i = 0; i < q; i++) {
        scanf("%d %d", &s, &e);
        r = 0;
        for (int j = s; j <= e; j++) r += hay[j];
        printf("%d\n", r);
    }
    return 0;
}