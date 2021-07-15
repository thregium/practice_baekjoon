#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;

/*
문제 : N(N <= 200000)개의 정점으로 이루어진 트리에서 M(M <= N)개의 정점에서 모두 같은 거리인 정점이 있는지 확인하고
있다면 그러한 정점 중 하나를 구한다.

해결 방법 : M개의 정점에서 BFS를 출발시킨다. 그리고 각 정점에는 방문한 출발지의 수를 저장해둔다.
확인하는 정점이 아직 방문하지 않은 정점인 경우에는 이전 정점의 출발지 수를 복사한 후 나머지는 평소대로 한다.
방문한 정점이라면 현재 출발지로부터의 거리와 저장된 거리가 같은지 확인한다. 다르다면 다른 정점을 살펴본다.
같다면 현재 정점의 출발지 수에 이전 정점의 출발지 수를 더하고 다른 정점을 살펴본다.
이를 전부 마친 뒤에는 출발 정점의 수가 M인 정점이 있는지 찾고 있다면 그 정점이 찾고자하는 점이고
없다면 그러한 점은 없는 것이다.

주요 알고리즘 : 그래프 이론, BFS, 트리

출처 : NWRRC 2019 E번
*/

int cnt[204800], dist[204800];
char dir[256], buff[64];
vector<int> ed[204800];
queue<int> q;

void bfs(void) {
    int x;
    while (q.size()) {
        x = q.front();
        q.pop();
        for (int i : ed[x]) {
            if (cnt[i]) {
                if (dist[i] == dist[x] + 1) cnt[i] += cnt[x];
                continue;
            }
            q.push(i);
            cnt[i] = cnt[x];
            dist[i] = dist[x] + 1;
        }
    }
}

int main(void) {
    int m, n, v, u;
    scanf("%d %d", &n, &m);
    for (int i = 1; i < n; i++) {
        scanf("%d %d", &v, &u);
        ed[v].push_back(u);
        ed[u].push_back(v);
    }
    for (int i = 1; i <= m; i++) {
        scanf("%d", &v);
        q.push(v);
        cnt[v] = 1;
    }
    bfs();
    for (int i = 1; i <= n; i++) {
        if (cnt[i] == m) {
            printf("YES\n%d", i);
            return 0;
        }
    }
    printf("NO");
    return 0;
}