#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 1000)개의 건물 사이 길들이 주어질 때, 각 길들의 오르막/내리막 여부가 주어진다.
사이클이 생기지 않도록 건물들 사이 길을 선택할 때, 오르막이 최대가 될 때와 최소가 될 때의 개수 제곱의 차이를 구한다.

해결 방법 : 오르막을 비용 1, 내리막을 비용 0으로 두고 최대 스패닝 트리와 최소 스패닝 트리를 구한다.
최대 스패닝 트리의 제곱에서 최소 스패닝 트리의 제곱을 빼면 답이 된다.

주요 알고리즘 : 그래프 이론, MST

출처 : 국민대 2016 F번
*/

int road[524288][3], g[1024];

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
    int n, m, a, b, c, rl = 0, rh = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i <= m; i++) {
        scanf("%d %d %d", &road[i][1], &road[i][2], &road[i][0]);
        road[i][0] = 1 - road[i][0];
        road[i][1]++;
        road[i][2]++;
    }
    qsort(road, m + 1, sizeof(int) * 3, cmp1);
    for (int i = 0; i <= m; i++) {
        if (find(road[i][1]) == find(road[i][2])) continue;
        uni(road[i][1], road[i][2]);
        rl += road[i][0];
    }
    for (int i = 0; i < 1024; i++) g[i] = 0;
    qsort(road, m + 1, sizeof(int) * 3, cmp2);
    for (int i = 0; i <= m; i++) {
        if (find(road[i][1]) == find(road[i][2])) continue;
        uni(road[i][1], road[i][2]);
        rh += road[i][0];
    }
    printf("%d", rh * rh - rl * rl);
    return 0;
}