#include <stdio.h>
#include <vector>
#include <queue>
#define INF 1012345678
#define INNER pair<int, pair<int, int>>
using namespace std;

/*
���� : N(N <= 30)���� ���ð� �ְ�, �� ���� ���� M���� ����� ���η� �̾��� �ִ�.
�� ���� ���� ������ ������ ���ƾ� 1����. �� ������ ���̴� 100 ����, �ӵ� ������ 30 ���ϴ�.
ù ���ø� ����� ������ �ӵ� 1���� �����ϰ�, �� ���ÿ��� �ӵ��� 1�� ���̰ų� ���� �� �ִ�.
�׸��� ������ ���Դ� ���÷� ���ư��� ���� �Ұ����ϴ�.
�� ���ǿ��� ���� S���� ���� T�� �̵��ϸ鼭, T���� �ӵ� 1�� ������ ����� �ִ� �� ���ϰ�,
�ִٸ� �� �� ���� �ӵ��� ���� ���� �̵� �ð��� ���Ѵ�.

�ذ� ��� : ���ͽ�Ʈ�� ���� ���� ���� �� �ִ�. ������ ������ ��ȣ�� ���� �ӵ���
������ ���¿� ���� ������ ������ �ȴ�. ������ �����ϹǷ� ������ �����Ѵ�.

�ֿ� �˰��� : �׷��� �̷�, ���ͽ�Ʈ��, DP?

��ó : JDC 2009 D��
*/

int vis[32][32][32]; //vertix, speed, last
double dist[32][32][32];
vector<INNER> ed[32]; //dest, dist, limit
priority_queue<pair<double, INNER>, vector<pair<double, INNER>>, greater<pair<double, INNER>>> pq;
//dist, vertix, speed, last

int main(void) {
    int n, m, s, g, x, y, d, c;
    double xd, res;
    INNER in;
    while (1) {
        for (int i = 0; i < 32; i++) {
            for (int j = 0; j < 32; j++) {
                for (int k = 0; k < 32; k++) {
                    vis[i][j][k] = 0;
                    dist[i][j][k] = INF;
                }
            }
            ed[i].clear();
        }

        scanf("%d %d", &n, &m);
        if (n == 0) break;
        scanf("%d %d", &s, &g);
        for (int i = 0; i < m; i++) {
            scanf("%d %d %d %d", &x, &y, &d, &c);
            ed[x].push_back(make_pair(y, make_pair(d, c)));
            ed[y].push_back(make_pair(x, make_pair(d, c)));
        }

        pq.push(make_pair(0, make_pair(s, make_pair(1, 31))));
        dist[s][1][31] = 0;
        while (pq.size()) {
            xd = pq.top().first; //dist
            in = pq.top().second;
            x = in.first; //vert
            c = in.second.first; //spd
            y = in.second.second; //last
            pq.pop();
            if (vis[x][c][y]) continue;
            else vis[x][c][y] = 1;

            for (INNER& i : ed[x]) {
                if (y == i.first) continue;
                if (y != 31 && i.second.second >= c + 1 && dist[i.first][c + 1][x] >
                    dist[x][c][y] + i.second.first / (c + 1.0)) {
                    dist[i.first][c + 1][x] = dist[x][c][y] + i.second.first / (c + 1.0);
                    pq.push(make_pair(dist[i.first][c + 1][x], make_pair(i.first, make_pair(c + 1, x))));
                }
                if (i.second.second >= c && dist[i.first][c][x] >
                    dist[x][c][y] + i.second.first / (double)c) {
                    dist[i.first][c][x] = dist[x][c][y] + i.second.first / (double)c;
                    pq.push(make_pair(dist[i.first][c][x], make_pair(i.first, make_pair(c, x))));
                }
                if (y != 31 && c > 1 && i.second.second >= c - 1 && dist[i.first][c - 1][x] >
                    dist[x][c][y] + i.second.first / (c - 1.0)) {
                    dist[i.first][c - 1][x] = dist[x][c][y] + i.second.first / (c - 1.0);
                    pq.push(make_pair(dist[i.first][c - 1][x], make_pair(i.first, make_pair(c - 1, x))));
                }
            }
        }

        res = INF;
        for (int i = 0; i <= 31; i++) {
            if (dist[g][1][i] < res) res = dist[g][1][i];
        }
        if (res == INF) printf("unreachable\n");
        else printf("%.9f\n", res);
    }
    return 0;
}