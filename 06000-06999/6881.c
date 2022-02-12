#include <stdio.h>

/*
���� : N * M(N, M <= 100) ũ���� ���ڰ� ���� ��Ŀ��� 3���� ����(�ߺ� ����)���� ����
�� �� �ٿ��� �� �Ʒ� �ٷ� �̵��� �� �ִ� ��� ��� ���������� ���� ���� 3���� ���ڸ� ���Ѵ�.
�׷��� ��찡 ���ٸ� -1�� 3�� ����Ѵ�.

�ذ� ��� : ��� ��쿡 ���� �� �� �ٿ������� ���Ʈ ������ �ϰ� �� �Ʒ� �ٿ� �����ϴ� ��찡 �ִ�
���� ���� 3���� ���� ����Ѵ�. ��� ��쿡 �Ұ����� ��� -1�� 3�� ����ϸ� �ȴ�.

�ֿ� �˰��� : �׷��� �̷�, �÷�����, ���Ʈ ����

��ó : CCO 2005 1��
*/

int mat[128][128], vis[128][128], sel[4];
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
int n, m;

int isvalid(int x, int y) {
    if (x < 0 || y < 0 || x >= n || y >= m) return 0;
    if (vis[x][y]) return 0;
    if (mat[x][y] == sel[0] || mat[x][y] == sel[1] || mat[x][y] == sel[2]) return 1;
    return 0;
}

void dfs(int x, int y) {
    vis[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        if (isvalid(x + dxy[i][0], y + dxy[i][1])) dfs(x + dxy[i][0], y + dxy[i][1]);
    }
}

int main(void) {
    scanf("%d %d", &m, &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
    for (int i = 0; i < 10; i++) {
        sel[0] = i;
        for (int j = 0; j < 10; j++) {
            sel[1] = j;
            for (int k = 0; k < 10; k++) {
                sel[2] = k;
                for (int l = 0; l < m; l++) {
                    if (mat[0][l] == i || mat[0][l] == j || mat[0][l] == k) dfs(0, l);
                }
                for (int l = 0; l < m; l++) {
                    if (vis[n - 1][l]) {
                        printf("%d %d %d", sel[0], sel[1], sel[2]);
                        return 0;
                    }
                }
                for (int l = 0; l < n; l++) {
                    for (int o = 0; o < m; o++) vis[l][o] = 0;
                }
            }
        }
    }
    printf("-1 -1 -1");
    return 0;
}