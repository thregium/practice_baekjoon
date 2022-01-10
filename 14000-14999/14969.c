#include <stdio.h>

/*
���� : N(N <= 1000)���� �ڿ���(<= 10^6) ��� �� �ڿ����� �̷���� ���� ���� M(2 <= M <= 2 * 10^6) ������ ��
��� ���� ���� ū ���� ���� ���Ѵ�. �׷��� ���� �ϳ��� ���ٸ� NONE�� ����Ѵ�.

�ذ� ��� : 2�� for���� ���� ��� ���� Ȯ���Ѵ�. �׷��� ���� ���� �� ���δ� ���� ���� ������ �ϸ� �� �� �ִ�.

�ֿ� �˰��� : ���Ʈ ����

��ó : JDC 2017 A��
*/

int a[1024];

int main(void) {
    int n, m, r;
    while (1) {
        scanf("%d %d", &n, &m);
        if (n == 0) break;
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        r = -1;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (a[i] + a[j] <= m && a[i] + a[j] > r) r = a[i] + a[j];
            }
        }
        if (r < 0) printf("NONE\n");
        else printf("%d\n", r);
    }
    return 0;
}