#include <stdio.h>

/*
���� : N * M(N, M <= 50) ũ���� �迭�� ���ڵ��� ���� ��, �����¿�� ������ ���� ���ڷ� �̷����
���� 4 �̻��� ����Ŭ�� �ִ��� ���Ѵ�.

�ذ� ��� : �迭�� �� ���ҿ� ���� DFS�� �õ��Ѵ�. ���� �������� �̵��� ������ �ݴ밡 �ƴ� ���⿡�� �԰�
�̹� �湮�� ĭ�� �湮�ϰ� �Ǹ� ���� 2�� �ƴ� ����Ŭ�� �߰��� ���̹Ƿ� Yes�� ���̰�,
�׷��� ���� ���ٸ� ����Ŭ�� ���� ���̹Ƿ� No�� ���̴�.

�ֿ� �˰��� : �׷��� �̷�, DFS
*/

char s[64][64];
int vis[64][64];
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
int n, m;

int isvalid(int x, int y, char c) {
    if (x < 0 || y < 0 || x >= n || y >= m) return 0;
    if (s[x][y] != c) return 0;
    if (vis[x][y]) return -1;
    return 1;
}

int dfs(int x, int y, int l) {
    vis[x][y] = 1;
    int t = 0, r = 0;
    for (int i = 0; i < 4; i++) {
        if (l == i) continue;
        t = isvalid(x + dxy[i][0], y + dxy[i][1], s[x][y]);
        if (t < 0) {
            return 1;
        }
        else if (t) r |= dfs(x + dxy[i][0], y + dxy[i][1], (i + 2) & 3);
    }
    return r;
}

int main(void) {
    int r = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s", s[i]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            r |= dfs(i, j, -1);
            for (int ii = 0; ii < n; ii++) {
                for (int jj = 0; jj < m; jj++) vis[ii][jj] = 0;
            }
        }
    }
    printf("%s", r ? "Yes" : "No");
    return 0;
}