#include <stdio.h>

/*
���� : N���� M(-10^9 <= N <= M <= 10^9)���� ������ ���� ���Ѵ�.

�ذ� ��� : ���콺 �� ������ �̿��Ѵ�.

�ֿ� �˰��� : ����

��ó : TUD 2006 8��
*/

long long getsum(long long s, long long e) {
    return ((s + e) * (e - s + 1)) >> 1;
}

int main(void) {
    int t, n, m;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        scanf("%d %d", &n, &m);
        printf("Scenario #%d:\n", tt);
        printf("%lld\n\n", getsum(n, m));
    }
    return 0;
}