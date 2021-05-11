#include <stdio.h>

/*
문제 : N(N <= 10)차원 좌표상에서 시작점과 도착점, 그리고 그들 사이의 경로가 각각 주어질 때,
주어진 경로들을 이용하여 도착점에 도착 가능한지 구한다.

해결 방법 : 각 정점들에 번호를 매긴 다음 이전에 나온 정점인 경우 그 번호로 두고,
새로 나온 정점이라면 새로운 번호를 할당한다. 그 다음 서로간의 연결관계를 파악하고 플러드필을 하면 된다.

주요 알고리즘 : 브루트 포스, 플러드필

출처 : GNY 2000 G번
*/

int nodes[1024][16], edges[1024][1024], vis[1024];

int dfs(int x, int r) {
    if (x == 1) r = 1;
    vis[x] = 1;
    for (int i = 1; i <= edges[x][0]; i++) {
        if (!vis[edges[x][i]]) r |= dfs(edges[x][i], r);
    }
    return r;
}

int main(void) {
    int n, sz, a, st, ed, tmp, r;
    for (int tt = 1;; tt++) {
        scanf("%d", &n);
        if (n == 0) break;
        for (int i = 0; i < n; i++) {
            scanf("%d", &nodes[0][i]);
        }
        for (int i = 0; i < n; i++) {
            scanf("%d", &nodes[1][i]);
        }
        sz = 2;
        while (1) {
            st = sz;
            for (int i = 0; i < n; i++) {
                scanf("%d", &nodes[sz][i]);
                if (nodes[sz][i] < 0) break;
            }
            if (nodes[sz][0] < 0) break;
            for (int i = 0; i < sz; i++) {
                tmp = 1;
                for (int j = 0; j < n; j++) {
                    if (nodes[i][0] != nodes[sz][0]) {
                        tmp = 0;
                        break;
                    }
                }
                if (tmp) {
                    st = i;
                    break;
                }
            }
            if (st == sz) sz++;

            ed = sz;
            for (int i = 0; i < n; i++) {
                scanf("%d", &nodes[sz][i]);
                if (nodes[sz][i] < 0) break;
            }
            if (nodes[sz][0] < 0) break;
            for (int i = 0; i < sz; i++) {
                tmp = 1;
                for (int j = 0; j < n; j++) {
                    if (nodes[i][0] != nodes[sz][0]) {
                        tmp = 0;
                        break;
                    }
                }
                if (tmp) {
                    ed = i;
                    break;
                }
            }
            if (ed == sz) sz++;

            edges[st][++edges[st][0]] = ed;
        }

        printf("Maze #%d %s be travelled\n", tt, dfs(0, 0) ? "can" : "cannot");
        for (int i = 0; i < sz; i++) {
            edges[i][0] = 0;
            vis[i] = 0;
        }
    }
    return 0;
}