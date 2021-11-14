#include <stdio.h>
#define INF 1012345678

/*
문제 : N(N <= 100)개의 정점으로 이루어진 연결 그래프에서 모든 정점과의 거리 합이 가장 짧은 두 정점을 찾아서
그 두 정점에서 모든 정점까지의 거리 합 * 2와 그 두 정점을 출력한다. 여러 가지인 경우 사전순으로 빠른 것을 출력한다.

해결 방법 : 플로이드-워셜 알고리즘을 이용하여 모든 정점 쌍 사이의 거리를 구한 후,
각 정점들을 확인하며 두 정점과 다른 정점들 사이 거리가 가장 짧은 것을 구한다.

주요 알고리즘 : 그래프 이론, 플로이드-워셜, 브루트 포스

출처 : 류호석배 2회 4번
*/

int dist[128][128];

int small(int a, int b) {
    return a < b ? a : b;
}

int main(void) {
    int n, m, a, b, r, t;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) dist[i][j] = INF;
        dist[i][i] = 0;
    }
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        dist[a][b] = 1;
        dist[b][a] = 1;
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dist[i][j] = small(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    a = -1, b = -1, r = INF;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            t = 0;
            for (int k = 1; k <= n; k++) {
                t += small(dist[i][k], dist[j][k]);
            }
            if (t < r) {
                r = t;
                a = i;
                b = j;
            }
        }
    }
    if (a < 0) return 1;
    printf("%d %d %d", a, b, r * 2);
    return 0;
}