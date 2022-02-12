#include <stdio.h>

/*
���� : H * W(H, W <= 100) ũ���� ���ڿ� '#'�� '.'�� �ִ�. '#'���� �� ���� ����� ������ ���Ѵ�.

�ذ� ��� : �� �湮���� ���� '#'���� �÷������� �ϰ�, �÷������� �� Ƚ���� ���ϸ� �ȴ�.

�ֿ� �˰��� : �׷��� �̷�, �÷�����

��ó : IDI 2009 G��
*/

char sheep[128][128];
int vis[128][128];
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
int h, w;

int isvalid(int x, int y) {
    if (x < 0 || y < 0 || x >= h || y >= w) return 0;
    if (vis[x][y] || sheep[x][y] == '.') return 0;
    return 1;
}

void dfs(int x, int y) {
    vis[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        if (isvalid(x + dxy[i][0], y + dxy[i][1])) dfs(x + dxy[i][0], y + dxy[i][1]);
    }
}

int main(void) {
    int t, r;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d %d", &h, &w);
        for (int i = 0; i < h; i++) {
            scanf("%s", sheep[i]);
            for (int j = 0; j < w; j++) vis[i][j] = 0;
        }
        r = 0;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (sheep[i][j] == '#' && !vis[i][j]) {
                    dfs(i, j);
                    r++;
                }
            }
        }
        printf("%d\n", r);
    }
    return 0;
}