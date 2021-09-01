#include <stdio.h>

/*
문제 : N(N <= 3000)개의 원이 있을 때, 서로 닿는 원들의 집합이 몇 개인지 구한다.

해결 방법 : 두 원이 닿기 위해서는 두 원의 반지름의 합이 두 원의 중심 사이 거리보다 크거나 같아야 한다.
이는 피타고라스 정리를 통해 계산할 수 있다. N이 작기 때문에 모든 쌍에 대해 직접 계산해보면 된다.
서로 닿는 쌍들끼리는 간선으로 연결하고 플러드필을 하면 서로 다른 집합의 수를 구할 수 있다.

주요 알고리즘 : 그래프 이론, 플러드필, 기하학

출처 : Coder's High 2014 C번
*/

int pos[3200][3], ed[3200][3200], vis[3200];

int sqr(int a) {
    return a * a;
}

void dfs(int x) {
    vis[x] = 1;
    for (int i = 1; i <= ed[x][0]; i++) {
        if (!vis[ed[x][i]]) dfs(ed[x][i]);
    }
}

int main(void) {
    int t, n, r;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d %d %d", &pos[i][0], &pos[i][1], &pos[i][2]);
        }
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                if (sqr(pos[i][0] - pos[j][0]) + sqr(pos[i][1] - pos[j][1]) <= (sqr(pos[i][2] + pos[j][2]))) {
                    ed[i][++ed[i][0]] = j;
                    ed[j][++ed[j][0]] = i;
                }
            }
        }
        r = 0;
        for (int i = 1; i <= n; i++) {
            if (vis[i]) continue;
            dfs(i);
            r++;
        }
        printf("%d\n", r);
        for (int i = 1; i <= n; i++) {
            ed[i][0] = 0;
            vis[i] = 0;
        }
    }
    return 0;
}