#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

/*
문제 : 정점 N(N <= 300000)개인 가중치 없는 유향 그래프에서 정점 X에서 출발했을 때 최단거리가 K인 정점을 모두 찾는다.

해결 방법 : X에서 BFS를 하며 거리 배열을 따로 만들어 둔 다음 BFS가 끝나면 거리 배열을 살펴보며 거리가 K인 정점을 모두 출력하면 된다.

주요 알고리즘 : 그래프 이론, BFS
*/

int vis[327680], dist[327680];
vector<int> ed[327680];
queue<int> q;

void bfs(int x) {
    q.push(x);
    vis[x] = 1;
    while (q.size()) {
        x = q.front();
        q.pop();
        for (int i : ed[x]) {
            if (vis[i]) continue;
            vis[i] = 1;
            dist[i] = dist[x] + 1;
            q.push(i);
        }
    }
}

int main(void) {
    int n, m, k, x, a, b, c = 0;
    scanf("%d %d %d %d", &n, &m, &k, &x);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        ed[a].push_back(b);
    }

    bfs(x);
    for (int i = 1; i <= n; i++) {
        if (dist[i] == k) {
            printf("%d\n", i);
            c++;
        }
    }
    if (c == 0) printf("-1");
    return 0;
}