#include <stdio.h>
#include <deque>
#include <tuple>
#define INF 1012345678
using namespace std;

/*
���� : N * N(N <= 100) ũ���� ���ڿ��� A�� B ���̸� �̵��� ��, 'x'�� ��ġ�� �ʰ� �̵��ϴ� ��� ���
���� ���� ȸ���� ȸ�� ���� ���Ѵ�. �׻� �̵� ������ ��츸 �־�����.

�ذ� ��� : 0-1 BFS�� ���� 'A'���� ����ؼ� �� ĭ�� ���⸶�� �ּ� ȸ�� Ƚ���� ���Ѵ�.
'B'�� �������� ���� ȸ�� ���� ����ϸ� �ȴ�.

�ֿ� �˰��� : �׷��� �̷�, 0-1BFS

��ó : USACO 2007Q S2��
*/

char mp[128][128], vis[128][128][4];
int dist[128][128][4];
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
int h, w;
deque<tuple<int, int, int>> dq;

int small(int a, int b) {
    return a < b ? a : b;
}

int isvalid(int x, int y, int d) {
    if (x < 0 || y < 0 || x >= h || y >= w) return 0;
    if (mp[x][y] == 'x' || vis[x][y][d]) return 0;
    return 1;
}

int bfs(void) {
    int x = -1, y = -1, d, a = -1, b = -1;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (mp[i][j] == 'A') {
                x = i; //A�� ã�Ƽ� A�� ��ġ�� �����Ѵ�.
                y = j;
                a = i;
                b = j;
            }
        }
    }
    if (x < 0) return -1;
    for (int i = 0; i < 4; i++) {
        dist[x][y][i] = 0; //A�� �ִ� ���� �Ÿ��� 0���� �ʱ�ȭ�Ѵ�.
        dq.push_back(make_tuple(x, y, i));
    }

    while (dq.size()) {
        x = get<0>(dq.front());
        y = get<1>(dq.front());
        d = get<2>(dq.front());
        dq.pop_front();
        vis[x][y][d] = 1;
        if (mp[x][y] == 'B' && !(a == x && b == y)) {
            return dist[x][y][d]; //B�� ������ �װ������� �Ÿ��� ��ȯ�Ѵ�.
        }

        if (isvalid(x + dxy[d][0], y + dxy[d][1], d)) {
            //����
            dq.push_front(make_tuple(x + dxy[d][0], y + dxy[d][1], d));
            dist[x + dxy[d][0]][y + dxy[d][1]][d] = small(dist[x + dxy[d][0]][y + dxy[d][1]][d], dist[x][y][d]);
        }
        if (isvalid(x, y, (d + 3) & 3)) {
            //��ȸ��
            dq.push_back(make_tuple(x, y, (d + 3) & 3));
            dist[x][y][(d + 3) & 3] = small(dist[x][y][(d + 3) & 3], dist[x][y][d] + 1);
        }
        if (isvalid(x, y, (d + 1) & 3)) {
            //��ȸ��
            dq.push_back(make_tuple(x, y, (d + 1) & 3));
            dist[x][y][(d + 1) & 3] = small(dist[x][y][(d + 1) & 3], dist[x][y][d] + 1);
        }
        //������ ȸ�� �� �����̹Ƿ� ������ �ʿ䰡 ����.
    }
    return -1;
}

int main(void) {
    scanf("%d", &h);
    w = h;
    for (int i = 0; i < h; i++) {
        scanf("%s", mp[i]);
        for (int j = 0; j < w; j++) {
            for (int k = 0; k < 4; k++) dist[i][j][k] = INF; //���� �Ÿ��� ���� ���Ѵ�� �ʱ�ȭ�Ѵ�.
        }
    }
    printf("%d", bfs());
    return 0;
}