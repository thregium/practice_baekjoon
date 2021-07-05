#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <queue>
#define INF 1012345678
using namespace std;

/*
문제 : 정점 N(N <= 2000)개, 간선 M(M <= 50000)개인 무향 가중치 그래프에서 정점 S에서 출발해 G-H를 잇는 간선을 지나는
최단경로가 있는 정점을 C(C <= 100)개의 정점 중에서 모두 찾는다. 이를 T(T<= 100)회 반복한다. 각 간선의 가중치는 1000 이하이다.

해결 방법 : 모든 정점들을 입력받은 다음 각 간선의 가중치를 2배로 늘린다. 그 다음 G-H를 잇는 간선의 가중치는 1 줄인다.
그렇게 되면 S에서 출발해 최단거리로 G-H를 지나는(또는 최단거리 중 하나인) 모든 정점들은 가중치가 홀수가 되고
나머지 정점들은 가중치가 짝수가 된다. 그 상태에서 다익스트라를 돌린 후 가중치가 홀수인 정점들을 보면 된다.

주요 알고리즘 : 그래프 이론, 다익스트라

출처 : BAPC 2013 D번
*/

int dist[2048], cand[128], res[128];
vector<pair<int, int>> ed[2048];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int t, n, m, c, s, g, h, a, b, d;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d %d %d", &n, &m, &c);
        scanf("%d %d %d", &s, &g, &h);
        for (int i = 0; i < m; i++) {
            scanf("%d %d %d", &a, &b, &d);
            if ((a == g && b == h) || (a == h && b == g)) {
                ed[a].push_back(pair<int, int>(d * 2 - 1, b));
                ed[b].push_back(pair<int, int>(d * 2 - 1, a));
            }
            else {
                ed[a].push_back(pair<int, int>(d * 2, b));
                ed[b].push_back(pair<int, int>(d * 2, a));
            }
        }
        for (int i = 0; i < c; i++) {
            scanf("%d", &cand[i]);
        }

        b = 0;
        for (int i = 1; i <= n; i++) dist[i] = INF;
        pq.push(pair<int, int>(0, s));
        while (pq.size()) {
            a = pq.top().second;
            d = pq.top().first;
            pq.pop();
            if (d >= dist[a]) continue;
            dist[a] = d;
            for (int i = 0; i < ed[a].size(); i++) {
                pq.push(pair<int, int>(ed[a][i].first + d, ed[a][i].second));
            }
        }
        for (int i = 0; i < c; i++) {
            if (dist[cand[i]] == INF) continue;
            if (dist[cand[i]] & 1) res[b++] = cand[i];
        }
        qsort(res, b, sizeof(int), cmp1);
        for (int i = 0; i < b; i++) {
            printf("%d ", res[i]);
        }
        printf("\n");

        for (int i = 1; i <= n; i++) ed[i].clear();
    }
    return 0;
}