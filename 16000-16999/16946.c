#include <stdio.h>

/*
���� : N * M(N, M <= 1000) ũ�� ���ڿ��� 0�� �� ĭ, 1�� ���̶� �� ��, ��� ������ �ش� ���� �μ��� ������
������ ũ�⸦ ���� ���Ѵ�.

�ذ� ��� : �÷������� ���� �� �� ĭ���� ���� ����� ũ�⸦ ���� ����, ��� ������ �ֺ� ���� ��ҵ��� Ȯ���Ѵ�.
�� ����, ��ġ�� �ʴ� �����ҳ��� ������ ũ�⸦ ���ϰ� 1�� ���ϸ� �װ��� �ش� ���� �μ��� ������ ������ ũ���̴�.

�ֿ� �˰��� : �׷��� �̷�, �÷�����
*/

char map[1024][1024], res[1024][1024];
int group[1024][1024], sizes[524288];
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
        if (map[x + dxy[i][0]][y + dxy[i][1]] == '0' && !group[x + dxy[i][0]][y + dxy[i][1]]) r += dfs(x + dxy[i][0], y + dxy[i][1], g);
    }
    return r;
}

int main(void) {
    int sz;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%s", map[i] + 1);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (map[i][j] == '0' && !group[i][j]) {
                g++;
                sizes[g] = dfs(i, j, g);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (map[i][j] == '0') {
                res[i - 1][j - 1] = '0';
                continue;
            }
            sz = sizes[group[i][j + 1]] + 1;
            if (group[i + 1][j] != group[i][j + 1]) sz += sizes[group[i + 1][j]];
            if (group[i][j - 1] != group[i][j + 1] && group[i][j - 1] != group[i + 1][j]) sz += sizes[group[i][j - 1]];
            if (group[i - 1][j] != group[i][j + 1] && group[i - 1][j] != group[i + 1][j] && group[i - 1][j] != group[i][j - 1]) sz += sizes[group[i - 1][j]];
            res[i - 1][j - 1] = sz % 10 + '0';
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%s\n", res[i]);
    }
    return 0;
}