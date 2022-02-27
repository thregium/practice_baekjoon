#include <stdio.h>
#include <stdlib.h>

/*
���� : N * M(N, M <= 50) ũ���� ���ڿ� 0�� 1�� ���� �ִ�.
0�� ���� ĭ ��� ���� ����� 1���� �Ÿ��� ���� �� ���� �Ÿ��� ���Ѵ�.
�Ÿ��� �����¿�밢������ �̵��ϴ� �ִܰŸ��� �ǹ��Ѵ�.

�ذ� ��� : ��� 0���� ��� 1�� ���� �Ÿ��� ���ϰ� ���� ���� ���� ã���� �ȴ�.
�Ÿ��� X�� Y��ǥ�� ���� ���� ��� �� ū ���� ���� ������ ��� �����ϴ�.

�ֿ� �˰��� : ����, ���Ʈ ����
*/

int a[64][64];

int small(int a, int b) {
    return a < b ? a : b;
}

int big(int a, int b) {
    return a > b ? a : b;
}

int getdist(int x1, int y1, int x2, int y2) {
    return big(abs(x2 - x1), abs(y2 - y1));
}

int main(void) {
    int n, m, c, r = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j]) continue;
            c = 103000;
            for (int ii = 0; ii < n; ii++) {
                for (int jj = 0; jj < m; jj++) {
                    if (!a[ii][jj]) continue;
                    c = small(c, getdist(i, j, ii, jj));
                }
            }
            r = big(r, c);
        }
    }
    printf("%d", r);
    return 0;
}