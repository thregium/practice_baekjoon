#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
문제 : N(N <= 1000)개의 센서가 너비 W(W <= 100000)인 복도 내부에 있다.
복도는 (X = 0)과 (X = W) 사이의 구간이다. 각 센서의 좌표(0 <= X <= W, -100000 <= Y <= 100000)와
탐지 범위(<= 100000)가 주어질 때, 복도의 양 끝 사이를 서로 이동할 수 있는 가장 작은 원의 반지름을 구한다.

해결 방법 : 복도의 양 끝을 기준선으로 하여 각 선과 복도의 양 끝 사이 거리를 간선으로 연결한다.
그리고 거리를 작은 순으로 정렬한 다음 유니온 파인드를 해 나가면서 복도의 양 끝 선이 연결되는
가장 작은 거리 / 2를 구하면 답이 된다.

주요 알고리즘 : 그래프 이론, 기하학, 유니온 파인드

출처 : BAPC 2013 G번
*/

typedef struct fpoint {
    double x, y, r;
} fpoint;

typedef struct edge {
    int s, e;
    double d;
} edge;

int uf_g[1024];
fpoint pos[1024];
edge ed[524288];

int cmp1(const void* a, const void* b) {
    double ai = (*(edge*)a).d;
    double bi = (*(edge*)b).d;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

double fdist(fpoint p1, fpoint p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

int uf_find(int x) {
    if (!uf_g[x]) return x;
    else return uf_g[x] = uf_find(uf_g[x]);
}

void uf_uni(int x, int y) {
    if (uf_find(x) == uf_find(y)) return;
    uf_g[uf_find(y)] = uf_find(x);
}

int main(void) {
    int t, n, ecnt;
    double w, res;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%lf%d", &w, &n);
        for (int i = 1; i <= n; i++) {
            scanf("%lf %lf %lf", &pos[i].x, &pos[i].y, &pos[i].r);
        }

        ecnt = 0;
        for (int i = 1; i <= n + 2; i++) {
            for (int j = i + 1; j <= n + 2; j++) {
                ed[ecnt].s = i;
                ed[ecnt].e = j;
                if (j > n) {
                    if (i > n) ed[ecnt].d = w;
                    else if (j == n + 1) ed[ecnt].d = pos[i].x - pos[i].r;
                    else if (j == n + 2) ed[ecnt].d = (w - pos[i].x) - pos[i].r;
                    else return 1;
                }
                else ed[ecnt].d = fdist(pos[i], pos[j]) - pos[i].r - pos[j].r;
                if (ed[ecnt].d < 0) ed[ecnt].d = 0;
                ecnt++;
            }
        }
        qsort(ed, ecnt, sizeof(edge), cmp1);
        res = 0.0;
        for (int i = 0; i < ecnt; i++) {
            uf_uni(ed[i].s, ed[i].e);
            res = ed[i].d;
            if (uf_find(n + 1) == uf_find(n + 2)) break;
        }
        res /= 2.0;
        printf("%.9f\n", res);

        for (int i = 1; i <= n + 2; i++) uf_g[i] = 0;
    }
    return 0;
}