#include <stdio.h>

/*
���� : N * M(N, M <= 100) ũ���� �� ����� ���� ����Ѵ�.

�ذ� ��� : ����� ���ҵ��� ���� ���� �� ���ؼ� ����ϸ� �ȴ�.

�ֿ� �˰��� : ����, ��Ģ����
*/

int a[128][128], b[128][128];

int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &b[i][j]);
            printf("%d ", a[i][j] + b[i][j]);
        }
        printf("\n");
    }
    return 0;
}