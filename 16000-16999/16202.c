#include <stdio.h>

/*
문제 : N(N <= 1000)개의 정점과 M(M <= 10000)개의 간선으로 이루어진 그래프에서 K(K <= 100)번 MST를 이루는 간선의 길이를 구한다.
단, 매번 구한 다음, MST를 이루는 간선 가운데 가장 길이가 작은 간선을 지운다.
만들 수 없는 경우 0을 출력한다.

해결 방법 : 매번 MST를 출력하면 된다. 또한, 가장 길이가 작은 간선은 항상 MST를 만들 수 있는 경우 MST에 들어가므로
가장 짧은 i - 1개의 간선을 제외하고 생각하면 된다.

주요 알고리즘 : 그래프 이론, MST, 시뮬레이션
*/

int ed[10240][3], g[1024];

int find(int x) {
    if (!g[x]) return x;
    else return g[x] = find(g[x]);
}

void uni(int x, int y) {
    if (find(x) == find(y)) return;
    g[find(y)] = find(x);
}

int main(void) {
    int n, m, k, c, r;
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &ed[i][1], &ed[i][2]);
        ed[i][0] = i + 1;
    }
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < 1024; j++) g[j] = 0;
        c = 0, r = 0;
        for (int j = i; j < m; j++) {
            if (find(ed[j][1]) == find(ed[j][2])) continue;
            uni(ed[j][1], ed[j][2]);
            r += ed[j][0];
            c++;
        }
        if (c == n - 1) printf("%d ", r);
        else printf("0 ");
    }
    return 0;
}