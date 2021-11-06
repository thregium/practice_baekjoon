#include <stdio.h>
#include <stdlib.h>

/*
���� : N(N <= 1000)���� ������ M(M <= 20000)���� �������� �̷���� �׷����� �� ������ ������ ����ġ(<= 100000)�� �־�����
���� ����ġ�� ū ���д� Ʈ���� ����ġ�� ���Ѵ�.

�ذ� ��� : ũ�罺Į �˰����� �ִ񰪿����� ���缺�� ����ȴ�. ����, ũ�罺Į �˰������� MST�� ���ϵ�,
������ �������� �ϸ� �ȴ�.

�ֿ� �˰��� : �׷��� �̷�, MST

��ó : USACO 2004D S2��
*/

int ed[20480][3], g[20480];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai < bi ? 1 : ai == bi ? 0 : -1;
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
    int n, m, r = 0, c = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &ed[i][1], &ed[i][2], &ed[i][0]);
    }
    qsort(ed, m, sizeof(int) * 3, cmp1);
    for (int i = 0; i < m; i++) {
        if (find(ed[i][1]) == find(ed[i][2])) continue;
        uni(ed[i][1], ed[i][2]);
        r += ed[i][0];
        c++;
    }
    if (c < n - 1) printf("-1");
    else printf("%d", r);
    return 0;
}