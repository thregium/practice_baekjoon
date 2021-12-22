#include <stdio.h>
#include <vector>
#include <queue>
#include <set>
#define INF 1012345678
using namespace std;

/*
문제 : N(N <= 500)개의 정점과 M(M <= 10000)개의 간선으로 이루어진 단방향 가중치 그래프에서 정점 s부터 d까지의 최단거리에
포함되는 경로를 제외한(동순위 포함) 경로 가운데 최단 경로의 가중치를 구한다. 그러한 경로가 없다면 -1을 출력한다.
한 정점 쌍끼리는 간선이 최대 1개이다.

해결 방법 : 처음에 간선을 받을 때 역방향 간선도 따로 만들어준다.
그리고 우선 s에서 d로 다익스트라를 통해 각 장점까지의 최단거리를 구한다. 최단거리를 구한 다음에는 d에서부터 역방향 간선을 통해
플러드필을 하며 최단거리에 속하는(해당 정점까지의 최단거리에 이 간선의 길이를 더한 것이 현재 정점까지의 최단거리와 같은 경우)
아직 방문하지 않은 정점이 나오면 셋에 넣고 이전 점으로 가서 다시 역방향 간선을 확인해 나간다.
이를 통해 셋에 저장된 간선들은 최단거리에 속하는 간선들이 된다.

이제 다시 s에서 d로 다익스트라를 해 나가며 최단거리를 구하되, 셋에 저장된 간선들이 나오면 넘어가도록 하면서 구하면 된다.
그때의 D의 최단거리가 무한대라면 답은 -1, 그 외에는 D의 최단거리가 된다.

주요 알고리즘 : 그래프 이론, 다익스트라, 역추적, 셋

출처 : Latin 2008 A번
*/

int vis[512], dist[512]; //방문 여부, 거리
vector<pair<int, int>> ed[512], edr[512]; //(목적지, 거리), 간선, 역방향 간선
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; //(거리, 목적지)
set<pair<int, int>> shst, nst; //최단 경로에 속하는 간선, 속하지 않는 간선

void dfs(int x) {
    //역추적을 통한 최단 경로에 속하는 간선 수집
    for (auto i : edr[x]) {
        if (shst.find(pair<int, int>(i.first, x)) != shst.end() || nst.find(pair<int, int>(i.first, x)) != nst.end()) continue;
        if (dist[i.first] + i.second == dist[x]) {
            shst.insert(pair<int, int>(i.first, x));
            dfs(i.first);
        }
        else nst.insert(pair<int, int>(i.first, x));
    }
}

void dijk(int n, int s) {
    //다익스트라를 통해 모든 정점으로의 거리를 구한다.
    int u, p;
    for (int i = 0; i < n; i++) {
        vis[i] = 0;
        dist[i] = INF;
    }
    dist[s] = 0;
    pq.push(pair<int, int>(0, s));
    while (pq.size()) {
        u = pq.top().second;
        p = pq.top().first;
        pq.pop();
        if (vis[u]) continue;
        else vis[u] = 1;
        for (auto i : ed[u]) {
            if (shst.find(pair<int, int>(u, i.first)) != shst.end()) continue;
            if (dist[u] + i.second < dist[i.first]) {
                pq.push(pair<int, int>(dist[u] + i.second, i.first));
                dist[i.first] = dist[u] + i.second;
            }
        }
    }
}

int main(void) {
    int n, m, s, d, u, v, p;
    //freopen("E:\\PS\\ICPC\\Latin America\\Latin\\2008\\testset_2008\\almost.in", "r", stdin);
    while (1) {
        scanf("%d %d", &n, &m);
        if (n == 0) break;
        scanf("%d %d", &s, &d);
        for (int i = 0; i < m; i++) {
            scanf("%d %d %d", &u, &v, &p);
            ed[u].push_back(pair<int, int>(v, p));
            edr[v].push_back(pair<int, int>(u, p));
        }

        dijk(n, s);
        dfs(d);
        dijk(n, s);
        printf("%d\n", dist[d] == INF ? -1 : dist[d]);

        for (int i = 0; i < n; i++) {
            ed[i].clear();
            edr[i].clear();
        }
        shst.clear();
        nst.clear();
    }
    return 0;
}