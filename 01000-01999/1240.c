#include <stdio.h>
#define INF 1012345678

/*
문제 : N(N <= 1000)개의 정점으로 이루어진 트리의 각 간선과 가중치가 주어질 때, M(M <= 1000)개의 정점 쌍 사이 거리를 출력한다.

해결 방법 : 플로이드-워셜 알고리즘을 이용해 모든 정점 쌍의 거리를 구하고 각 정점 쌍을 입력받을 때 마다 거리를 출력하면 된다.

주요 알고리즘 : 그래프 이론, 플로이드-워셜
*/

int dist[1024][1024];

int small(int a, int b) {
    return a < b ? a : b;
}

int main(void) {
    int n, m, a, b, c;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) dist[i][j] = INF;
        dist[i][i] = 0;
    }
    for (int i = 1; i < n; i++) {
        scanf("%d %d %d", &a, &b, &c);
        dist[a][b] = c;
        dist[b][a] = c;
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dist[i][j] = small(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        printf("%d\n", dist[a][b]);
    }
    return 0;
}