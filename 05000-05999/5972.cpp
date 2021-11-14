#include <stdio.h>
#include <vector>
#include <queue>
#define INF 1023456789
using namespace std;

/*
���� : N(N <= 50000)���� ������ M(M <= 50000)���� �������� �̷���� �׷������� 1�� �������� ����ؼ�
N�� �������� �̵��ϴ� �ִ� �Ÿ��� ���Ѵ�. �� ������ �Ÿ��� 0 �̻� 1000 ������ �����̴�.

�ذ� ��� : ���ͽ�Ʈ�� �˰����� ����Ѵ�.

�ֿ� �˰��� : �׷��� �̷�, ���ͽ�Ʈ��

��ó : USACO 2011M S2��
*/

int dist[51200];
vector<pair<int, int>> v[51200];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main(void) {
    int n, m, a, b, c, s, e;
    scanf("%d%d", &n, &m);
    //scanf("%d", &s);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &a, &b, &c);
        v[a].push_back(pair<int, int>(b, c));
        v[b].push_back(pair<int, int>(a, c));
    }
    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
    }
    //scanf("%d %d", &s, &e);
    pq.push(pair<int, int>(0, 1));
    while (pq.size()) {
        a = pq.top().second;
        b = pq.top().first;
        pq.pop();
        if (b < dist[a]) dist[a] = b;
        else continue;
        for (int i = 0; i < v[a].size(); i++) {
            if (b + v[a][i].second < dist[v[a][i].first]) pq.push(pair<int, int>(b + v[a][i].second, v[a][i].first));
        }
    }
    printf("%d", dist[n]);
    return 0;
}