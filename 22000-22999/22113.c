#include <stdio.h>

/*
���� : N(N <= 100)���� ������ ���� ȯ�� ǥ�� ȯ�� ��ȹ�� �־��� ��, �־��� ������� ȯ�� �� ȯ�� ����� ���� ���Ѵ�.

�ذ� ��� : �־��� ȯ�� ��ȹ�� ���ʷ� ȯ��ǥ�� �ְ� Ȯ���� ���� ���� �����ָ� �ȴ�.

�ֿ� �˰��� : ����

��ó : ������M 2021 2ȸ A��
*/

int a[128][128], seq[128];

int main(void) {
    int n, m, r = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &seq[i]);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 1; i < m; i++) {
        r += a[seq[i - 1]][seq[i]];
    }
    printf("%d", r);
    return 0;
}