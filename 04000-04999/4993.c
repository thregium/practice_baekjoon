#include <stdio.h>

/*
���� : H * W(H, W <= 20) ũ���� ���ڿ� ���� ĭ�� ���� ĭ, ��� ������ ��ġ�� �־��� ��, ��� �������� ���� ĭ�� ���� �ʰ�
�� �� �ִ� ĭ�� ���� ���Ѵ�.

�ذ� ��� : ���� �������� �÷������� ���� Ǯ �� �ִ�.

�ֿ� �˰��� : �׷��� �̷�, �÷�����

��ó : JDome 2004 B��
*/

int w, h;
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
char a[32][32], vis[32][32];

int isvalid(int x, int y) {
    if (x < 0 || y < 0 || x >= h || y >= w) return 0;
    if (vis[x][y] || a[x][y] == '#') return 0;
    return 1;
}

dfs(int x, int y, int c) {
    vis[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        if (isvalid(x + dxy[i][0], y + dxy[i][1])) c += dfs(x + dxy[i][0], y + dxy[i][1], 1);
    }
    return c;
}

int main(void) {
    int x = 0, y = 0;
    while (1) {
        scanf("%d %d", &w, &h);
        if (w == 0 && h == 0) break;
        for (int i = 0; i < h; i++) {
            scanf("%s", a[i]);
            for (int j = 0; j < w; j++) {
                if (a[i][j] == '@') {
                    x = i;
                    y = j;
                }
            }
        }
        printf("%d\n", dfs(x, y, 1));
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) vis[i][j] = 0;
        }
    }
    return 0;
}