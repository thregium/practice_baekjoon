#include <stdio.h>

/*
���� : H * W(H, W <= 8) ũ���� �ǿ� 6���� ������ �־�����.
���� ���� ���� �����¿�� ����� ���� ĭ�� ������ �ٲٴ� ������ 5ȸ �̳��� �ݺ��Ͽ� ���� �� �ִ�
���� ū C�� ���� ����� ĭ�� ������ ���Ѵ�.

�ذ� ��� : 5ȸ���� �� ������ �����ϴ� ��� ����� �õ��غ� ����,
�� �� C�� ���� ����� ĭ�� ������ ���� ���� ���� ���ϸ� �ȴ�. �� �ܰ迡�� ���� ���´�
������ �̿��Ͽ� �����Ѵ�. ����� ���� ĭ ���δ� �÷������� ���� ���� �� �ִ�.

�ֿ� �˰��� : �׷��� �̷�, �÷�����, ����, ���Ʈ ����

��ó : JDC 2011 C��
*/

int p[8][16][16], vis[16][16];
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
int h, w, c, best;

int isvalid(int l, int x, int y, int e) {
    if (x < 0 || y < 0 || x >= h || y >= w) return 0;
    if (vis[x][y] || p[l][x][y] != e) return 0;
    return 1;
}

int dfs(int l, int x, int y, int e) {
    vis[x][y] = 1;
    int r = 1;
    for (int i = 0; i < 4; i++) {
        if (isvalid(l, x + dxy[i][0], y + dxy[i][1], e)) r += dfs(l, x + dxy[i][0], y + dxy[i][1], e);
    }
    return r;
}

void track(int lv) {
    if (lv == 5) {
        int r;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (p[lv][i][j] != c) continue;
                r = dfs(lv, i, j, c);
                if (r > best) best = r;
            }
        }
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) vis[i][j] = 0;
        }
        return;
    }
    for (int i = 1; i <= 6; i++) {
        dfs(lv, 0, 0, p[lv][0][0]);
        for (int j = 0; j < h; j++) {
            for (int k = 0; k < w; k++) {
                if (vis[j][k]) p[lv + 1][j][k] = i;
                else p[lv + 1][j][k] = p[lv][j][k];
                vis[j][k] = 0;
            }
        }
        track(lv + 1);
    }
}

int main(void) {
    while (1) {
        scanf("%d %d %d", &h, &w, &c);
        if (h == 0) break;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                scanf("%d", &p[0][i][j]);
            }
        }
        best = 0;
        track(0);
        printf("%d\n", best);
    }
    return 0;
}