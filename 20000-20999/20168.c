#include <stdio.h>

/*
문제 : N(N <= 10)개의 정점으로 이루어진 양방향 가중치 그래프에서 C(C <= 10000)의 비용으로 정점 A에서 정점 B로 이동하는
방법 가운데 중간에 지나는 간선의 가중치 최댓값이 가장 작은 것의 가중치 최댓값을 구한다.
각 간선의 가중치는 1000 이하의 자연수이다.

해결 방법 : 백트래킹을 통해 모든 경우를 살펴본다. 중간에 비용이 넘는 경우는 확인하지 않는다.

주요 알고리즘 : 그래프 이론, 백트래킹

출처 : 류호석배 1회 6번
*/

typedef struct road {
    int ed;
    int fee;
} road;

int rdc[16], vis[16];
road rd[16][16];
int best = 103000;

void track(int a, int b, int c, int m) {
    if (a == b) {
        if (m < best) best = m;
        return;
    }
    for (int i = 0; i < rdc[a]; i++) {
        if (!vis[rd[a][i].ed] && rd[a][i].fee <= c) {
            vis[rd[a][i].ed] = 1;
            track(rd[a][i].ed, b, c - rd[a][i].fee, rd[a][i].fee > m ? rd[a][i].fee : m);
            vis[rd[a][i].ed] = 0;
        }
    }
}

int main(void) {
    int n, m, a, b, c, u, v, f;
    scanf("%d %d %d %d %d", &n, &m, &a, &b, &c);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &f);
        rd[u][rdc[u]].ed = v;
        rd[u][rdc[u]++].fee = f;
        rd[v][rdc[v]].ed = u;
        rd[v][rdc[v]++].fee = f;
    }
    vis[a] = 1;
    track(a, b, c, 0);
    printf("%d", best == 103000 ? -1 : best);
    return 0;
}