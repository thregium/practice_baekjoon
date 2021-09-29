#include <stdio.h>

/*
문제 : N(N <= 100)개의 정점으로 이루어진 유향 그래프의 인접 행렬이 주어질 때, M번 정점에서 출발한다면
해당 정점에서의 최단거리별 정점을 각각 오름차순으로 출력한다.

해결 방법 : M번 정점에서 시작하는 BFS를 돌린 다음, 정점 번호를 오름차순으로 확인하며 방문한 정점들에 대해
최단거리별로 결과를 배열에 저장한다. 그 다음, 이를 차례로 출력하면 된다.

주요 알고리즘 : 그래프 이론, BFS

출처 : USACO 2011M B2번
*/

int q[1024], vis[128], dist[128], adj[128][128], res[128][128];
int qf = 0, qr = 0;

int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }
    q[qr++] = m;
    vis[m] = 1;
    while (qr > qf) {
        m = q[qf++];
        for (int i = 1; i <= n; i++) {
            if (adj[m][i] && !vis[i]) {
                q[qr++] = i;
                vis[i] = 1;
                dist[i] = dist[m] + 1;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) continue;
        res[dist[i]][++res[dist[i]][0]] = i; //res[i][0] = res[i]의 크기
    }

    for (int i = 0; res[i][0]; i++) {
        for (int j = 1; j <= res[i][0]; j++) {
            printf("%d", res[i][j]);
            if (j < res[i][0]) printf(" ");
        }
        if (res[i + 1][0]) printf("\n");
    }
    return 0;
}