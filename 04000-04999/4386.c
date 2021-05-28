#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
���� : N(N <= 100)���� ������ �̾ ��� ������ ���� ������������ �̾����� �ϴ� ��� �� ���� ���� ���̰� ª�� ���� ���̸� ���Ѵ�.

�ذ� ��� : ��Ÿ��� ������ ���� ��� ���� ������ �Ÿ��� ���� �� �� ������ �������� ���� MST�� ���ϸ� �ȴ�.

�ֿ� �˰��� : �׷��� �̷�, MST, ��Ÿ��� ����

��ó : ���з� 000923 A��
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