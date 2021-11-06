#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 1000)개의 정점과 M(M <= 20000)개의 간선으로 이루어진 그래프의 각 간선과 간선의 가중치(<= 100000)가 주어지면
가장 가중치가 큰 스패닝 트리의 가중치를 구한다.

해결 방법 : 크루스칼 알고리즘은 최댓값에서도 정당성이 증명된다. 따라서, 크루스칼 알고리즘으로 MST를 구하되,
정렬을 역순으로 하면 된다.

주요 알고리즘 : 그래프 이론, MST

출처 : USACO 2004D S2번
*/

int ed[20480][3], g[20480];

int cmp1(const void* a, const void* b) {
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
    int n, m, r = 0, c = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &ed[i][1], &ed[i][2], &ed[i][0]);
    }
    qsort(ed, m, sizeof(int) * 3, cmp1);
    for (int i = 0; i < m; i++) {
        if (find(ed[i][1]) == find(ed[i][2])) continue;
        uni(ed[i][1], ed[i][2]);
        r += ed[i][0];
        c++;
    }
    if (c < n - 1) printf("-1");
    else printf("%d", r);
    return 0;
}