#include <stdio.h>

/*
���� : N * M(N, M <= 1000) ũ���� 0�� 1�� ���� ���ڿ��� 1�� �����¿� ����� �κ��� ���� ��Ҷ� �� ��, �� ĭ�� ���� �ٲپ� ���� �� �ִ�
���� ū ���� ����� ũ�⸦ ���Ѵ�. ��, 0�� 1�� ���� 1�� �̻� �ִ�.

�ذ� ��� : �翬�� 1�� 0���� �ٲٴ� �� ���ٴ� 0�� 1�� �ٲٴ� ���� ���� ��Ҹ� �� Ű�� �� �ֱ� ������ �̵��̴�.
��� �������� ũ�⸦ ���� ����, �� 0���� �ش� 0�� 1�� �ٲپ��� �� ���� ����� ũ�⸦ ���� ���ϸ� �ִ��� ã���� �ȴ�.
�̶� ���� ���� ��Ҹ� ������ ���ϸ� �� �ȴ�.

�ֿ� �˰��� : �׷��� �̷�, �÷�����, ���Ʈ ����
*/

int shape[1024][1024], group[1024][1024], sizes[524288];
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
int n, m, g = 0;

int isvalid(int x, int y) {
    if (x < 1 || y < 1 || x > n || y > m) return 0;
    if (group[x][y]) return 0;
    return 1;
}

int dfs(int x, int y, int g) {
    int r = 1;
    group[x][y] = g;
    for (int i = 0; i < 4; i++) {
        if (shape[x + dxy[i][0]][y + dxy[i][1]] && !group[x + dxy[i][0]][y + dxy[i][1]]) r += dfs(x + dxy[i][0], y + dxy[i][1], g);
    }
    return r;
}

int main(void) {
    int r = 0, sz;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &shape[i][j]);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (shape[i][j] && !group[i][j]) {
                g++;
                sizes[g] = dfs(i, j, g);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (shape[i][j]) continue;
            sz = sizes[group[i][j + 1]] + 1;
            if (group[i + 1][j] != group[i][j + 1]) sz += sizes[group[i + 1][j]];
            if (group[i][j - 1] != group[i][j + 1] && group[i][j - 1] != group[i + 1][j]) sz += sizes[group[i][j - 1]];
            if (group[i - 1][j] != group[i][j + 1] && group[i - 1][j] != group[i + 1][j] && group[i - 1][j] != group[i][j - 1]) sz += sizes[group[i - 1][j]];
            if (sz > r) r = sz;
        }
    }
    if (r == 0) r = n * m;
    printf("%d", r);
    return 0;
}