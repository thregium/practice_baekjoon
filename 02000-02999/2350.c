#include <stdio.h>

/*
문제 : N(N <= 1000)개의 정점과 M(M <= 100000)개의 간선으로 이루어진 무방향 그래프가 있다.
각 간선은 가중치 W(W <= 200)를 갖는다. 이때, K(K <= 100000)개의 쿼리에 응답한다.
두 정점 i, j 사이를 잇는 경로 가운데 가장 가중치의 최솟값이 큰 경로의 가중치 최솟값을 출력한다.

해결 방법 : 그래프의 가중치들을 입력받은 후, 플로이드-워셜 알고리즘을 이용해 모든 경로의 가중치 최솟값을 구한다.
경유지를 거쳐 갈 때 경로의 가중치 최솟값이 커진다면 가중치를 업데이트 하는 방식으로 구하면 된다.
그 다음으로는 저장해둔 모든 경로의 가중치를 각각 출력하면 된다.

주요 알고리즘 : 그래프 이론, 플로이드-워셜

출처 : Shumen 2012 A2번
*/

int maxwidth[1024][1024];

int small(int a, int b) {
    return a < b ? a : b;
}

int big(int a, int b) {
    return a > b ? a : b;
}

int main(void) {
    int n, m, k, x, y, w;
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &x, &y, &w);
        if (maxwidth[x][y]) maxwidth[x][y] = big(maxwidth[x][y], w);
        else maxwidth[x][y] = w;
        if (maxwidth[y][x]) maxwidth[y][x] = big(maxwidth[y][x], w);
        else maxwidth[y][x] = w;
    }
    for (int v = 1; v <= n; v++) {
        for (int i = 1; i <= n; i++) {
            if (maxwidth[i][v] == 0) continue;
            for (int j = 1; j <= n; j++) {
                if (small(maxwidth[i][v], maxwidth[v][j]) > maxwidth[i][j]) {
                    maxwidth[i][j] = small(maxwidth[i][v], maxwidth[v][j]);
                }
            }
        }
    }
    for (int i = 0; i < k; i++) {
        scanf("%d %d", &x, &y);
        printf("%d\n", maxwidth[x][y]);
    }
    return 0;
}