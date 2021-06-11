#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

/*
문제 : N(N <= 100000)개의 정점으로 이루어진 트리에서 (두 정점 사이의 경로의 거리) - (그 경로에서 가장 긴 간선의 길이)의 값을 구한다.

해결 방법 : 두 정점 사이의 거리를 플러드필을 통해 구한 다음(트리이므로 다익스트라 등이 필요 없음), 역추적을 통해
정점 사이 경로를 확인하며 가장 긴 간선의 길이를 구한다.

주요 알고리즘 : 그래프 이론, 플러드필, 역추적

출처 : 정올 2018 초3/중2번
*/

int vis[103000], dist[103000];
vector<pair<int, int>> ed[103000];
queue<int> q;

int bfs(int x, int y) {
    int s = x, e = y, longest = 0;
    q.push(x);
    vis[x] = 1;
    while (q.size()) {
        x = q.front();
        q.pop();
        for (int i = 0; i < ed[x].size(); i++) {
            if (vis[ed[x][i].first]) continue;
            vis[ed[x][i].first] = 1;
            dist[ed[x][i].first] = dist[x] + ed[x][i].second;
            q.push(ed[x][i].first);
        }
    }

    while (y != s) {
        for (int i = 0; i < ed[y].size(); i++) {
            if (dist[ed[y][i].first] == dist[y] - ed[y][i].second) {
                if (ed[y][i].second > longest) longest = ed[y][i].second;
                y = ed[y][i].first;
                break;
            }
        }
    }
    return dist[e] - longest;
}

int main(void) {
    int n, x, y, a, b, l;
    scanf("%d %d %d", &n, &x, &y);
    for (int i = 1; i < n; i++) {
        scanf("%d %d %d", &a, &b, &l);
        ed[a].push_back(pair<int, int>(b, l));
        ed[b].push_back(pair<int, int>(a, l));
    }
    printf("%d", bfs(x, y));
    return 0;
}