#include <stdio.h>
#define INF 1012345678

/*
문제 : 길이 D(D <= 10000)의 길을 가려고 한다. N(N <= 12)개의 지름길이 있을 때,
D까지의 최단 거리를 구한다.

해결 방법 : 길의 각 지점마다의 최단 거리를 다이나믹 프로그래밍을 통해 구한다.
지름길의 끝점인 경우 지름길을 지나는 경로와도 비교해보고, 그 외에는 전 칸 + 1로 두면 된다.

주요 알고리즘 : DP
*/

int dist[10240], sc[16][3];

int small(int a, int b) {
    return a < b ? a : b;
}

int main(void) {
    int n, d;
    scanf("%d %d", &n, &d);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &sc[i][0], &sc[i][1], &sc[i][2]);
    }
    for (int i = 1; i <= d; i++) dist[i] = INF;
    for (int i = 1; i <= d; i++) {
        for (int j = 0; j < n; j++) {
            if (sc[j][1] == i) dist[i] = small(dist[i], dist[sc[j][0]] + sc[j][2]);
        }
        dist[i] = small(dist[i], dist[i - 1] + 1);
    }
    printf("%d", dist[d]);
    return 0;
}