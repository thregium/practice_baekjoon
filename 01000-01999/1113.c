#include <stdio.h>

/*
���� : N * M(N, M <= 50) ũ���� �������� ����(<= 9, �ڿ���)�� �־��� ��, ���� �ȿ� ���ξ� �� �� �ִ� ���� ���� ���Ѵ�.
�����¿�� �����ִ� ��� ���ξ� �� �� �ִ� �κ��̴�.

�ذ� ��� : ���� 1���� Ȯ���� ������ �ش� ���� ������ ����� ������ Ȯ���Ѵ�. ���� �׵θ��� ���� �� �ִ� ���,
���ξ� �� �� ���� �κ��̰�, ���� �� ���ٸ� ���ξ� �� �� �ִ� �κ��̴�. ���ξ� �� �� �ִ� �κ��� ���̸�
��� ���̿� ���� ���� ���ϸ� ���� �ȴ�.

�ֿ� �˰��� : �׷��� �̷�, �÷�����
*/

char height[64][64], vis[64][64];
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
int n, m;

int isvalid(int x, int y, int h) {
    if (x < 0 || y < 0 || x >= n || y >= m) return -1;
    else if (vis[x][y] || height[x][y] > h + '0') return 0;
    else return 1;
}

int dfs(int x, int y, int h) {
    int r = 1, t;
    vis[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        t = isvalid(x + dxy[i][0], y + dxy[i][1], h);
        if (t < 0) r = -1;
        else if (t > 0) {
            t = dfs(x + dxy[i][0], y + dxy[i][1], h);
            if (t < 0 || r < 0) r = -1;
            else r += t;
        }
    }
    return r;
}

int main(void) {
    int r = 0, t;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s", height[i]);
    }
    for (int i = 1; i <= 8; i++) {
        for (int x = 0; x < n; x++) {
            for (int y = 0; y < m; y++) {
                if (!vis[x][y] && height[x][y] <= i + '0') {
                    t = dfs(x, y, i);
                    if (t > 0) r += t;
                }
            }
        }

        for (int x = 0; x < n; x++) {
            for (int y = 0; y < m; y++) vis[x][y] = 0;
        }
    }
    printf("%d", r);
    return 0;
}