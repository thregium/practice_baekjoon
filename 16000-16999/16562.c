#include <stdio.h>

/*
���� : N(N <= 10000)���� ������ ���� �׷����� �ְ�, �� �������� ����ġ�� �ִ�.
�� �׷����� ���� ��ҿ� ���� ����ġ�� �ּڰ��� ���� ���Ѵ�.

�ذ� ��� : ���Ͽ� ���ε带 ���� ������ �߰��� �� ���� ��ǩ���� ����ġ�� ���� ������ �ű��.
�̸� �ݺ��ϸ� ��� �������� �����Һ��� �������� �и��Ǹ�, ������ ��ǥ ������ ����ġ�� �ּڰ��� �ȴ�.
���� �� �����Ҹ��� �ش� ������ ���ϸ� �ȴ�.

�ֿ� �˰��� : �ڷ� ����, ���Ͽ� ���ε�

��ó : ������ 2018M B��
*/

int g[10240], money[10240];

int find(int x) {
    if (!g[x]) return x;
    return g[x] = find(g[x]);
}

void uni(int x, int y) {
    if (find(x) == find(y)) return;
    g[find(y)] = find(x);
}

int main(void) {
    int n, m, k, v, w;
    long long r = 0;
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &money[i]);
    }
    for (int i = 1; i <= m; i++) {
        scanf("%d %d", &v, &w);
        if (money[find(v)] < money[find(w)]) uni(v, w);
        else uni(w, v);
    }
    for (int i = 1; i <= n; i++) {
        if (!money[find(i)]) continue;
        r += money[find(i)];
        money[find(i)] = 0;
    }
    if (r <= k) printf("%lld", r);
    else printf("Oh no");
    return 0;
}