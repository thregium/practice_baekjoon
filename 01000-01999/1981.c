#include <stdio.h>

/*
���� : N * N(N <= 100) ũ���� �迭�� 0 �̻� 200 ������ ������ ���� �ִ�. �̶�, �� �迭�� (1, 1)����
�����¿�� �̵��� (N, N)���� �̵��ϸ� ��ο��� ���� �� �ִ� �ִ񰪰� �ּڰ��� ���̰�
���� ���� ���� ���̸� ���Ѵ�.

�ذ� ��� : �迭�� �� ������ ���� ���̹Ƿ� ���� �������� ������ ���� �������� �Űܰ���
�̵� ������ �� ��� ���̰� �ּ��� ��츦 ã�Ƴ����� �ȴ�.
�������� �������� �� �� �ִ� �� ���θ� �̸� Ȯ���ؾ� �Կ� �����Ѵ�.

�ֿ� �˰��� : �׷��� �̷�, �÷�����, �� ������

��ó : TUD 2006 6��
*/

int a[128][128], vis[128][128];
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
int n, s = 0, e = 0;

int isvalid(int x, int y) {
    if (x < 0 || y < 0 || x >= n || y >= n) return 0;
    if (vis[x][y] || a[x][y] < s || a[x][y] > e) return 0;
    return 1;
}

int dfs(int x, int y) {
    if (!isvalid(x, y)) return 0;
    vis[x][y] = 1;
    int r = 0;
    if (x == n - 1 && y == n - 1) return 1;
    for (int i = 0; i < 4; i++) {
        if (isvalid(x + dxy[i][0], y + dxy[i][1])) r |= dfs(x + dxy[i][0], y + dxy[i][1]);
    }
    return r;
}

int main(void) {
    int r = 103000;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    while (s <= 200) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) vis[i][j] = 0;
        }
        while (e <= 200 && !dfs(0, 0)) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) vis[i][j] = 0;
            }
            e++;
        }
        if (e <= 200 && e - s < r) r = e - s;
        s++;
    }
    printf("%d", r);
    return 0;
}