#include <stdio.h>
#define INF 1012345678

/*
문제 : N(N <= 100)개의 정점과 R(R <= 100)개의 양방향 간선으로 이루어진 그래프가 주어진다.
이 그래프에서 각 정점마다의 점수(<= 30)와 간선의 가중치(<= 15)가 주어지면 가중치 M(M <= 15) 이하 안에 있는
정점의 점수 합이 가장 큰 정점의 점수 합을 구한다.

해결 방법 : 플로이드-와샬 알고리즘을 이용해 각 정점 쌍의 거리를 구한다. 그 다음, 모든 정점마다
해당 정점에서 출발해서 가중치 M 내에 있는 정점의 점수 합을 구하고 그 값 가운데 가장 큰 것을 고르면 된다.
이때, 자기 자신으로 이동하는 경우에는 거리에 상관없이 더해야 한다.

주요 알고리즘 : 그래프 이론, 플로이드-와샬

출처 : 서강대 2017M D번
*/

int dist[128][128], item[128];

int small(int a, int b) {
    return a < b ? a : b;
}

int main(void) {
    int n, m, r, a, b, l;
    scanf("%d %d %d", &n, &m, &r);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &item[i]);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dist[i][j] = INF;
        }
    }
    for (int i = 0; i < r; i++) {
        scanf("%d %d %d", &a, &b, &l);
        dist[a][b] = small(dist[a][b], l);
        dist[b][a] = small(dist[b][a], l);
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dist[i][j] = small(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    r = 0;
    for (int i = 1; i <= n; i++) {
        a = 0;
        for (int j = 1; j <= n; j++) {
            if (dist[i][j] <= m || i == j) a += item[j];
        }
        if (a > r) r = a;
    }
    printf("%d", r);
    return 0;
}
