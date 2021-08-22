#include <stdio.h>
#include <vector>
#include <queue>
#define INF 123456789876543210
using namespace std;

/*
���� : N(N <= 100000)���� ������ M(M <= 500000)���� �������� �̷���� ���� ����ġ �׷������� K(K <= N)���� ��������
���� �ָ� ������ ������ �׵� �� ���� ����� K���� ���� �� �ϳ��� �Ÿ��� ���Ѵ�.

�ذ� ��� : �׷��� ������ ����� K���� �������� �����ϴ� ���ͽ�Ʈ�� ����ϸ� ���� ���� �� �ִ�.
��� ������ �Ÿ��� ���� ���� ���� �Ÿ��� �� ������ �� �Ÿ��� ����ϸ� ���� �ȴ�.

�ֿ� �˰��� : �׷��� �̷�, ���ͽ�Ʈ��

��ó : ȫ�ʹ� 2019 G��
*/

long long dist[103000];
vector<pair<int, int>> ed[103000];
priority_queue<pair<int, long long>, vector<pair<int, long long>>, greater<pair<int, long long>>> pq;

int main(void) {
    int n, m, k, u, v, far = -1;
    long long c, fdist = 0;
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %lld", &u, &v, &c);
        ed[v].push_back(pair<int, int>(u, c));
    }
    for (int i = 1; i <= n; i++) dist[i] = INF;
    for (int i = 0; i < k; i++) {
        scanf("%d", &u);
        pq.push(pair<int, long long>(u, 0));
    }
    while (pq.size()) {
        u = pq.top().first;
        c = pq.top().second;
        pq.pop();
        if (c >= dist[u]) continue;
        else dist[u] = c;
        for (auto i : ed[u]) {
            if (c + i.second < dist[i.first]) pq.push(pair<int, long long>(i.first, c + i.second));
        }
    }
    for (int i = 1; i <= n; i++) {
        if (dist[i] > fdist) {
            far = i;
            fdist = dist[i];
        }
    }
    if (far < 0) return 1;
    printf("%d\n%lld", far, fdist);
    return 0;
}