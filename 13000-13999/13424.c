#include <stdio.h>
#define INF 1012345678

/*
문제 : N(N <= 100)개의 정점을 가진 그래프에서 M개의 양방향 간선 각각에 대한 가중치가 주어질 때,
K(K <= 100)개의 정점에서의 거리 합이 가장 작은 정점 가운데 번호가 가장 작은 정점을 찾는다.

해결 방법 : 플로이드-워셜 알고리즘을 이용하여 각 정점 쌍 사이의 거리를 구하고, 각 정점을 확인하면서
거리 합을 구한 다음 가장 작은 정점을 찾으면 된다.

주요 알고리즘 : 그래프 이론, 플로이드-워셜

출처 : 국민대 2016 L번
*/

int dist[128][128], room[128];

int small(int a, int b) {
    return a < b ? a : b;
}

int main(void) {
    int t, n, m, k, a, b, c, best = 0, bn = 0;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) dist[i][j] = INF;
            dist[i][i] = 0;
        }
        for (int i = 0; i < m; i++) {
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
        best = INF, bn = -1;
        scanf("%d", &k);
        for (int i = 0; i < k; i++) {
            scanf("%d", &room[i]);
        }
        for (int i = 1; i <= n; i++) {
            a = 0;
            for (int j = 0; j < k; j++) {
                a += dist[i][room[j]];
            }
            if (a < best) {
                best = a;
                bn = i;
            }
        }
        if (bn < 0) return 1;
        printf("%d\n", bn);
    }
    return 0;
}