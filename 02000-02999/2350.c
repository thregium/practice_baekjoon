#include <stdio.h>

/*
���� : N(N <= 1000)���� ������ M(M <= 100000)���� �������� �̷���� ������ �׷����� �ִ�.
�� ������ ����ġ W(W <= 200)�� ���´�. �̶�, K(K <= 100000)���� ������ �����Ѵ�.
�� ���� i, j ���̸� �մ� ��� ��� ���� ����ġ�� �ּڰ��� ū ����� ����ġ �ּڰ��� ����Ѵ�.

�ذ� ��� : �׷����� ����ġ���� �Է¹��� ��, �÷��̵�-���� �˰����� �̿��� ��� ����� ����ġ �ּڰ��� ���Ѵ�.
�������� ���� �� �� ����� ����ġ �ּڰ��� Ŀ���ٸ� ����ġ�� ������Ʈ �ϴ� ������� ���ϸ� �ȴ�.
�� �������δ� �����ص� ��� ����� ����ġ�� ���� ����ϸ� �ȴ�.

�ֿ� �˰��� : �׷��� �̷�, �÷��̵�-����

��ó : Shumen 2012 A2��
*/

int maxwidth[1024][1024];

int small(int a, int b) {
    return a < b ? a : b;
}

int big(int a, int b) {
    return a > b ? a : b;
}

int main(void) {
    int n, m, k, x, y, w;
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &x, &y, &w);
        if (maxwidth[x][y]) maxwidth[x][y] = big(maxwidth[x][y], w);
        else maxwidth[x][y] = w;
        if (maxwidth[y][x]) maxwidth[y][x] = big(maxwidth[y][x], w);
        else maxwidth[y][x] = w;
    }
    for (int v = 1; v <= n; v++) {
        for (int i = 1; i <= n; i++) {
            if (maxwidth[i][v] == 0) continue;
            for (int j = 1; j <= n; j++) {
                if (small(maxwidth[i][v], maxwidth[v][j]) > maxwidth[i][j]) {
                    maxwidth[i][j] = small(maxwidth[i][v], maxwidth[v][j]);
                }
            }
        }
    }
    for (int i = 0; i < k; i++) {
        scanf("%d %d", &x, &y);
        printf("%d\n", maxwidth[x][y]);
    }
    return 0;
}