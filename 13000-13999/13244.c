#include <stdio.h>

/*
���� : �־��� �׷����� Ʈ������ �Ǻ��Ѵ�.

�ذ� ��� : �־��� �׷����� ����Ŭ�� �ִٸ� Ʈ���� �ƴϴ�. �̰��� ���Ͽ� ���ε带 ���� ���� �ذ� �����ϴ�.
����, ��� �׷����� �ϳ��� ���� ��ҷ� �̷������ �ϴµ�, �� ���� ���Ͽ� ���ε�� �ذ� �����ϴ�.

�ֿ� �˰��� : �׷��� �̷�, Ʈ��, ���Ͽ� ���ε�

��ó : AIPO 2016F 5��
*/

int g[1024];

int find(int x) {
    if (!g[x]) return x;
    else return g[x] = find(g[x]);
}

void uni(int x, int y) {
    g[find(x)] = find(y);
}

int main(void) {
    int t, n, m, a, b, r;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d%d", &n, &m);
        r = 0;
        for (int i = 0; i < m; i++) {
            scanf("%d %d", &a, &b);
            if (find(a) == find(b)) r = 1; //������ ������ �̹� ���� ������ ��� Ʈ���� �ƴϴ�.
            else uni(a, b);
        }
        for (int i = 1; i <= n; i++) {
            if (find(1) != find(i)) r = 1; //������ ��� ������ �Ŀ��� 1�� ������ ���� �ٸ� ������ ������ �ִ� ��� Ʈ���� �ƴϴ�.
        }
        printf("%s\n", r ? "graph" : "tree");
        for (int i = 1; i <= n; i++) g[i] = 0;
    }
    return 0;
}