#include <stdio.h>
#define INF 1012345678

/*
문제 : N(N <= 100)개의 정점과 M(M <= 1000)개의 간선으로 이루어진 단방향 가중치(<= 1000, 자연수) 그래프에서
정점 A부터 B와 C로 이동하도록 간선을 남길 때의 최소 가중치를 구한다.

해결 방법 : 플로이드-워셜 알고리즘을 통해 모든 정점 사이 거리를 구한 다음, 모든 중간 정점에 대해
해당 정점을 분기점으로 하도록 간선을 남겼을 때의 가중치 합 가운데 가장 작은 것을 고르면 된다.

주요 알고리즘 : 그래프 이론, 플로이드-워셜, 브루트 포스

출처 : JDC 2006 F번
*/

int dist[128][128], ed[128][128];

long long small(long long a, long long b) {
    return a < b ? a : b;
}

int main(void) {
    int n, m, a, b, c, x, y, z;
    long long r;
    //freopen("E:\\PS\\Contest\\Japanese Alumni Group\\2006D\\judge-data\\F1", "r", stdin);
    while (1) {
        scanf("%d %d %d %d %d", &n, &m, &a, &b, &c);
        if (n == 0) break;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dist[i][j] = INF;
                ed[i][j] = 0;
            }
            dist[i][i] = 0;
        }
        for (int i = 0; i < m; i++) {
            scanf("%d %d %d", &x, &y, &z);
            ed[x][y] = z;
            //ed[y][x] = z;
            dist[x][y] = z;
            //dist[y][x] = z;
        }
        for (int k = 1; k <= n; k++) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    dist[i][j] = small(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        /*
        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j++) {
                if (dist[a][i] > dist[a][j]) ed[i][j] = 0;
                else ed[j][i] = 0;
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dist[i][j] = INF;
                if (ed[i][j]) dist[i][j] = ed[i][j];
            }
            dist[i][i] = 0;
        }
        */
        for (int k = 1; k <= n; k++) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    dist[i][j] = small(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        r = INF;
        for (int i = 1; i <= n; i++) {
            r = small(r, (long long)dist[a][i] + dist[i][b] + dist[i][c]);
        }
        printf("%lld\n", r);
    }
    return 0;
}