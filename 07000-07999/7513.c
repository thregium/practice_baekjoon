#include <stdio.h>

/*
���� : N(N <= 50)���� �ܾ �־�����, ���� N(N <= 300)���� �ܾ ���� K(K <= 10)���� �־����� ��ġ�� �ܾ����
�̾���� ���ڿ��� ����Ѵ�.

�ذ� ��� : �� �ܾ���� �Է¹��� ����, �־����� ��ġ�� �ܾ ã�� �������� ������ָ� �̾���� ���ڿ��� �ȴ�.

�ֿ� �˰��� : ����

��ó : TUD 2008S 3��
*/

char word[64][16];

int main(void) {
    int t, m, n, k, x;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        scanf("%d", &m);
        for (int i = 0; i < m; i++) {
            scanf("%s", word[i]);
        }
        scanf("%d", &n);
        printf("Scenario #%d:\n", tt);
        for (int i = 0; i < n; i++) {
            scanf("%d", &k);
            for (int j = 0; j < k; j++) {
                scanf("%d", &x);
                printf("%s", word[x]);
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}