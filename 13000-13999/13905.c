#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 100000)개의 정점과 M(M <= 300000)개의 간선으로 이루어진 그래프에서 정점 S와 정점 E 사이 이동하는 경로가
생기기 위해서 있어야 하는 제한 가운데 최소를 구한다. 이동 불가능한 경우 0을 출력한다.

해결 방법 : 크루스칼 알고리즘을 통해 각 간선들을 제한이 큰 순으로 정렬한 다음, S와 E가 연결되는 시점의 제한을 구해서
그때의 제한을 출력하면 된다.

주요 알고리즘 : 그래프 이론, MST

출처 : 서강대 12회C F번
*/

int brd[327680][3], g[103000];

int find(int x) {
    if (!g[x]) return x;
    else return g[x] = find(g[x]);
}

void uni(int x, int y) {
    if (find(x) == find(y)) return;
    g[find(y)] = find(x);
}

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai < bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, m, s, e;
    scanf("%d %d", &n, &m);
    scanf("%d %d", &s, &e);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &brd[i][1], &brd[i][2], &brd[i][0]);
    }
    qsort(brd, m, sizeof(int) * 3, cmp1);
    for (int i = 0; i < m; i++) {
        uni(brd[i][1], brd[i][2]);
        if (find(s) == find(e)) {
            printf("%d", brd[i][0]);
            return 0;
        }
    }
    printf("0");
    return 0;
}