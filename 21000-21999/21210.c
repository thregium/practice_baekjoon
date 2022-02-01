#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
문제 : X * Y(X, Y <= 10^6) 크기의 직사각형에 N(N <= 1000)명의 사람들이 있다.
각 사람들과의 거리를 최대한 멀리 하며 (0, 0)에서 (X, Y)로 이동하려고 할 때, 다른 사람과 가장 가까워지는
지점의 거리를 구한다.

해결 방법 : 각 사람 사이 이동 가능한 통로를 생각하면서 거리가 멀어질 때 마다 통로 사이를 합쳐나간다.
이렇게 가다가 서로 마주보는 두 벽 또는 입구나 출구와 맞닿은 두 벽이 합쳐지면 그 때의 거리를 구하면 된다.
통로로 쓸 수 있는 두 사람간의 안전거리는 두 사람 간의 거리 / 2 또는 사람과 벽의 거리와 같다.
이를 모두 구한 다음, 크루스칼 알고리즘과 같이 거리가 짧은 순으로 정렬한 후 이동 불가능할 때 까지
거리를 늘려나간다.

주요 알고리즘 : 자료 구조, 유니온 파인드, 크루스칼

출처 : SWERC 2020 C번
*/

typedef struct edge {
    double len;
    int v1, v2;
} edge;

int g[1024];
double pers[1024][2];
edge ed[1048576];

int cmp1(const void* a, const void* b) {
    edge ai = *(edge*)a;
    edge bi = *(edge*)b;
    return ai.len > bi.len ? 1 : ai.len == bi.len ? 0 : -1;
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
    int x, y, n, e = 0;
    double d = 103000 * 103000;
    //freopen("E:\\PS\\ICPC\\Europe\\SWERC\\2020\\swerc\\safedistance\\data\\secret\\test15.in", "r", stdin);
    scanf("%d %d", &x, &y);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lf %lf", &pers[i][0], &pers[i][1]);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            ed[e].v1 = i;
            ed[e].v2 = j;
            ed[e++].len = sqrt(pow(pers[i][0] - pers[j][0], 2) + pow(pers[i][1] - pers[j][1], 2)) / 2;
        }
        for (int j = 0; j < 4; j++) {
            ed[e].v1 = i;
            ed[e].v2 = 1001 + j;
            if (j == 0) ed[e++].len = pers[i][0];
            else if (j == 1) ed[e++].len = pers[i][1];
            else if (j == 2) ed[e++].len = x - pers[i][0];
            else ed[e++].len = y - pers[i][1];
        }
    }
    qsort(ed, e, sizeof(edge), cmp1);
    for (int i = 0; i < e; i++) {
        if (find(1001) == find(1002) || find(1001) == find(1003) ||
            find(1002) == find(1004) || find(1003) == find(1004)) break;
        uni(ed[i].v1, ed[i].v2);
        d = ed[i].len;
    }
    printf("%.9f\n", d);
    return 0;
}