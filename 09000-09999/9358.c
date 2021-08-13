#include <stdio.h>

/*
���� : N(N <= 100) ������ �迭�� ������ ���� ���� �ݺ��� ��, ������ ���� �� ���� �� ��� ���� �� ū�� Ȯ���Ѵ�.

�ذ� ��� : �ùķ��̼��� ���� �迭�� ������ ���°��� ������ �ݺ��غ��� �ȴ�. �迭�� ���� �������� N�� �������� ���� ����
�ٽ� �ݺ��Ͽ� N�� 2�� �� �� ���� �ݺ��Ѵ�.

�ֿ� �˰��� : ����, �ùķ��̼�

��ó : LCPC 2011 A��
*/

int a[128];

int main(void) {
    int t, n;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        while (n > 2) {
            for (int i = 0, j = n - 1; i <= j; i++, j--) {
                a[i] += a[j];
            }
            n = (n + 1) >> 1;
        }
        if (a[0] > a[1]) printf("Case #%d: Alice\n", tt);
        else printf("Case #%d: Bob\n", tt);
    }
    return 0;
}