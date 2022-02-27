#include <stdio.h>

/*
���� : N(N <= 200000)���� �������� �̷���� Ʈ���� (N - 1) + Q(Q <= 200000)���� ������ �־�����.
�� ������ �����Ѵ�.
0. Ʈ���� Ư�� ������ ���´�.
1. Ʈ���� �� ������ ����� ������ �� ���Ѵ�.
0�� ������ ��Ȯ�� N - 1�� �־����� �������� ������ ���� �ٸ���.

�ذ� ��� : ������ �������� ���鼭 �и� ������ �̿��� Ʈ���� ����� ���ÿ� 1�� ������ ������
���� ���¸� Ȯ���ϰ� ����ϸ� �ȴ�.

�ֿ� �˰��� : �ڷ� ����, �и� ����, �������� ����

��ó : ���� 2016 ��3��
*/

int par[204800], g[204800], query[409600][3], res[204800];

int find(int x) {
    if (!g[x]) return x;
    else return g[x] = find(g[x]);
}

void uni(int x, int y) {
    if (find(x) == find(y)) return;
    g[find(y)] = find(x);
}

int main(void) {
    int n, q, rcnt = 0, p;
    scanf("%d %d", &n, &q);
    for (int i = 2; i <= n; i++) {
        scanf("%d", &par[i]);
    }
    for (int i = 1; i < n + q; i++) {
        scanf("%d %d", &query[i][0], &query[i][1]);
        if (query[i][0]) {
            scanf("%d", &query[i][2]);
            rcnt++;
        }
    }
    p = rcnt - 1;
    for (int i = n + q - 1; i >= 1; i--) {
        if (query[i][0] == 0) uni(query[i][1], par[query[i][1]]);
        else {
            if (find(query[i][1]) == find(query[i][2])) res[p--] = 1;
            else res[p--] = 0;
        }
    }
    for (int i = 0; i < rcnt; i++) {
        printf("%s\n", res[i] ? "YES" : "NO");
    }
    return 0;
}