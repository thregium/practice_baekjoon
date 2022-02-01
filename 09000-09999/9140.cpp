#include <stdio.h>
#include <vector>
#include <queue>
#define INF 1012345678

/*
���� : N(N <= 10000)���� ������ M(M <= 100000)���� �������� �̷���� ����� ����ġ(<= 1000, �ڿ���)
�׷������� S�� �������� C�� �������� �̵��ϴ� �ִ� �Ÿ��� ���Ѵ�.

�ذ� ��� : ���ͽ�Ʈ�� �˰����� �̿��Ѵ�.

�ֿ� �˰��� : �׷��� �̷�, ���ͽ�Ʈ��

��ó : CTU 2001 F��
*/

char vis[10240];
int dist[10240];
std::vector<std::pair<int, int>> ed[10240];
std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
    std::greater<std::pair<int, int>>> pq;

int main(void) {
    int n, m, s, c, a, b, v;
    //freopen("E:\\PS\\ICPC\\Europe\\CTU\\2001\\f.in", "r", stdin);
    //freopen("E:\\PS\\ICPC\\Europe\\CTU\\2001\\f_t.out", "w", stdout);
    while (1) {
        scanf("%d %d %d %d", &n, &m, &s, &c);
        if (n == 0) break;
        for (int i = 1; i <= n; i++) {
            ed[i].clear();
            vis[i] = 0;
            dist[i] = INF;
        }

        for (int i = 0; i < m; i++) {
            scanf("%d %d %d", &a, &b, &v);
            ed[a].push_back(std::pair<int, int>(b, v));
            ed[b].push_back(std::pair<int, int>(a, v));
        }
        dist[s] = 0;
        pq.push(std::pair<int, int>(0, s));
        while (pq.size()) {
            s = pq.top().second;
            v = pq.top().first;
            pq.pop();
            if (vis[s]) continue;
            else vis[s] = 1;
            for (auto &i : ed[s]) {
                if (!vis[i.first] && i.second + v < dist[i.first]) {
                    dist[i.first] = i.second + v;
                    pq.push(std::pair<int, int>(i.second + v, i.first));
                }
            }
        }
        printf("%d\n", dist[c]);
    }
    return 0;
}