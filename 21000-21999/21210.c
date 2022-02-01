#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
���� : X * Y(X, Y <= 10^6) ũ���� ���簢���� N(N <= 1000)���� ������� �ִ�.
�� �������� �Ÿ��� �ִ��� �ָ� �ϸ� (0, 0)���� (X, Y)�� �̵��Ϸ��� �� ��, �ٸ� ����� ���� ���������
������ �Ÿ��� ���Ѵ�.

�ذ� ��� : �� ��� ���� �̵� ������ ��θ� �����ϸ鼭 �Ÿ��� �־��� �� ���� ��� ���̸� ���ĳ�����.
�̷��� ���ٰ� ���� ���ֺ��� �� �� �Ǵ� �Ա��� �ⱸ�� �´��� �� ���� �������� �� ���� �Ÿ��� ���ϸ� �ȴ�.
��η� �� �� �ִ� �� ������� �����Ÿ��� �� ��� ���� �Ÿ� / 2 �Ǵ� ����� ���� �Ÿ��� ����.
�̸� ��� ���� ����, ũ�罺Į �˰���� ���� �Ÿ��� ª�� ������ ������ �� �̵� �Ұ����� �� ����
�Ÿ��� �÷�������.

�ֿ� �˰��� : �ڷ� ����, ���Ͽ� ���ε�, ũ�罺Į

��ó : SWERC 2020 C��
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