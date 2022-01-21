#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/*
���� : ���� �� N(N <= 100)���� ���� �ִ�. �̶�, ��� ������ �����ϱ� ���� �ʿ��� �ּ� �Ÿ��� ���Ѵ�.
�� ������ �����ϴ� ������ �߰��� �������� ������ ������ ������� �ʴ´�. ����, ���� �Ϻΰ� ��ġ�� ���
�������� �ʾƵ� ����� ������ �����Ѵ�.

�ذ� ��� : �켱 �� ������ �մ� �Ÿ����� ���� ���Ѵ�. �̴� ��Ÿ��� ������ ���� �Ÿ��� ���� ����,
�� ���� �������� ���� �ȴ�. �� ���� �Ÿ����� ������������ �����ϰ� MST�� ���ϸ� �ȴ�.
�̶�, ����� ������ ��� ��뿡 ������ ������ �����Ѵ�.

�ֿ� �˰��� : �׷��� �̷�, MST, ������

��ó : JDC 2003 D��
*/

double cell[128][4], corr[5120][3];
int g[128];

int cmp1(const void* a, const void* b) {
    double ai = *(double*)a;
    double bi = *(double*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

double getdist(int a, int b) {
    return sqrt(pow(cell[a][0] - cell[b][0], 2) + pow(cell[a][1] - cell[b][1], 2) +
        pow(cell[a][2] - cell[b][2], 2));
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
    int n, cp;
    double r;
    //freopen("E:\\PS\\ICPC\\Asia Pacific\\Japan Domestic\\2003\\D2.txt", "r", stdin);
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        for (int i = 1; i <= n; i++) {
            scanf("%lf %lf %lf %lf", &cell[i][0], &cell[i][1], &cell[i][2], &cell[i][3]);
        }
        cp = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                corr[cp][0] = getdist(i, j) - cell[i][3] - cell[j][3];
                corr[cp][1] = i;
                corr[cp++][2] = j;
            }
        }
        qsort(corr, cp, sizeof(double) * 3, cmp1);
        r = 0.0;
        for (int i = 0; i < cp; i++) {
            if (find(corr[i][1]) != find(corr[i][2])) {
                uni(corr[i][1], corr[i][2]);
                if (corr[i][0] > 0) r += corr[i][0];
            }
        }
        printf("%.3f\n", r);
        for (int i = 1; i <= n; i++) g[i] = 0;
    }
    return 0;
}