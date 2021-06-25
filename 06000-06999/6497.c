#include <stdio.h>
#include <stdlib.h>

/*
���� : ������ M���̰� ������ N(M, N <= 200000)���� ���� �׷����� �־��� ��, �ش� �׷����� ������ �����ص� ���� �׷����� �ǵ���
�ϴ� �������� ����ġ �ִ��� ���Ѵ�.

�ذ� ��� : �̴� MST�� �ƴ� ��� ������ ����ġ ���� ���ϴ� �Ͱ� ����, ���� MST�� ���� ���� ��ü ������ ����ġ �տ���
MST�� ����ġ ���� ���ָ� �ȴ�.

�ֿ� �˰��� : �׷��� �̷�, MST

��ó : ULM 2009 D��
*/

int roads[204800][3], g[204800];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int find(int x) {
    if (g[x] == 0) return x;
    else return g[x] = find(g[x]);
}

void uni(int x, int y) {
    g[find(y)] = find(x);
}

int main(void) {
    int m, n, x, y, z, sum = 0, mst = 0;
    while (1) {
        scanf("%d %d", &m, &n);
        if (m == 0) break;
        sum = 0;
        mst = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d %d %d", &x, &y, &z);
            roads[i][0] = z;
            roads[i][1] = x + 1;
            roads[i][2] = y + 1;
            sum += z;
        }
        qsort(roads, n, sizeof(int) * 3, cmp1);

        for (int i = 0; i < n; i++) {
            if (find(roads[i][1]) == find(roads[i][2])) continue;
            uni(roads[i][1], roads[i][2]);
            mst += roads[i][0];
        }
        printf("%d\n", sum - mst);
        for (int i = 1; i <= m; i++) g[i] = 0;
    }
    return 0;
}