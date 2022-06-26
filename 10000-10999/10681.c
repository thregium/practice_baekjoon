#include <stdio.h>
#define INF 103000

/*
문제 : N(N <= 300)개의 역이 있고, 각 역들은 M(M <= 5000)개의 노선으로 연결되어 있다.
S번 역에서 출발하여 L(L <= 16)개의 식당 중 최대한 많은 식당에서 음식을 먹고 T(T <= 100000) 시간 내에
S번 역으로 돌아오려 한다. 각 식당의 위치와 먹는데 걸리는 시간이 주어질 때,
음식을 먹을 수 있는 최대의 식당 수를 구한다. S번 역의 근처에는 식당이 없고, 역에서 식당까지 가는 데에는
시간이 소요되지 않는다.

해결 방법 : 플로이드-워셜 알고리즘을 이용해 거리를 전처리한 다음, 비트DP를 이용하여 방문한
식당의 집합별로 돌아오는 최단 거리를 구하고, 그 거리가 T 이하인 것 가운데 방문한 식당의
개수가 가장 많은 것의 식당 수를 구하면 된다.

주요 알고리즘 : 그래프 이론, DP, 비트DP, 플로이드-워셜

출처 : JAG 2013P C번
*/

int dist[384][384], siro[17][2], mem[65536][17];

int small(int a, int b) {
    return a < b ? a : b;
}

int main(void) {
    int n, m, l, s, t, a, b, c, res, popcnt;
    while (1) {
        scanf("%d %d %d %d %d", &n, &m, &l, &s, &t);
        if (n == 0) break;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == j) dist[i][j] = 0;
                else dist[i][j] = INF;
            }
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

        for (int i = 0; i < l; i++) {
            scanf("%d %d", &siro[i][0], &siro[i][1]);
        }
        for (int i = 0; i < (1 << l); i++) {
            for (int j = 0; j <= l; j++) mem[i][j] = INF;
        }
        mem[0][l] = 0;
        siro[l][0] = s;
        siro[l][1] = 0;
        for (int i = 0; i < (1 << l); i++) {
            for (int j = 0; j <= l; j++) {
                if ((i >> j) & 1) {
                    for (int k = 0; k <= l; k++) {
                        if (k == l || ((i >> k) & 1)) {
                            mem[i][j] = small(mem[i][j], mem[i ^ (1 << j)][k] +
                                siro[j][1] + dist[siro[k][0]][siro[j][0]]);
                        }
                    }
                }
                else if (j == l) {
                    for (int k = 0; k < l; k++) {
                        if ((i >> k) & 1) {
                            mem[i][j] = small(mem[i][j], mem[i][k] + dist[siro[k][0]][siro[j][0]]);
                        }
                    }
                }
            }
        }

        res = 0;
        for (int i = 0; i < (1 << l); i++) {
            if (mem[i][l] > t) continue;
            popcnt = 0;
            for (int j = 0; j < l; j++) {
                if ((i >> j) & 1) popcnt++;
            }
            if (popcnt > res) res = popcnt;
        }
        printf("%d\n", res);
    }
    return 0;
}