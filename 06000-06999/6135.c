#include <stdio.h>
#define INF 1012345678

/*
문제 : N(N <= 300)개의 정점과 M(M <= 25000)개의 간선으로 이루어진 그래프에서 각 간선들은 가중치(<= 10^6)를 가진 유향 간선이다.
T(T <= 40000)개의 정점 쌍이 주어질 때, 해당 경로 가운데 가중치의 최댓값이 가장 작은 경로의 가중치 최댓값을 각각 출력한다.
경로가 없는 경우에는 -1을 출력한다.

해결 방법 : 플로이드-워셜 알고리즘을 사용한다. 먼저 각 경로의 가중치 최댓값의 최소를 무한대로 초기화한 다음,
각 간선마다 경로의 가중치를 해당 가중치로 바꾼다. 그 이후로는 플로이드-워셜 알고리즘을 돌리면서
중간점을 경유할 때 가중치가 줄어들 수 있는지 확인하고 그때마다 가중치를 갱신해 나간다.
모든 정점을 확인한 후에는 모든 경로에 대해 가중치를 알 수 있게 된다. 무한대인 경우에는 경로가 없는 것이므로
-1을 출력하면 되고, 그 외에는 그 값을 출력하면 된다.

주요 알고리즘 : 그래프 이론, 플로이드-워셜

출처 : USACO 2007N S1번
*/

int best[384][384];

int small(int a, int b) {
    return a < b ? a : b;
}

int big(int a, int b) {
    return a > b ? a : b;
}

int main(void) {
    int n, m, t, s, e, h;
    scanf("%d %d %d", &n, &m, &t);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) best[i][j] = INF;
    }
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &s, &e, &h);
        best[s][e] = small(best[s][e], h);
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                best[i][j] = small(best[i][j], big(best[i][k], best[k][j]));
            }
        }
    }
    for (int tt = 0; tt < t; tt++) {
        scanf("%d %d", &s, &e);
        printf("%d\n", best[s][e] == INF ? -1 : best[s][e]);
    }
    return 0;
}