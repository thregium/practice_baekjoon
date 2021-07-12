#include <stdio.h>

/*
���� : M(M <= 20000)���� N(N <= 10000) ������ �ڿ��� ��� ��ġ�� ���� ������ ���Ѵ�.

�ذ� ��� : �� ���� ������ �� ���� 2�� �̻� �����ϴ� ���� ������ ���ϸ� �ȴ�.

�ֿ� �˰��� : ����

��ó : Brasil 2002 PA��
*/

int cnt[10240];

int main(void) {
    int n, m, ti, r;
    while (1) {
        scanf("%d %d", &n, &m);
        if (n == 0 && m == 0) break;
        for (int i = 0; i < m; i++) {
            scanf("%d", &ti);
            cnt[ti]++;
        }
        r = 0;
        for (int i = 1; i <= n; i++) {
            if (cnt[i] > 1) r++;
            cnt[i] = 0;
        }
        printf("%d\n", r);
    }
    return 0;
}