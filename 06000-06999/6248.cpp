#include <stdio.h>
#include <vector>
#include <queue>
#define INF 1012345678
using namespace std;

/*
���� : N(N <= 1000)���� �������� �̷���� ���� ����ġ �׷������� ���� X�� ���� ���µ� �ɸ��� �ִܰŸ��� ���� �� ������
�ִܰŸ��� ���Ѵ�.

�ذ� ��� : ���� X���� �����ϴ� ���ͽ�Ʈ�� ������, X���� ����� �� �������� ���� �ִܰŸ��� ���� �� �� �ִ�.
���� �׷����̱� ������ X���� �����ϴ� �ִܰŸ��� ���� �� ������ ã�� �װ����� ���µ� �ɸ��� �ִܰŸ��� 2�谡 ���� �ȴ�.

�ֿ� �˰��� : �׷��� �̷�, ���ͽ�Ʈ��

��ó : USACO 2007O B4��
*/

int dist[1024];
vector<pair<int, int>> ed[1024];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main(void) {
    int n, m, x, a, b, t, r = 0;
    scanf("%d %d %d", &n, &m, &x);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &a, &b, &t);
        ed[a].push_back(pair<int, int>(b, t));
        ed[b].push_back(pair<int, int>(a, t));
    }
    for (int i = 1; i <= n; i++) dist[i] = INF;
    dist[x] = 0;
    pq.push(pair<int, int>(0, x));
    while (pq.size()) {
        x = pq.top().second;
        t = pq.top().first;
        pq.pop();
        for (auto i : ed[x]) {
            if (i.second + t < dist[i.first]) {
                pq.push(pair<int, int>(i.second + t, i.first));
                dist[i.first] = i.second + t;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (dist[i] > r) r = dist[i];
    }
    printf("%d", r * 2);
    return 0;
}