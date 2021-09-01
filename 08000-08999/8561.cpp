#include <stdio.h>
#include <vector>
#include <queue>
#define INF 1012345678
using namespace std;

/*
���� : N(N <= 1000)���� ������ M(M <= 30000)���� �������� �̷���� ���� ����ġ ����׷����� �ִ�.
�� �׷������� K(K <= N)���� ���� ��ο��� ���� �ָ� ������ ������ ���� ����� K���� �������� �Ÿ��� ���Ѵ�.

�ذ� ��� : ���ͽ�Ʈ�� �����ϵ� ���� ������ K���� �������� �����ϸ� �ȴ�.
��� ������ �Ÿ��� ���������� ���� �Ÿ��� �� ������ �Ÿ��� ���Ѵ�.

�ֿ� �˰��� : �׷��� �̷�, ���ͽ�Ʈ��

��ó : PA 2001 3-1��
*/

int dist[1024];
vector<pair<int, int>> ed[1024];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main(void) {
    int n, k, m, x, y, d, r = 0;
    scanf("%d %d %d", &n, &k, &m);
    for (int i = 0; i < k; i++) {
        scanf("%d", &x);
        pq.push(pair<int, int>(0, x));
    }
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &x, &y, &d);
        ed[x].push_back(pair<int, int>(d, y));
        ed[y].push_back(pair<int, int>(d, x));
    }
    for (int i = 1; i <= n; i++) dist[i] = INF;
    while (pq.size()) {
        d = pq.top().first;
        x = pq.top().second;
        pq.pop();
        if (d < dist[x]) dist[x] = d;
        else continue;
        for (auto i : ed[x]) {
            if (dist[x] + i.first < dist[i.second]) {
                pq.push(pair<int, int>(dist[x] + i.first, i.second));
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (dist[i] > r) r = dist[i];
    }
    printf("%d", r);
    return 0;
}