#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 1000)개의 정점과 M(M <= 10000)개의 간선으로 이루어진 그래프에서 정점마다 두 가지 중 한 가지의 색을 칠했다.
서로 색이 다른 정점을 연결하는 간선으로 이루어진 그래프 가운데 연결 그래프가 되는 것의 가장 작은 가중치를 구한다.
그러한 것이 없다면 -1을 출력한다.

해결 방법 : 색이 다른 정점을 연결하는 간선만을 추린 다음 MST를 만들면 된다.

주요 알고리즘 : 그래프 이론, MST

출처 : 인하대 2017 J번
*/

int univ[1024], g[1024], road[10240][3];

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
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, m, rsz = 0, cnt = 1, r = 0;
    char c;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf(" %c", &c);
        if (c == 'M') univ[i] = 1;
    }
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &road[rsz][1], &road[rsz][2], &road[rsz][0]);
        if (univ[road[rsz][1]] != univ[road[rsz][2]]) rsz++;
    }
    qsort(road, rsz, sizeof(int) * 3, cmp1);
    for (int i = 0; i < rsz; i++) {
        if (find(road[i][1]) == find(road[i][2])) continue;
        r += road[i][0];
        uni(road[i][1], road[i][2]);
        cnt++;
        if (cnt == n) {
            printf("%d", r);
            return 0;
        }
    }
    printf("-1");
    return 0;
}