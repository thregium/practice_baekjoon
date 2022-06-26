#include <stdio.h>
#include <vector>
#include <queue>
#define INF 1234567890987654321
using namespace std;

/*
���� : N(N <= 100000)���� ������ M(M <= 300000)���� �������� �̷���� ����� ����ġ(<= 100000) �׷�������
0�� �������� N - 1�� �������� N - 1�� ������ �����ϰ� ���� 0�� ������ �����鼭 ���� �ִܰŸ��� ���Ѵ�.
�� �� ���ٸ� -1�� ����Ѵ�.

�ذ� ��� : ������ ���� 0���� �ٲٰ� ������ 0�� �����鸸 ���鼭 ���ͽ�Ʈ�� �ϸ� �ȴ�.

�ֿ� �˰��� : �׷��� �̷�, ���ͽ�Ʈ��

��ó : ������ 2019 I��
*/

int a[103000], vis[103000];
long long dist[103000];
vector<pair<int, int>> ed[103000];
priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;

int main(void) {
    int n, m, x, y;
    long long d;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        dist[i] = INF;
    }
    a[n - 1] = 0;
    for (int i = 0; i < m; i++) {
        scanf("%d %d %lld", &x, &y, &d);
        if (a[x] || a[y]) continue;
        ed[x].push_back({ y, d });
        ed[y].push_back({ x, d });
    }
    
    dist[0] = 0;
    pq.push({ 0, 0 });
    while (pq.size()) {
        x = pq.top().second;
        d = pq.top().first;
        pq.pop();
        if (vis[x]) continue;
        else vis[x] = 1;
        for (auto& i : ed[x]) {
            if (d + i.second < dist[i.first]) {
                dist[i.first] = d + i.second;
                pq.push({ dist[i.first], i.first });
            }
        }
    }

    if (dist[n - 1] == INF) printf("-1");
    else printf("%lld", dist[n - 1]);
    return 0;
}