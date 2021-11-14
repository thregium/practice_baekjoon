#include <stdio.h>

/*
���� : N(N <= 10^6)���� ������ K(K <= 100000)���� �������� �̷���� �׷������� M(M <= 100000)���� ����
���� ���� ��ҿ� ���ϴ��� ���θ� ���Ѵ�.

�ذ� ��� : ���Ͽ�-���ε带 ���� �̸� �������� �����Ų ��, M���� �ֿ� ���� �� ���� ���� ���տ� ���ϴ��� ���ϸ� �ȴ�.

�ֿ� �˰��� : �ڷ� ����, ���Ͽ� ���ε�

��ó : TUD 2008S 1��
*/

int g[1048576];

int find(int x) {
    if (!g[x]) return x;
    else return g[x] = find(g[x]);
}

void uni(int x, int y) {
    if (find(x) == find(y)) return;
    g[find(y)] = find(x);
}

int main(void) {
    int t, n, k, m, a, b;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        scanf("%d%d", &n, &k);
        for (int i = 0; i < k; i++) {
            scanf("%d %d", &a, &b);
            a++, b++;
            uni(a, b);
        }
        scanf("%d", &m);
        printf("Scenario %d:\n", tt);
        for (int i = 0; i < m; i++) {
            scanf("%d %d", &a, &b);
            a++, b++;
            printf("%d\n", find(a) == find(b));
        }
        printf("\n");
        for (int i = 0; i <= n; i++) g[i] = 0;
    }
    return 0;
}