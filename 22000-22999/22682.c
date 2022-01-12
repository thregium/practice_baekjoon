#include <stdio.h>

/*
���� : H * W(H, W <= 50) ũ���� ���ڿ� 'B', 'W', '.'�� �����ִ�. � '.'���� �����¿�� �������� ��
'B' �Ǵ� 'W' �� �� ������ ���� �� �ִٸ� �� ������ �ѷ��ο��ٰ� �Ѵ�. 'B'�� 'W'�� �ѷ����� ĭ�� ������
���� ���Ѵ�.

�ذ� ��� : �� '.'���� �÷������� ���� ������ 'B'�� 'W'�� �ִ� �� ���θ� Ȯ���Ѵ�.
�� �� �ϳ��� �ִٸ� �ٽ� �÷������� �Ͽ� '.'�� ������ ���� �� ���� �ѷ����� ĭ�� ������ �ش� '.' ������ ������ �߰��Ѵ�.
�̸� ��� ĭ�� ���� �ݺ��ϰ� �� ���� �ѷ����� ĭ�� ������ ���ϸ� ���� �ȴ�.

�ֿ� �˰��� : �׷��� �̷�, �÷�����

��ó : JAG 2007D C��
*/

char ground[64][64], vis[64][64];
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
int w, h;

int isvalid(int x, int y, int p) {
    if (x < 0 || y < 0 || x >= h || y >= w) return 0;
    if (vis[x][y] != p) return 0;
    if (ground[x][y] == 'B') return -1;
    if (ground[x][y] == 'W') return -2;
    return 1;
}

int dfs1(int x, int y) {
    vis[x][y] = 1;
    int r = 0, t;
    for (int i = 0; i < 4; i++) {
        t = isvalid(x + dxy[i][0], y + dxy[i][1], 0);
        if (t < 0) r |= (-t);
        else if (t > 0) r |= dfs1(x + dxy[i][0], y + dxy[i][1]);
    }
    return r;
}

int dfs2(int x, int y) {
    vis[x][y] = 2;
    int r = 1;
    for (int i = 0; i < 4; i++) {
        if (isvalid(x + dxy[i][0], y + dxy[i][1], 1)) r += dfs2(x + dxy[i][0], y + dxy[i][1]);
    }
    return r;
}

int main(void) {
    int black, white, t;
    while (1) {
        scanf("%d %d", &w, &h);
        if (w == 0) break;
        black = 0, white = 0;
        for (int i = 0; i < h; i++) {
            scanf("%s", ground[i]);
        }

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (!vis[i][j] && ground[i][j] == '.') {
                    t = dfs1(i, j);
                    if (t == 1) {
                        black += dfs2(i, j);
                    }
                    else if (t == 2) {
                        white += dfs2(i, j);
                    }
                }
            }
        }

        printf("%d %d\n", black, white);
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) vis[i][j] = 0;
        }
    }
    return 0;
}