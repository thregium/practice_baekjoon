#include <stdio.h>
#include <stdlib.h>
#define INF 1012345678

/*
문제 : N(N <= 1000)개의 도시의 위치(|| <= 2000)와 특별한 도시 여부가 주어진다.
각 도시 사이 이동시 맨해튼 거리만큼의 시간이 소요한다. 특별한 도시끼리는 서로 이동이 가능하고,
서로 이동시 T(T <= 2000)만큼의 시간이 소요된다. 이때, 두 도시 A, B에 대해 최단 이동 시간을
M(M <= 1000)개 구한다.

해결 방법 : 먼저 도시의 위치들에서 모든 도시 쌍에 대한 소요 시간을 구한다.
그리고 플로이드-워셜 알고리즘을 통해 모든 도시 쌍에 대한 이동 시간을 구하고 이를 출력하면 된다.

주요 알고리즘 : 그래프 이론, 플로이드-워셜

출처 : ?
*/

int dist[1024][1024], city[1024][3];

int small(int a, int b) {
    return a < b ? a : b;
}

int main(void) {
    int n, t, m, a, b;
    scanf("%d %d", &n, &t);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) dist[i][j] = INF;
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d %d %d", &city[i][0], &city[i][1], &city[i][2]);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dist[i][j] = abs(city[i][1] - city[j][1]) + abs(city[i][2] - city[j][2]);
            if (city[i][0] & city[j][0]) dist[i][j] = small(dist[i][j], t);
        }
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dist[i][j] = small(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        printf("%d\n", dist[a][b]);
    }
    return 0;
}