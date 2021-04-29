#include <stdio.h>
#include <queue>
#include <tuple>
using namespace std;

/*
���� : N * N(N <= 50) ���ڿ��� 0�� ĭ���� ����ؼ� K + 1(K <= 5)�� ĭ���� �̵��ϴµ� �ɸ��� �ּ� �ð��� ���Ѵ�.
��, 0���� K���� ��� �ڿ����� ������� ������ �ϸ�, ���� ���̳� #�� ĭ���� �̵��� �� ����.
����, ������ �̵��� �������� +-1��ŭ�� ���ο� ������ �� �� �ִ�. �׸���, ������ ������ 0, 0�̾�� �Ѵ�.

�ذ� ��� : ť�� ��ġ�� �Բ� ������ ���ݱ��� ���� ����, ��������� �Ÿ��� ���� ����ִ´�.
����, �湮 �迭���� ���� ����� �� �ð��� ������ �������� ���� ����ִ´�. �̶�, ������ �ִ� 9�����ۿ� �� �� �����Ƿ�
(1 ~ 10���� ������� ���ϸ� 50�� �Ѿ�� ������), �湮 �迭�� �� ���� ���� ���ϴ��� �ִ� �� 600���ۿ� ���� �ʴ´�.
������ ����� �Ǿ�� �ϹǷ� �湮 �迭������ 9�� 10�� �����־�� �Ѵ�.
BFS�� �� ������ ������ ��ǥ�� 2�� for������ ������ �������� ���� -1 ~ +1 ������ ���� ���� ���� ������ ���� ���� ��ǥ�� �ϸ� �ȴ�.
��, ���� ã�� ���� ã�� ��� ���ݱ����� ���� 1�� ���ϰ�, K + 1�� ���� ��� Ž���� �����Ѵ�. �� �ܿ��� �Ϲ����� BFSó�� �ϸ� �ȴ�.

�ֿ� �˰��� : �׷��� �̷�, BFS, ����

��ó : BAPC 2020P K��
*/

char grid[64][64], vis[50][50][20][20][6];
int r, c, k;
queue<tuple<int, int, int, int, int, int>> q; //x, y, dx, dy, dist, warn

int isvalid(int x, int y, int dx, int dy, int warn) {
    if (x < 0 || y < 0 || x >= r || y >= c) return 0;
    if (vis[x][y][10 + dx][10 + dy][warn] || grid[x][y] == '#') return 0;
    return 1;
}

int bfs(int x, int y) {
    int dx, dy, dist, warn;
    q.push(make_tuple(x, y, 0, 0, 0, 0));
    vis[x][y][10][10][0] = 1;
    while (q.size()) {
        x = get<0>(q.front());
        y = get<1>(q.front());
        dx = get<2>(q.front());
        dy = get<3>(q.front());
        dist = get<4>(q.front());
        warn = get<5>(q.front());
        q.pop();
        if (grid[x][y] - '0' == k + 1 && warn == k && dx == 0 && dy == 0) {
            //���� ����
            return dist;
        }
        else if (grid[x][y] - '0' - 1 == warn && grid[x][y] - '0' <= k) warn++; //���� ã�� ���� ã�� ���
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if (isvalid(x + dx + i, y + dy + j, dx + i, dy + j, warn)) {
                    q.push(make_tuple(x + dx + i, y + dy + j, dx + i, dy + j, dist + 1, warn));
                    vis[x + dx + i][y + dy + j][10 + dx + i][10 + dy + j][warn] = 1;
                }
            }
        }
    }
    return -1; //���� ã�� ���� ���
}

int main(void) {
    int x = 0, y = 0, res;
    scanf("%d %d %d", &r, &c, &k);
    for (int i = 0; i < r; i++) {
        scanf("%s", grid[i]);
        for (int j = 0; j < c; j++) {
            if (grid[i][j] == '0') {
                x = i;
                y = j;
            }
        }
    }
    res = bfs(x, y); //0���� ����
    if (res < 0) printf("impossible");
    else printf("%d", res);
    return 0;
}