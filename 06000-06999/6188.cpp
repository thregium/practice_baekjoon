#include <stdio.h>
#include <queue>
using namespace std;

/*
문제 : 1번 정점을 루트로 갖는 이진 트리에서 각 정점별로 자식 노드들이 주어질 때, 각 정점마다 차수를 구한다.

해결 방법 : 1번 정점을 시작점으로 하는 BFS를 한 다음, 각 정점까지의 최단거리에 1을 더한 값을 출력하면 된다.

주요 알고리즘 : 그래프 이론, BFS

출처 : USACO 2008O B3번
*/

int vis[103000], dist[103000], ed[103000][2];
queue<int> q;

void bfs(int x, int d) {
    vis[x] = 1;
    q.push(x);
    while (q.size()) {
        x = q.front();
        d = dist[x];
        q.pop();
        if (!vis[ed[x][0]]) {
            q.push(ed[x][0]);
            dist[ed[x][0]] = dist[x] + 1;
            vis[ed[x][0]] = 1;
        }
        if (!vis[ed[x][1]]) {
            q.push(ed[x][1]);
            dist[ed[x][1]] = dist[x] + 1;
            vis[ed[x][1]] = 1;
        }
    }
}

int main(void) {
    int n, c, e, b1, b2;
    scanf("%d %d", &n, &c);
    for (int i = 0; i < c; i++) {
        scanf("%d %d %d", &e, &b1, &b2);
        ed[e][0] = b1;
        ed[e][1] = b2;
    }
    bfs(1, 0);
    for (int i = 1; i <= n; i++) {
        printf("%d\n", dist[i] + 1);
    }
    return 0;
}