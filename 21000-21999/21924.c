#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 100000)개의 정점과 M(M <= 500000)개의 간선을 가진 그래프에서 MST에 없는 간선의 비용 합을 구한다.
MST가 만들어지지 않는 경우 -1을 출력한다.

해결 방법 : 크루스칼 알고리즘을 이용해 MST를 구한 것을 전체 간선의 합과 비교한 차를 출력한다. 단, 간선이 N - 1회보다
적게 만들어졌다면 MST가 완성되지 못했으므로 -1을 출력해야 한다.

주요 알고리즘 : 그래프 이론, MST
*/

int road[524288][3], g[103000];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
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
    int n, m, cnt = 0;
    long long s = 0, r = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &road[i][1], &road[i][2], &road[i][0]);
        s += road[i][0];
    }
    qsort(road, m, sizeof(int) * 3, cmp1);
    for (int i = 0; i < m; i++) {
        if (find(road[i][1]) == find(road[i][2])) continue;
        r += road[i][0];
        cnt++;
        uni(road[i][1], road[i][2]);
    }
    if (cnt < n - 1) printf("-1");
    else printf("%lld", s - r);
    return 0;
}