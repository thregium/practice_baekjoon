#include <stdio.h>

/*
���� : N(N <= 100) * M(M <= 70)�� ���ڿ��� ����츮�� ������ ���Ѵ�. ����츮�� ���� �����¿�밢������ �� ���� ĭ�� ����
�����ϰ� ���̰� ���� ĭ���� �����̴�.

�ذ� ��� : �÷������� �̿��Ͽ� ���̰� ���� ������ ĭ�鿡 ���� �湮 ó���� �ϸ� �� ���� ĭ�� ������ ���캻��.
���ٸ� �ش� ĭ���� ���츮�� ���̹Ƿ� �ᱣ���� �߰��ϰ�, �ִٸ� �湮 ó���� �ϰ� �Ѿ��. �̹� �湮 ó���� ĭ��
������ �ʰ� �Ѿ�� �ȴ�.

�ֿ� �˰��� : �׷��� �̷�, �÷�����

��ó : USACO 2008N B2��
*/

int height[128][128], vis[128][128];
int dxy[8][2] = { {1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1} };
int n, m;

int isvalid(int x, int y, int h) {
    if (x < 0 || y < 0 || x >= n || y >= m) return 0;
    if (height[x][y] > h) return -1;
    if (vis[x][y] || height[x][y] < h) return 0;
    return 1;
}

int dfs(int x, int y, int h, int r) {
    //r = 1 : ������ �� ���� ���츮�� ����, 0 : ������ �� ���� ���츮�� ����
    int v;
    vis[x][y] = 1;
    for (int i = 0; i < 8; i++) {
        v = isvalid(x + dxy[i][0], y + dxy[i][1], h);
        if (v < 0) r = 0;
        else if (v > 0) r = dfs(x + dxy[i][0], y + dxy[i][1], h, r);
    }
    return r;
}

int main(void) {
    int r = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &height[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!vis[i][j]) {
                r += dfs(i, j, height[i][j], 1);
            }
        }
    }
    printf("%d", r);
    return 0;
}