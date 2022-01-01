#include <stdio.h>
#include <stdlib.h>
#define INF 103000

/*
문제 : N(N <= 100)명에 대해 서로 아는 관계들이 주어진다. 이때, 각 서로 아는 관계들끼리 회의를 하고, 각 회의의 대표는
가장 친구 거리가 가까운 사람이 한다고 할 때, 대표의 수와 각 번호를 출력한다.

해결 방법 : 플러드필을 통해 회의를 각각 나눈 다음, 플로이드-워셜을 통해 각 친구 사이의 거리를 구한다.
그리고 각 회의마다 친구 사이 거리가 가장 먼 사람과의 거리가 가장 가까운 사람을 찾으면 대표를 찾을 수 있다.

주요 알고리즘 : 그래프 이론, 플러드필, 플로이드-워셜

출처 : 정올 2004지 중3/고3번
*/

int dist[128][128], vis[128], meet[128][128], rep[128];
int mcnt = 0;

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

void dfs(int n, int x) {
    vis[x] = 1;
    meet[mcnt][++meet[mcnt][0]] = x;
    for (int i = 1; i <= n; i++) {
        if (dist[x][i] < INF && !vis[i]) dfs(n, i);
    }
}

int main(void) {
    int n, m, a, b, hi, best;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) dist[i][j] = INF;
        dist[i][i] = 0;
    }
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        dist[a][b] = 1;
        dist[b][a] = 1;
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(n, i);
            mcnt++;
        }
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
    for (int i = 0; i < mcnt; i++) {
        best = INF;
        for (int j = 1; j <= meet[i][0]; j++) {
            hi = -1;
            for (int k = 1; k <= meet[i][0]; k++) {
                if (dist[meet[i][j]][meet[i][k]] > hi) hi = dist[meet[i][j]][meet[i][k]];
            }
            if (hi < 0) return 1;
            if (hi < best) {
                best = hi;
                rep[i] = meet[i][j];
            }
        }
        if (rep[i] == 0) return 2;
    }
    qsort(rep, mcnt, sizeof(int), cmp1);
    printf("%d\n", mcnt);
    for (int i = 0; i < mcnt; i++) {
        printf("%d\n", rep[i]);
    }
    return 0;
}