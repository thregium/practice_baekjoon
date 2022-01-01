#include <stdio.h>

/*
���� : N^2 * N^2(2 <= N <= 6) ũ���� �����ǿ��� ���� �ൿ�� Q(Q <= 100)�� �� ����
�������� ���� �հ� ���� ū ���������� ũ�⸦ ���Ѵ�.
���ڸ� 2^L_i(0 <= L_i <= N) ������ ���� �� �� ������ 90�� �ð�������� ȸ����Ų ���� �����¿�� 2ĭ ���Ͽ��� ������ �����ִ�
ĭ�� ���� ���� 1�� ���δ�.
���������� ũ��� �����¿�� 0�� �ƴϸ� ������ ������ ���� ���̸�, ó�� �־����� ������ ���� 1000 ���ϴ�.

�ذ� ��� : ȸ�� ������ ��Ʈ����ŷ�� ���� ���� ������ ���� �����ϴ�.
L�� ���� �������� �� �迭������ ��ġ�� ����� ���� ����̴�.
�׸��� ���� �ܰ�� ���� �迭�� ������ ����ϸ� �ǰ�, ������ ���������� ũ��� ������ �÷����ʷ� ���� �� �ִ�.

�ֿ� �˰��� : ����, �ùķ��̼�, ��Ʈ����ŷ, �÷�����
*/

int ice[64][64], tmp[80][80], vis[64][64];
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

int big(int a, int b) {
    return a > b ? a : b;
}

int isvalid(int n, int x, int y) {
    if (x < 0 || y < 0 || x >= n || y >= n) return 0;
    if (vis[x][y] || ice[x][y] == 0) return 0;
    return 1;
}

int dfs(int n, int x, int y) {
    vis[x][y] = 1;
    int r = 1;
    for (int i = 0; i < 4; i++) {
        if (isvalid(n, x + dxy[i][0], y + dxy[i][1])) r += dfs(n, x + dxy[i][0], y + dxy[i][1]);
    }
    return r;
}

int main(void) {
    int n, q, l, c = 0, b = 0;
    scanf("%d %d", &n, &q);
    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < (1 << n); j++) {
            scanf("%d", &ice[i][j]);
        }
    }
    for (int i = 0; i < q; i++) {
        scanf("%d", &l);
        for (int j = 0; j < (1 << n); j++) {
            for (int k = 0; k < (1 << n); k++) {
                tmp[(j >> l << l) + (k & ((1 << l) - 1)) + 1][(k >> l << l) + (~j & ((1 << l) - 1)) + 1] = ice[j][k];
            }
        }
        for (int j = 1; j <= (1 << n); j++) {
            for (int k = 1; k <= (1 << n); k++) {
                c = 0;
                for (int d = 0; d < 4; d++) {
                    if (tmp[j + dxy[d][0]][k + dxy[d][1]]) c++;
                }
                ice[j - 1][k - 1] = tmp[j][k] - (c < 3);
                if (ice[j - 1][k - 1] < 0) ice[j - 1][k - 1] = 0;
            }
        }
    }
    c = 0;
    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < (1 << n); j++) {
            c += ice[i][j];
            if (!vis[i][j] && ice[i][j] > 0) b = big(b, dfs(1 << n, i, j));
        }
    }
    printf("%d\n%d", c, b);
    return 0;
}