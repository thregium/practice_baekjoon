#include <stdio.h>

/*
���� : N * 2(N <= 100)���� ī�尡 ���ʷ� �ִ�. M(M <= 1000)�� �־������ ���� �� ī���� ������ ����Ѵ�.

�ذ� ��� : ī���� �̵��� �ùķ��̼��� �� �� ����� ����ϸ� �ȴ�.

�ֿ� �˰��� : ����, �ùķ��̼�

��ó : JOI 2007�� 4��
*/

int card[256], tcard[256];

int main(void) {
    int n, m, k;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n * 2; i++) {
        card[i - 1] = i;
    }
    for (int i = 0; i < m; i++) {
        scanf("%d", &k);
        if (k) {
            for (int j = k; j < 2 * n; j++) tcard[j - k] = card[j];
            for (int j = 0; j < k; j++) tcard[j + 2 * n - k] = card[j];
        }
        else {
            for (int i = 0; i < n; i++) {
                tcard[i * 2] = card[i];
                tcard[i * 2 + 1] = card[i + n];
            }
        }
        for (int j = 0; j < 2 * n; j++) card[j] = tcard[j];
    }
    for (int i = 0; i < n * 2; i++) {
        printf("%d\n", card[i]);
    }
    return 0;
}