#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 1000)개의 정점을 가진 그래프에서 가중치가 인접 행렬 형태로 주어질 때,
간선을 최대한 제거하여도 연결 그래프가 되도록 할 때 남은 간선의 가중치 합 가운데 최솟값을 구한다.

해결 방법 : 최소 스패닝 트리를 구하면 된다.

주요 알고리즘 : 그래프 이론, MST

출처 : 홍익대 2018 E번
*/

int ed[1048576][3], g[1024];

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
    int n;
    long long r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &ed[i * n + j][0]);
            ed[i * n + j][1] = i + 1;
            ed[i * n + j][2] = j + 1;
        }
    }
    qsort(ed, n * n, sizeof(int) * 3, cmp1);
    for (int i = 0; i < n * n; i++) {
        if (find(ed[i][1]) == find(ed[i][2])) continue;
        r += ed[i][0];
        uni(ed[i][1], ed[i][2]);
    }
    printf("%lld", r);
    return 0;
}