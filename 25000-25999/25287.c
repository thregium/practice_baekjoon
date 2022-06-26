#include <stdio.h>

/*
���� : N(N <= 50000)���� �ڿ����� �̷���� �������� �� ���� N - x + 1�� �ٲ� �� �ִٸ�
���� ������ �� Ȯ���Ѵ�.

�ذ� ��� : �տ������� ���� ������ ���� �־�� ���� ������ �۴ٸ� ū ������ �ٽ� �־��.
�Ѵ� �� �ȴٸ� ���� �� ���� ���̹Ƿ� ������ �Ұ����ϴ�.

�ֿ� �˰��� : �׸��� �˰���

��ó : ���� 6ȸ�� C��
*/

int a[51200];

int small(int a, int b) {
    return a < b ? a : b;
}

int big(int a, int b) {
    return a > b ? a : b;
}

int main(void) {
    int t, n, r;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }
        r = 0;
        for (int i = 1; i <= n; i++) {
            a[i] = small(a[i], n - a[i] + 1);
            if (a[i] < a[i - 1]) {
                a[i] = big(a[i], n - a[i] + 1);
                if (a[i] < a[i - 1]) break;
            }
            r = i;
        }
        if (r == n) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}