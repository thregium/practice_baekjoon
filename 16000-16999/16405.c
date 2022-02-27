#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/*
���� : ������ N(N <= 1000)���� ���� ���̸� �մ� ���̺��� �������� �Ѵ�. ��� �������� E(1 <= E <= N)����
���� �� �ϳ��� �̵��� �����ؾ� �Ѵ�. �̹� ������ P(P <= 1000)���� ���̺��� �־�����,
������ �����ϱ� ���� �߰��� ����� �ϴ� ���̺��� �ּ� ���̸� ���Ѵ�.
���̺��� ������ �� �ְ�, �����ϴ� ���̺��� �̾��� ������ ���� �ʴ´�.

�ذ� ��� : �ּ� ���д� Ʈ���� ���ϸ� �ȴ�. ��, �̸� E���� ������ P���� ���̺���� �����ص� �� ���Ѵ�.

�ֿ� �˰��� : �׷��� �̷�, MST

��ó : MidC 2018 A��
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