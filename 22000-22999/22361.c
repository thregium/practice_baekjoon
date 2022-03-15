#include <stdio.h>

/*
���� : N * M(N, M <= 100) ũ���� ĭ�� N���� M���� �ڿ���(<= 1000) ������ ������ ���.
�� ���鿡�� Ȯ�� ������ ���ڵ�(0 ~ 9)�� ������ ���� ����Ѵ�.

�ذ� ��� : �� �ڿ����� ���� ���� ����, 10���� ������ ���� �ڸ������� ���� �� ������ �ȴ�.

�ֿ� �˰��� : ����

��ó : JAG 2020D A��
*/

int a[128], b[128], cnt[10];

int main(void) {
    int n, m;
    while (1) {
        scanf("%d %d", &n, &m);
        if (n == 0) break;
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        for (int i = 0; i < m; i++) {
            scanf("%d", &b[i]);
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (int k = a[i] * b[j]; k; k /= 10) cnt[k % 10]++;
            }
        }
        for (int i = 0; i < 10; i++) {
            printf("%d%c", cnt[i], i == 9 ? '\n' : ' ');
            cnt[i] = 0;
        }
    }
    return 0;
}