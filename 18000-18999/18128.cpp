#include <stdio.h>
#include <queue>
using namespace std;

/*
���� : N * N(N <= 1000) ũ���� ������ ���� ������ W(W <= N)���� �־�����. (1, 1)����
(N, N)���� �̵��ϱ� ���� ��ٷ��� �ϴ� �ּ� �� ���� ���Ѵ�. ���� �ִ� ĭ���� �����¿�밢������
�̵� �����ϸ�, �������� ������ �����ϸ� ���� �ִ� ĭ���θ� �̵� �����ϴ�. �̵��� �ð��� �ɸ��� �ʴ´�.
���� �� ĭ���� �����¿�� 1�Ͽ� 1ĭ�� ����������.

�ذ� ��� : �켱 �� ���� ���������� BFS�� ���� �� ������ ���� �����ϴ� ������ ���Ѵ�.
�׸��� �Ű� ���� Ž���� �÷������� �̿��Ͽ� �̵� ������ ������ ã���� �ȴ�.

�ֿ� �˰��� : �׷��� �̷�, BFS, �Ķ��Ʈ��

��ó : ���縯�� 1ȸ G/5��
*/

char stone[1024][1024];
int dist[1024][1024], vis[1024][1024];
queue<pair<int, int>> q;
int dxy[8][2] = { {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1} };
int n;

int isvalid(int x, int y, int d) {
    if (x < 0 || y < 0 || x >= n || y >= n) return 0;
    if (vis[x][y]) return 0;
    if (stone[x][y] == '0' || dist[x][y] > d) return -1;
    return 1;
}

int cango(int day) {
    int x, y, xn, yn;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) vis[i][j] = 0;
    }
    while (q.size()) q.pop();
    q.push({ 0, 0 });
    vis[0][0] = 1;
    while (q.size()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for (int i = 0; i < 8; i++) {
            xn = x + dxy[i][0];
            yn = y + dxy[i][1];
            if (xn == n - 1 && yn == n - 1) return 1;
            if (isvalid(xn, yn, day) > 0) {
                q.push({ xn, yn });
                vis[xn][yn] = 1;
            }
        }
    }
    return 0;
}

int main(void) {
    int w, x, y, lo = 0, hi = 2048, mid;
    scanf("%d %d", &n, &w);
    for (int i = 0; i < w; i++) {
        scanf("%d %d", &x, &y);
        q.push({ x - 1, y - 1 });
        vis[x - 1][y - 1] = 1;
    }
    for (int i = 0; i < n; i++) {
        scanf("%s", stone[i]);
    }

    while (q.size()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for (int i = 0; i < 8; i += 2) {
            if (isvalid(x + dxy[i][0], y + dxy[i][1], hi)) {
                q.push({ x + dxy[i][0], y + dxy[i][1] });
                vis[x + dxy[i][0]][y + dxy[i][1]] = 1;
                dist[x + dxy[i][0]][y + dxy[i][1]] = dist[x][y] + 1;
            }
        }
    }

    while (lo < hi) {
        mid = (lo + hi) >> 1;
        if (cango(mid)) hi = mid;
        else lo = mid + 1;
    }
    cango(lo);
    printf("%d", lo == 2048 ? -1 : lo);
    return 0;
}