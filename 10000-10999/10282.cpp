#include <stdio.h>
#include <vector>
#include <queue>
#define INF 1012345678
using namespace std;

/*
���� : N(N <= 10000)���� ������ D(D <= 100000)���� �������� �̷���� ����ġ ���� �׷������� Ư���� ���� C���� ����Ͽ� ���� ������
������ ���� �� �� ���� �� �������� �Ÿ��� ���Ѵ�.

�ذ� ��� : ���ͽ�Ʈ�� ���� ���������� ���� ������ ���� ���� ���� �� ���� �Ÿ��� ���� �� �ִ�.

�ֿ� �˰��� : �׷��� �̷�, ���ͽ�Ʈ��

��ó : BAPC 2014P B��
*/

int dist[10240];
vector<pair<int, int>> ed[10240];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main(void) {
    int t, n, d, c, a, b, s, r, far;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d %d %d", &n, &d, &c);
        for (int i = 0; i < d; i++) {
            scanf("%d %d %d", &a, &b, &s);
            ed[b].push_back(pair<int, int>(s, a));
        }
        for (int i = 1; i <= n; i++) dist[i] = INF;
        r = 0;
        far = 0;
        pq.push(pair<int, int>(0, c));
        while (pq.size()) {
            a = pq.top().second;
            s = pq.top().first;
            pq.pop();
            if (s >= dist[a]) continue;
            dist[a] = s;
            r++;
            far = s;
            for (auto e : ed[a]) {
                pq.push(pair<int, int>(e.first + s, e.second));
            }
        }
        printf("%d %d\n", r, far);
        for (int i = 1; i <= n; i++) ed[i].clear();
    }
    return 0;
}