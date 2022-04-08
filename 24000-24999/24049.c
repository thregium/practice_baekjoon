#include <stdio.h>

/*
���� : N * M(N, M <= 1000) ũ���� ĭ�� �ɵ��� �ɴ´�. �ٱ��� �� ���ʰ� �� ���ʿ� ���� �ɵ��� ���� �־�����
���� ������ �Ʒ��� �ɴ� ���� ���� ���Ѵ�. �� ���� ���ʰ� ���� ���� ���ٸ� �����, �ٸ��ٸ� ������
���� �ɾ����.

�ذ� ��� : ������ �־������ �����Ѵ�.

�ֿ� �˰��� : ����, �ùķ��̼�

��ó : pjshwa
*/

int flower[1024][1024];

int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &flower[i][0]);
    }
    for (int j = 1; j <= m; j++) {
        scanf("%d", &flower[0][j]);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            flower[i][j] = (flower[i - 1][j] != flower[i][j - 1]);
        }
    }
    printf("%d", flower[n][m]);
    return 0;
}