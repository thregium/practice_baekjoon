#include <stdio.h>
#include <vector>
#include <queue>
#define INF 1012345678.0
using namespace std;

/*
���� : M(M <= 30)���� ���ð� �ִ�. �� ���� ���� P���� ���� �ְ�, �� ���� ���̴� D(D <= 100, �ڿ���)�̴�.
�̶�, N(N <= 8)���� ���а� �ְ�, �� ���и��� ���� ���� �� �ִ� ���� ��(<= 10)�� �־�����,
A�� ���ÿ��� B�� ���÷� �̵��ϴ� �� �ɸ��� �ð��� ���Ѵ�.
�� �̵��� �ɸ��� �ð��� D / ���� �������̴�.

�ذ� ��� : ���ͽ�Ʈ��� ��Ʈ����ŷ�� �̿��Ѵ�. �� ���� ����Ͽ����� ���θ� ������ �Բ� ���·� �����ϰ�
�ִܰŸ��� ���ϸ� �ȴ�.

�ֿ� �˰��� : �׷��� �̷�, ���ͽ�Ʈ��, ��Ʈ����ŷ

��ó : JDC 2005 D��
*/

int t[16], vis[32][256];
double dist[32][256];
vector<pair<int, int>> ed[32];
priority_queue<pair<double, pair<int, int>>, vector<pair<double, pair<int, int>>>, greater<>> pq;

/*
void track(int n, int x, int y, double d) {
    if (x == y) {
        if (d < res) res = d;
        return;
    }
    for (auto& i : ed[x]) {
        for (int j = 0; j < n; j++) {
            if (chk[j]) continue;
            chk[j] = 1;
            track(n, i.first, y, d + i.second / (double)t[j]);
            chk[j] = 0;
        }
    }
}
*/

int main(void) {
    int n, m, p, a, b, x, y, z;
    double res, d;
    while (1) {
        scanf("%d %d %d %d %d", &n, &m, &p, &a, &b);
        if (n == 0) break;
        for (int i = 0; i < n; i++) {
            scanf("%d", &t[i]);
        }
        for (int i = 0; i < p; i++) {
            scanf("%d %d %d", &x, &y, &z);
            ed[x].push_back({ y, z });
            ed[y].push_back({ x, z });
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 0; j < (1 << n); j++) {
                dist[i][j] = INF;
                vis[i][j] = 0;
            }
        }
        dist[a][0] = 0.0;

        pq.push({ 0.0, {a, 0} });
        while (pq.size()) {
            d = pq.top().first;
            x = pq.top().second.first;
            y = pq.top().second.second;
            pq.pop();
            if (vis[x][y]) continue;
            else vis[x][y] = 1;
            for (auto& i : ed[x]) {
                for (int j = 0; j < n; j++) {
                    if ((y >> j) & 1) continue;
                    if (dist[x][y] + i.second / (double)t[j] < dist[i.first][y ^ (1 << j)]) {
                        dist[i.first][y ^ (1 << j)] = dist[x][y] + i.second / (double)t[j];
                        pq.push({ dist[i.first][y ^ (1 << j)], {i.first, y ^ (1 << j)} });
                    }
                }
            }
        }

        res = INF;
        for (int i = 0; i < (1 << n); i++) {
            if (dist[b][i] < res) res = dist[b][i];
        }
        if (res >= INF - 1) printf("Impossible\n");
        else printf("%.9f\n", res);

        for (int i = 1; i <= m; i++) ed[i].clear();
    }
    return 0;
}