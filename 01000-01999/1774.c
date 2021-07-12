#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/*
���� : N(N <= 1000)���� ������ �־�����, �̸� �� ������ ������ �����ߴٰ� �� ��, ������ ������ ������
��� ������ ���� �׷����� �ǵ��� �ϴ� ���� ������ �ּڰ��� ���Ѵ�.

�ذ� ��� : ũ�罺Į�� ���� MST�� �����, �̸� ����� ������ ���� ���Ͽ� �� ���´�.
�� ���� ���Ͽµ��� ���� ���鳢�� ������� ���� MST�� �ش� ���¿��� ���� �� �ִ� ���� ������ �ּڰ��� �ȴ�.

�ֿ� �˰��� : �׷��� �̷�, MST

��ó : USACO 2007D S2��
*/

typedef struct line {
    double len;
    int s;
    int e;
} line;

int pos[1024][2], g[1024];
line lines[1048576];
int lp = 0;

int cmp1(const void* a, const void* b) {
    line al = *(line*)a;
    line bl = *(line*)b;
    return al.len > bl.len ? 1 : al.len == bl.len ? 0 : -1;
}

int find(int x) {
    if (g[x] == 0) return x;
    else return g[x] = find(g[x]);
}

void uni(int a, int b) {
    if (find(a) == find(b)) return;
    g[find(a)] = find(b);
}

double getdist(int a, int b) {
    return sqrt(pow(pos[a][0] - pos[b][0], 2) + pow(pos[a][1] - pos[b][1], 2));
}

int main(void) {
    int n, m, s, e;
    double r = 0;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &pos[i][0], &pos[i][1]);
    }
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &s, &e);
        uni(s, e);
        //r += getdist(s, e);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            lines[lp].len = getdist(i, j);
            lines[lp].s = i;
            lines[lp].e = j;
            lp++;
        }
    }
    qsort(lines, lp, sizeof(line), cmp1);
    for (int i = 0; i < lp; i++) {
        if (find(lines[i].s) == find(lines[i].e)) continue;
        uni(lines[i].s, lines[i].e);
        r += lines[i].len;
    }
    printf("%.2f", r);
    return 0;
}