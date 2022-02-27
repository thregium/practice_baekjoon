#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/*
문제 : 평면상의 N(N <= 1000)개의 지점 사이를 잇는 케이블을 지으려고 한다. 모든 지점에서 E(1 <= E <= N)개의
지점 중 하나로 이동이 가능해야 한다. 이미 지어진 P(P <= 1000)개의 케이블이 주어지면,
조건을 만족하기 위해 추가로 지어야 하는 케이블의 최소 길이를 구한다.
케이블은 교차할 수 있고, 교차하는 케이블은 이어진 것으로 보지 않는다.

해결 방법 : 최소 스패닝 트리를 구하면 된다. 단, 미리 E개의 지점과 P개의 케이블들을 연결해둔 후 구한다.

주요 알고리즘 : 그래프 이론, MST

출처 : MidC 2018 A번
*/

typedef struct edge {
    int s, e;
    double l;
} edge;

int g[1024];
double pos[1024][2];
edge ed[1048576];

int cmp1(const void* a, const void* b) {
    edge ai = *(edge*)a;
    edge bi = *(edge*)b;
    return ai.l > bi.l ? 1 : ai.l == bi.l ? 0 : -1;
}

double getdist(double x1, double y1, double x2, double y2) {
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
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
    int n, e, p, x, y, ep = 0;
    double r = 0.0;
    scanf("%d %d %d", &n, &e, &p);
    for (int i = 1; i <= n; i++) {
        scanf("%lf %lf", &pos[i][0], &pos[i][1]);
    }
    for (int i = 2; i <= e; i++) {
        uni(1, i);
    }
    for (int i = 0; i < p; i++) {
        scanf("%d %d", &x, &y);
        uni(x, y);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            ed[ep].s = i;
            ed[ep].e = j;
            ed[ep++].l = getdist(pos[i][0], pos[i][1], pos[j][0], pos[j][1]);
        }
    }
    qsort(ed, ep, sizeof(edge), cmp1);
    for (int i = 0; i < ep; i++) {
        if (find(ed[i].e) != find(ed[i].s)) {
            uni(ed[i].s, ed[i].e);
            r += ed[i].l;
        }
    }
    printf("%f", r);
    return 0;
}