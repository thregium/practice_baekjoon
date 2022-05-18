#include <stdio.h>
#define INF 1012345678

/*
문제 : 차 3대가 1번 지점에 있다. N(N <= 30)개의 지점 쌍들에 대해 이동 시간이 주어질 때, 차 3대로 모든 지점을
지나갔을 때의 차 3대가 움직이는 이동 시간 합의 최솟값을 구한다.
단, 각 지점은 오름차순으로만 방문 가능하다.

해결 방법 : 차 3대의 위치마다의 최단 시간 합을 저장한 다음, 2번 지점부터 N번 지점까지 오름차순으로 돌며
값들을 갱신해 나간다. 최종적으로 N번 지점에 차가 있는 지점들의 이동 시간 합 가운데
가장 작은 것을 고르면 답이 된다.

주요 알고리즘 : DP

출처 : Tehran 1999 F번
*/

int dist[32][32], mem[32][32][32];

int small(int a, int b) {
    return a < b ? a : b;
}

int big(int a, int b) {
    return a > b ? a : b;
}

int main(void) {
    int t, n, r;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) dist[i][j] = INF;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                scanf("%d", &dist[i][j]);
                dist[j][i] = dist[i][j];
            }
        }
        /*
        for (int k = 1; k <= n; k++) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    dist[i][j] = small(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        */

        for (int i = 0; i < 32; i++) {
            for (int j = 0; j < 32; j++) {
                for (int k = 0; k < 32; k++) mem[i][j][k] = INF;
            }
        }
        mem[1][1][1] = 0;
        r = INF;
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j < i; j++) {
                for (int k = 1; k < i; k++) {
                    for (int l = 1; l < i; l++) {
                        if (big(big(j, k), l) < i - 1) continue;
                        mem[i][k][l] = small(mem[i][k][l], mem[j][k][l] + dist[j][i]);
                        mem[j][i][l] = small(mem[j][i][l], mem[j][k][l] + dist[k][i]);
                        mem[j][k][i] = small(mem[j][k][i], mem[j][k][l] + dist[l][i]);
                        if (i == n) {
                            r = small(r, mem[i][k][l]);
                            r = small(r, mem[j][i][l]);
                            r = small(r, mem[j][k][i]);
                        }
                    }
                }
            }
        }

        if (r == INF) return 1;
        printf("%d\n", r);
    }
    return 0;
}