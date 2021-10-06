#include <stdio.h>
#define FOUT 0
#define INF 1012345678
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
문제 : 10000개의 도시와 N(N <= 500)개의 고속도로가 있고, 각 고속도로는 500개 이하의 도시를 연결한다.
한 고속도로의 일부를 탄 경우에는 요금(<= 1000)을 내게 된다면 고속도로를 2개 이하로 타고
도시 A에서 도시 B로 이동하는데 필요한 최소 금액을 구한다. 이동이 불가능하다면 -1을 출력한다.

해결 방법 : A에서 이동이 가능한 각 도시에 대해 필요한 고속도로 요금과 각 도시에서 B로 이동이 가능한 도시에
대해 필요한 고속도로의 요금을 저장한다. 그 다음, 두 값의 합을 더한 값이 가장 작은 것을 구하고,
A에서 B로 바로 이동이 가능하다면 그 값과 비교해 가장 작은 것을 구하면 된다.

주요 알고리즘 : 밋 인 더 미들

출처 : USACO 2015J B2번
*/

int cost[512], rc[512], route[512][512], dist[10240], dist2[10240];
char chk[10240];

int small(int a, int b) {
    return a < b ? a : b;
}

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("cowroute.in", "r");
        fo = fopen("cowroute.out", "w");
    }
    int a, b, n, c, r = INF;
    scanf("%d %d %d", &a, &b, &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &cost[i], &rc[i]);
        for (int j = 0; j < rc[i]; j++) {
            scanf("%d", &route[i][j]);
        }
    }
    for (int i = 0; i < 10240; i++) {
        dist[i] = INF;
        dist2[i] = INF;
    }
    for (int i = 0; i < n; i++) {
        c = 0;
        for (int j = 0; j < 10240; j++) chk[j] = 0;
        for (int j = 0; j < rc[i]; j++) {
            chk[route[i][j]] = 1;
            if (route[i][j] == a) c = 1;
            if (c) dist[route[i][j]] = small(dist[route[i][j]], cost[i]);
            if (route[i][j] == b) {
                for (int k = 0; k < 10240; k++) {
                    if (chk[k]) dist2[k] = small(dist2[k], cost[i]);
                }
            }
        }
    }

    r = small(r, dist[b]);
    for (int i = 0; i < 10240; i++) r = small(r, dist[i] + dist2[i]);
    printf("%d", r == INF ? -1 : r);
    return 0;
}