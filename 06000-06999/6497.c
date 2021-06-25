#include <stdio.h>
#include <stdlib.h>

/*
문제 : 정점이 M개이고 간선이 N(M, N <= 200000)개인 연결 그래프가 주어질 때, 해당 그래프의 간선을 제거해도 연결 그래프가 되도록
하는 간선들의 가중치 최댓값을 구한다.

해결 방법 : 이는 MST가 아닌 모든 간선의 가중치 합을 구하는 것과 같고, 따라서 MST를 구한 다음 전체 간선의 가중치 합에서
MST의 가중치 합을 빼주면 된다.

주요 알고리즘 : 그래프 이론, MST

출처 : ULM 2009 D번
*/

int roads[204800][3], g[204800];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int find(int x) {
    if (g[x] == 0) return x;
    else return g[x] = find(g[x]);
}

void uni(int x, int y) {
    g[find(y)] = find(x);
}

int main(void) {
    int m, n, x, y, z, sum = 0, mst = 0;
    while (1) {
        scanf("%d %d", &m, &n);
        if (m == 0) break;
        sum = 0;
        mst = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d %d %d", &x, &y, &z);
            roads[i][0] = z;
            roads[i][1] = x + 1;
            roads[i][2] = y + 1;
            sum += z;
        }
        qsort(roads, n, sizeof(int) * 3, cmp1);

        for (int i = 0; i < n; i++) {
            if (find(roads[i][1]) == find(roads[i][2])) continue;
            uni(roads[i][1], roads[i][2]);
            mst += roads[i][0];
        }
        printf("%d\n", sum - mst);
        for (int i = 1; i <= m; i++) g[i] = 0;
    }
    return 0;
}