#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
문제 : N(N <= 100)개의 점들을 이어서 모든 점들이 서로 직간접적으로 이어지게 하는 방법 중 가장 선의 길이가 짧은 것의 길이를 구한다.

해결 방법 : 피타고라스 정리를 통해 모든 점들 사이의 거리를 구한 후 그 선들을 바탕으로 선의 MST를 구하면 된다.

주요 알고리즘 : 그래프 이론, MST, 피타고라스 정리

출처 : 워털루 000923 A번
*/

double pos[128][2], edges[16384][3];
int g[128];
int ep = 0;

double square(double a) {
    return a * a;
}

double dist(int a, int b) {
    return sqrt(square(pos[a][0] - pos[b][0]) + square(pos[a][1] - pos[b][1]));
}

int cmp1(const void* a, const void* b) {
    double ai = *(double*)a;
    double bi = *(double*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int find(int x) {
    if (g[x] == 0) return x;
    return g[x] = find(g[x]);
}

void uni(int x, int y) {
    if (find(x) == find(y)) return;
    g[find(x)] = find(y);
}

int main(void) {
    int n;
    double res = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lf %lf", &pos[i][0], &pos[i][1]);
        for (int j = 0; j < i; j++) {
            edges[ep][0] = dist(i, j);
            edges[ep][1] = i + 1;
            edges[ep++][2] = j + 1;
        }
    }
    qsort(edges, ep, sizeof(double) * 3, cmp1);
    for (int i = 0; i < ep; i++) {
        if (find(edges[i][1]) == find(edges[i][2])) continue;
        res += edges[i][0];
        uni(edges[i][1], edges[i][2]);
    }
    printf("%f", res);
    return 0;
}