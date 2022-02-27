#include <stdio.h>
#include <vector>
#include <queue>
#define INF 1234567890987654321
using namespace std;

/*
���� : N(N <= 10000)���� ������ M(M <= 50000)���� �������� �̷���� ����� ����ġ(<= 10^6) �׷�������
K(K <= 20)�� ������ ������ ����ġ�� 0���� ���� �� �ִٸ� 1�� �������� N�� ���������� �ִܰŸ��� ���Ѵ�.
��, �׻� N�� ������ ���� ������ ��츸 �־�����.

�ذ� ��� : �� ������ ������ ����ġ�� 0���� ���� Ƚ������ ���� ���� ���ͽ�Ʈ�� �ϸ� �ȴ�.

�ֿ� �˰��� : �׷��� �̷�, ���ͽ�Ʈ��

��ó : USACO 2009F G3��
*/

char vis[10240][24];
long long dist[10240][24];

vector<pair<int, int>> ed[10240];
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
    greater<pair<int, pair<int, int>>>> pq;

int main(void) {
    int n, m, k, a, b, t;
    long long r = INF;
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &a, &b, &t);
        ed[a].push_back(pair<int, int>(b, t));
        ed[b].push_back(pair<int, int>(a, t));
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= k; j++) dist[i][j] = INF;
    }
    dist[1][0] = 0;
    pq.push(make_pair(0, make_pair(1, 0)));
    while (pq.size()) {
        t = pq.top().first;
        a = pq.top().second.first;
        b = pq.top().second.second;
        pq.pop();
        if (vis[a][b]) continue;
        else vis[a][b] = 1;
        for (auto& i : ed[a]) {
            if (b < k && dist[a][b] < dist[i.first][b + 1]) {
                dist[i.first][b + 1] = dist[a][b];
                pq.push(make_pair(dist[i.first][b + 1], make_pair(i.first, b + 1)));
            }
            if (dist[a][b] + i.second < dist[i.first][b]) {
                dist[i.first][b] = dist[a][b] + i.second;
                pq.push(make_pair(dist[i.first][b], make_pair(i.first, b)));
            }
        }
    }

    for (int i = 0; i <= k; i++) {
        if (dist[n][i] < r) r = dist[n][i];
    }
    printf("%lld", r);
    return 0;
}