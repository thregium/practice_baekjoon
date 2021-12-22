#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 10000)개의 정점과 P(P <= 100000)개의 간선으로 이루어진 양방향 가중치 연결 그래프가 주어진다.
이때, 이 그래프의 한 정점에서 N - 1개의 간선만을 사용해 한 정점에서 모든 정점으로 이동 후 돌아오는 비용을 최소로 하려고 한다.
각 정점과 간선을 방문시 드는 비용이 주어질 때, 해당 이동시 최소 비용을 구한다.

해결 방법 : 최적의 이동 경로를 생각해본다. 그러한 경우는 간선이 N - 1개이므로 스패닝 트리의 형태를 할 것이고,
각 정점을 방문한 횟수는 차수 또는 차수 + 1(시작 정점인 경우)일 것이다. 또한, 각 간선을 이동한 횟수는 모두 2회씩이 된다.
여기서 위 내용을 이용해 간선의 가중치를 (원래 간선의 가중치 * 2 + 양쪽 정점의 가중치)로 두면 최소 스패닝 트리를 통해
그러한 스패닝 트리를 구할 수 있다. 시작 정점은 가장 가중치가 작은 정점으로 두면 된다.

주요 알고리즘 : 그래프 이론, MST

출처 : USACO 2008N G2번
*/

int road[103000][3], cost[10240], g[10240];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int find(int x) {
    if (!g[x]) return x;
    else return g[x] = find(g[x]);
}

void uni(int x, int y) {
    if (find(x) == find(y)) return;
    g[find(y)] = find(x);
}

int main(void) {
    int n, p, r = 0;
    scanf("%d %d", &n, &p);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &cost[i]);
    }
    for (int i = 0; i < p; i++) {
        scanf("%d %d %d", &road[i][1], &road[i][2], &road[i][0]);
        road[i][0] <<= 1;
        road[i][0] += cost[road[i][1]] + cost[road[i][2]];
    }
    qsort(road, p, sizeof(int) * 3, cmp1);
    for (int i = 0; i < p; i++) {
        if (find(road[i][1]) != find(road[i][2])) {
            uni(road[i][1], road[i][2]);
            r += road[i][0];
        }
    }
    qsort(cost + 1, n, sizeof(int), cmp1);
    r += cost[1];
    printf("%d", r);
    return 0;
}