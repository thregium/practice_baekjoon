#include <stdio.h>

/*
���� : M * N(M, N <= 100) ũ���� �ݰ��ڿ� 'W'�� 'B'�� �̷���� �� ������ �־�����. �̶�, �� ������ �������� �� ������ ��������
�հ� ����, �� ������ �������� ������ ũ���� ������ ���ٰ� �Ѵ�. �����¿�� ���� ������ ������ �����̶� �� ��,
�� ������ �������� ���Ѵ�.

�ذ� ��� : �÷������� �̿��� ���� �湮���� ���� ���縶�� ���� ����� ũ�⸦ ���ϰ� �� ������ �Ͽ� �ش� ������ �����¿� ���Ѵ�.
���� ���� ���� �� ������ �������� ����ϸ� �ȴ�.

�ֿ� �˰��� : �׷��� �̷�, �÷�����
*/

char soli[128][128], vis[128][128];
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
int n, m;

int sqr(int x) {
    return x * x;
}

int isvalid(int x, int y, char c) {
    if (x < 0 || y < 0 || x >= n || y >= m) return 0;
    if (vis[x][y] || soli[x][y] != c) return 0;
    return 1;
}

int dfs(int x, int y, char c) {
    int r = 1;
    vis[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        if (isvalid(x + dxy[i][0], y + dxy[i][1], c)) r += dfs(x + dxy[i][0], y + dxy[i][1], c);
    }
    return r;
}

int main(void) {
    int w = 0, b = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s", soli[i]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (vis[i][j]) continue;
            if (soli[i][j] == 'W') w += sqr(dfs(i, j, 'W'));
            else if (soli[i][j] == 'B') b += sqr(dfs(i, j, 'B'));
            else return 1;
        }
    }
    printf("%d %d", w, b);
    return 0;
}