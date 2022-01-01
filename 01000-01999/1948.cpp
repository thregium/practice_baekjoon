#include <stdio.h>
#include <vector>
#include <queue>
#define INF 1012345678
using namespace std;

/*
문제 : N(N <= 10000)개의 정점과 M(M <= 100000)개의 간선으로 이루어진 DAG에서 각 간선마다 가중치(<= 10000, 자연수)가 주어질 때,
출발 정점에서 도착 정점으로의 최장 거리와 그러한 최장 거리에 속하는 간선의 개수를 구한다.

해결 방법 : 위상 정렬을 통해 출발 정점에서 각 정점으로의 최장 거리를 구할 수 있다. 그러한 거리를 구한 다음,
도착 정점에서 역방향 간선을 통해 가중치가 최장 거리의 차이와 같은 간선들의 개수를 세고 그 간선들을 이용해 탐색하면
센 간선들의 개수가 최장 거리에 속하는 간선의 개수가 된다.

주요 알고리즘 : 그래프 이론, 위상 정렬, 역추적
*/

int dist[10240], ins[10240], vis[10240];
int roadcount = 0;
vector<pair<int, int>> ed[10240], edr[10240];
queue<int> q;

void bfs(int x) {
    vis[x] = 1;
    dist[x] = 0;
    q.push(x);
    while (q.size()) {
        x = q.front();
        q.pop();
        for (auto i : ed[x]) {
            ins[i.first]--;
        }
        for (auto i : ed[x]) {
            if (dist[x] + i.second > dist[i.first]) dist[i.first] = dist[x] + i.second;
            if (ins[i.first] == 0) {
                if (!vis[i.first]) q.push(i.first);
                vis[i.first] = 1;
            }
        }
    }
}

void dfs(int x) {
    vis[x] = 1;
    for (auto i : edr[x]) {
        if (dist[i.first] + i.second == dist[x]) {
            roadcount++;
            if (!vis[i.first]) dfs(i.first);
        }
    }
}

int main(void) {
    int n, m, s, e, t;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &s, &e, &t);
        ed[s].push_back(pair<int, int>(e, t));
        edr[e].push_back(pair<int, int>(s, t));
        ins[e]++;
    }
    scanf("%d %d", &s, &e);
    bfs(s);
    for (int i = 1; i <= n; i++) vis[i] = 0;
    dfs(e);
    printf("%d\n%d", dist[e], roadcount);
    return 0;
}