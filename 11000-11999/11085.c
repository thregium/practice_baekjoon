#include <stdio.h>
#include <stdlib.h>

/*
문제 : P(P <= 1000)개의 정점과 W(W <= 50000)개의 간선으로 이루어진 그래프에서 두 점 c와 w 사이를 잇는 상한을 구한다.

해결 방법 : 크루스칼 알고리즘을 응용하여 풀 수 있다. 간선들을 상한이 큰 순으로 정렬한 다음, c와 w가 연결될 때 까지
유니온-파인드를 이용해 두 정점들을 이어나간다. c와 w가 연결되는 순간의 상한이 답이 된다.
연결되지 않는다면 0을 출력한다.

주요 알고리즘 : 그래프 이론, 유니온 파인드, MST

출처 : ACMSPCD 2015 F번
*/

int road[51200][3], g[1024];

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
    int p, w, c, v;
    scanf("%d %d", &p, &w);
    scanf("%d %d", &c, &v);
    c++, v++;
    for (int i = 0; i < w; i++) {
        scanf("%d %d %d", &road[i][1], &road[i][2], &road[i][0]);
        road[i][1]++, road[i][2]++;
    }
    qsort(road, w, sizeof(int) * 3, cmp1);
    for (int i = 0; i < w; i++) {
        uni(road[i][1], road[i][2]);
        if (find(c) == find(v)) {
            printf("%d", road[i][0]);
            return 0;
        }
    }
    printf("0");
    return 0;
}