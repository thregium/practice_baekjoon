#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

/*
문제 : N(N <= 100000)개의 정점으로 이루어진 무방향 그래프가 있다. 이 그래프의 간선들을 2가지 색으로 칠해서 1번 정점에서 N번 정점으로
이동하며 어떤 경로를 선택하더라도 색을 변경하는 횟수를 최대한으로 한다면, 이때의 색 변경 횟수를 구한다.

해결 방법 : 이때의 색 변경 횟수는 1에서 N으로의 최단경로의 길이에서 1을 뺀 것과 같다.
최단 경로에서 옆으로 돌아가는 경로들이 존재하더라도 최단 경로의 색을 포함해서 칠해버리면 최단 경로의 색 변경 횟수 이상으로 색 변경 횟수가 늘어나기 때문이다.

주요 알고리즘 : 그래프 이론, BFS

출처 : PacNW 2019 C번/P번
*/

int vis[103000], dist[103000];
vector<int> edge[103000];
queue<int> q;

int bfs(int a, int b) {
    q.push(a);
    vis[a] = 1;
    while (q.size()) {
        a = q.front();
        q.pop();
        for (int i = 0; i < edge[a].size(); i++) {
            if (vis[edge[a][i]]) continue;
            q.push(edge[a][i]);
            dist[edge[a][i]] = dist[a] + 1;
            vis[edge[a][i]] = 1;
        }
    }
    return dist[b];
}

int main(void) {
    int n, m, a, b;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    printf("%d", bfs(1, n) - 1);
    return 0;
}