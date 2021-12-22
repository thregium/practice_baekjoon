#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 1000)개의 정점으로 이루어진 빨강과 파랑 간선으로 이어진 연결 그래프가 주어진다.
이때, 이 그래프의 스패닝 트리 가운데 파란 간선이 정확히 K개인 것이 있는 지 구한다.

해결 방법 : 이 그래프의 스패닝 트리에서 가능한 파란 간선의 수는 연속적으로 만들어진다. 그 이유는 한 스패닝 트리에서 한 간선을
끊고 다른 간선(단, 서로 다른 부분에 있는)을 이으면 새로운 스패닝 트리가 되는데, 색이 같다면 파란 간선의 수는 같을 것이고,
새로 이은 간선이 파랑, 끊은 간선이 빨강이면 1 늘어나고, 그 반대라면 1 줄어들기 때문에 가능한 범위 안에서는 연속이 된다.

가능한 범위는 그리디하게 그래프를 연결하여 알 수 있다. 파란 간선이 가장 많은 경우는 우선 파란 간선으로 최대한
연결한 다음 나머지를 빨간 간선으로 채운 경우이고, 가장 적은 경우는 그 반대로 한 경우이다.
K가 해당 범위 안에 있다면 그러한 경우가 있는 것이고, 범위 밖인 경우라면 그러한 경우가 없는 것이다.

주요 알고리즘 : 그래프 이론, 그리디 알고리즘, MST

출처 : UCIPC 2012 G번
*/

int ed[1048576][3], g[1024];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int cmp2(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai < bi ? 1 : ai == bi ? 0 : -1;
}

int find(int x) {
    if (!g[x]) return x;
    else return g[x] = find(g[x]);
}

void uni(int x, int y) {
    if (find(x) == find(y)) return;
    g[find(y)] = find(x);
}

int main(void) {
    int n, m, k, x, y, lo, hi;
    char c;
    //freopen("E:\\PS\\University\\NAIPC\\2012\\redblue.in", "r", stdin);
    while (1) {
        scanf("%d %d %d", &n, &m, &k);
        if (n == 0) break;
        for (int i = 0; i < m; i++) {
            scanf(" %c %d %d", &c, &ed[i][1], &ed[i][2]);
            ed[i][0] = (c == 'B');
        }
        lo = 0, hi = 0;
        qsort(ed, m, sizeof(int) * 3, cmp1);
        for (int i = 0; i < m; i++) {
            if (find(ed[i][1]) != find(ed[i][2])) {
                uni(ed[i][1], ed[i][2]);
                lo += ed[i][0];
            }
        }
        for (int i = 1; i <= n; i++) g[i] = 0;
        qsort(ed, m, sizeof(int) * 3, cmp2);
        for (int i = 0; i < m; i++) {
            if (find(ed[i][1]) != find(ed[i][2])) {
                uni(ed[i][1], ed[i][2]);
                hi += ed[i][0];
            }
        }
        for (int i = 1; i <= n; i++) g[i] = 0;
        
        printf("%d\n", k >= lo && k <= hi);
    }
    return 0;
}