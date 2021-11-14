#include <stdio.h>
#define INF 1012345678

/*
문제 : N(N <= 250)개의 정점과 M개의 간선으로 이루어진 그래프가 주어진다. 각 간선은 가중치가 없고 단방향과
양방향 간선으로 나뉜다. K(K <= 30000)개의 쿼리에 응답한다.
두 정점 s, e가 주어지면 s에서 e로 이동하기 위해 최소 몇 개의 단방향 간선을 양방향 간선으로 바꾸어야 하는지 구한다.
단, 이동 불가능한 경우는 주어지지 않는다.

해결 방법 : 양방향 간선과 순방향 간선의 가중치를 0으로 두고, 역방향 간선의 가중치를 1로 둔 다음
플로이드-워셜 알고리즘을 이용해 모든 정점 쌍의 거리를 구한다. 이때, 자기 자신으로 이동하는 경로는 0으로 두어야 한다.
이렇게 되면 역방향 간선을 바꾼 횟수가 되고, 따라서 각 정점 쌍의 가중치가 각각의 답이 된다.

주요 알고리즘 : 그래프 이론, 플로이드-워셜

출처 : 연세대 2015 F번
*/

int dist[256][256];

int small(int a, int b) {
    return a < b ? a : b;
}

int main(void) {
    int n, m, u, v, b;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) dist[i][j] = INF;
        dist[i][i] = 0;
    }
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &b);
        dist[u][v] = 0;
        dist[v][u] = (!b);
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dist[i][j] = small(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    scanf("%d", &b);
    for (int i = 0; i < b; i++) {
        scanf("%d %d", &u, &v);
        printf("%d\n", dist[u][v]);
    }
    return 0;
}