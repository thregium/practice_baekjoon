#include <stdio.h>

/*
���� : N(N <= 1000)���� �ڿ���(<= 10^9) �� �ִ񰪰� M(M <= 1000)���� �ڿ���(<= 10^9) �� �ִ��� ���� ���Ѵ�.

�ذ� ��� : ������ �ִ��� ���� ���� ���ϸ� �ȴ�.

�ֿ� �˰��� : ����

��ó : ���ϴ� 2018 B��
*/

int main(void) {
    int n, m, x, hr = -1, ar = -1;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        if (x > hr) hr = x;
    }
    for (int i = 0; i < m; i++) {
        scanf("%d", &x);
        if (x > ar) ar = x;
    }
    if (hr < 0 || ar < 0) return 1;
    printf("%d", hr + ar);
    return 0;
}