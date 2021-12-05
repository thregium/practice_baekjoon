#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

/*
문제 : N(N <= 20000)개의 정점과 M(M <= 50000)개의 양방향 간선으로 이루어진 그래프에서 1번 정점과 가장 멀리 떨어진 정점들의
가장 번호가 작은 정점의 번호, 1번 정점과의 거리, 그러한 정점의 개수를 구한다. 그래프는 연결 그래프이다.

해결 방법 : BFS를 통해 1번 정점에서 각 정점으로의 거리를 구한 다음, 가장 멀리 떨어진 정점들의 정보를 찾아 나가면 된다.

주요 알고리즘 : 그래프 이론, BFS

출처 : USACO 2009O S1번
*/

int vis[20480], dist[20480];
vector<int> ed[20480];
queue<int> q;

void bfs(int x) {
    vis[x] = 1;
    q.push(x);
    while (q.size()) {
        x = q.front();
        q.pop();
        for (int i : ed[x]) {
            if (!vis[i]) {
                vis[i] = 1;
                dist[i] = dist[x] + 1;
                q.push(i);
            }
        }
    }
}

int main(void) {
    int n, m, a, b, c;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        ed[a].push_back(b);
        ed[b].push_back(a);
    }
    bfs(1);
    a = -1, b = -1, c = -1;
    for (int i = 1; i <= n; i++) {
        if (dist[i] > b) {
            b = dist[i];
            a = i;
            c = 1;
        }
        else if (dist[i] == b) c++;
    }
    if (a < 0) return 1;
    printf("%d %d %d", a, b, c);
    return 0;
}