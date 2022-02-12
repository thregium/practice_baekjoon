#include <stdio.h>
#include <stdlib.h>

/*
���� : 1���� N(N <= 4 * 10^6)������ �ڿ����� ���� ī�� ��� M(M <= N)���� ī�尡 �־��� ��,
K(K <= 10000)���� ������ �����Ѵ�.
X�� �־��� ��, X���� ū ���� ���� ī�带 ����, �� ī�带 ������.

�ذ� ��� : �� ī����� ������ ����, �̺� Ž���� ���� �� ī�带 ã���� �ȴ�.
��, N�� M�� �ſ� ũ�� ������ �� �������� ����ȭ�� ���� �ʿ��ϴ�. ������ ī���� ��Ʈ�� �ϰų�
�и� ������ ����ϰų� fast io ���� �̿��ϴ� ���� ����� ����ؾ� �Ѵ�.

�ֿ� �˰��� : ����ȭ, ����, �̺� Ž��

��ó : ������ 2018M F��
*/

int card[4194304], g[4194304];

int find(int x) {
    if (!g[x]) return x;
    else return g[x] = find(g[x]);
}

void uni(int x, int y) {
    if (find(x) == find(y)) return;
    g[find(y)] = find(x);
}

int lb(int* a, int n, int p) {
    int l = 1, h = n, m;
    while (l < h) {
        m = (l + h) >> 1;
        if (a[m] >= p) h = m;
        else l = m + 1;
    }
    return l;
}

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, m, k, x, y;
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < m; i++) {
        scanf("%d", &x);
        card[x] = 1;
    }
    y = 1;
    for (int i = 1; i <= n; i++) {
        if (card[i]) {
            card[y++] = i;
        }
    }
    if (y != m + 1) return 1;
    for (int i = 0; i < k; i++) {
        scanf("%d", &x);
        y = lb(card, m, x + 1);
        printf("%d\n", card[find(y)]);
        uni(find(y) + 1, y);
    }
    return 0;
}