#include <stdio.h>
#include <deque>
using namespace std;

/*
���� : R * C(R, C <= 1000) ũ���� ���ڿ��� ���̵��� �־�����.(h <= 10^9), ���⼭ �ִ� K(K <= R - 1) ĭ�� �ٸ��� ���� �� �ִٸ�
�����ϴ� ���� ���� ���̸� �ִ��� ���̷��� �� �� �����ϴ� ���� ���� ���̸� ���Ѵ�. �ٸ��� ĭ ���� �´ٸ� ���� ���� ���Ƶ� �ȴ�.
������� ���� �Ʒ����̰� �������� ���� �����̴�.

�ذ� ��� : �̺� Ž���� ���� �ش� ���̸� �������� ���� �� �ٸ��� Kĭ ���Ϸ� ���� �� �� �ִ��� Ȯ���� ����
�����ϴٸ� Ž�� ������ ��������, �Ұ����ϴٸ� �Ʒ������� ��ư��� ���� ã���� �ȴ�. �ٸ��� Kĭ ���Ϸ� �� �� �ִ�����
0-1 BFS�� ���� �� �Ʒ��� ĭ���� ����� �� ���� ĭ�� �� ���� �Ÿ��� ª�� ���� K �����̸� �ȴ�.
�Ÿ��� ��ǥ ���� ������ �� 1�� �����Ѵ�.

�ֿ� �˰��� : �׷��� �̷�, 0-1 BFS, �̺� Ž��

��ó : BAPC 2019P C��
*/

int maps[1024][1024], vis[1024][1024], dist[1024][1024];
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
deque<pair<int, int>> dq;

int isvalid(int r, int c, int x, int y) {
    if (x < 0 || y < 0 || x >= r || y >= c) return 0;
    if (vis[x][y]) return 0;
    return 1;
}

int bfs(int r, int c, int h, int k) {
    dq.clear();
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            vis[i][j] = 0;
            dist[i][j] = 0;
        }
    }
    for (int i = 0; i < c; i++) {
        vis[r - 1][i] = 1;
        if (maps[r - 1][i] >= h) {
            dq.push_front(pair<int, int>(r - 1, i));
        }
        else {
            dq.push_back(pair<int, int>(r - 1, i));
            dist[r - 1][i] = 1;
        }
    }

    int x, y, best = 123456789;
    while (dq.size()) {
        x = dq.front().first;
        y = dq.front().second;
        dq.pop_front();
        for (int i = 0; i < 4; i++) {
            if (!isvalid(r, c, x + dxy[i][0], y + dxy[i][1])) continue;
            vis[x + dxy[i][0]][y + dxy[i][1]] = 1;
            if (maps[x + dxy[i][0]][y + dxy[i][1]] >= h) {
                dist[x + dxy[i][0]][y + dxy[i][1]] = dist[x][y];
                dq.push_front(pair<int, int>(x + dxy[i][0], y + dxy[i][1]));
            }
            else {
                dist[x + dxy[i][0]][y + dxy[i][1]] = dist[x][y] + 1;
                dq.push_back(pair<int, int>(x + dxy[i][0], y + dxy[i][1]));
            }
        }
    }

    for (int i = 0; i < c; i++) {
        if (dist[0][i] < best) best = dist[0][i];
    }
    if (best <= k) return 1;
    else return 0;
}

int main(void) {
    int r, c, k, lo = 0, hi = 1012345678;
    scanf("%d %d %d", &r, &c, &k);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", &maps[i][j]);
        }
    }
    while (lo < hi) {
        if (bfs(r, c, (lo + hi + 1) >> 1, k)) {
            lo = ((lo + hi + 1) >> 1);
        }
        else {
            hi = ((lo + hi + 1) >> 1) - 1;
        }
    }
    printf("%d", lo);
    return 0;
}