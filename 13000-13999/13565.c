#include <stdio.h>

/*
���� : M * N(M, N <= 1000) ũ���� 0�� 1�� �̷���� ���ڿ��� �� ���� 0 �� �ϳ����� �����¿�� �̵��ϸ�
1�� ĭ�� ������ �ʰ� �� �Ʒ��� �̵� �������� ���Ѵ�.

�ذ� ��� : �÷������� �̿��Ͽ� �� ���� ��� 0���� �����¿�� �̵��ϸ� �� �� �ִ� ��� ĭ�� ã��,
�� ��� �� �Ʒ��� �ִ� �� ã���� �ȴ�.

�ֿ� �˰��� : �׷��� �̷�, �÷�����

��ó : Daejeon 2016 G��
*/

char grid[1024][1024], vis[1024][1024];
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
int m, n;

int isvalid(int x, int y) {
    if (x < 0 || y < 0 || x >= m || y >= n) return 0;
    if (vis[x][y] || grid[x][y] == '1') return 0;
    return 1;
}

void dfs(int x, int y) {
    vis[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        if (isvalid(x + dxy[i][0], y + dxy[i][1])) dfs(x + dxy[i][0], y + dxy[i][1]);
    }
}

int main(void) {
    int r = 0;
    scanf("%d %d", &m, &n);
    for (int i = 0; i < m; i++) {
        scanf("%s", grid[i]);
    }
    for (int i = 0; i < n; i++) {
        if (grid[0][i] == '0') dfs(0, i);
    }
    for (int i = 0; i < n; i++) {
        if (vis[m - 1][i]) r = 1;
    }
    printf("%s", r ? "YES" : "NO");
    return 0;
}