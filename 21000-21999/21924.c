#include <stdio.h>
#include <stdlib.h>

/*
���� : N(N <= 100000)���� ������ M(M <= 500000)���� ������ ���� �׷������� MST�� ���� ������ ��� ���� ���Ѵ�.
MST�� ��������� �ʴ� ��� -1�� ����Ѵ�.

�ذ� ��� : ũ�罺Į �˰����� �̿��� MST�� ���� ���� ��ü ������ �հ� ���� ���� ����Ѵ�. ��, ������ N - 1ȸ����
���� ��������ٸ� MST�� �ϼ����� �������Ƿ� -1�� ����ؾ� �Ѵ�.

�ֿ� �˰��� : �׷��� �̷�, MST
*/

int road[524288][3], g[103000];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
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
    int n, m, cnt = 0;
    long long s = 0, r = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &road[i][1], &road[i][2], &road[i][0]);
        s += road[i][0];
    }
    qsort(road, m, sizeof(int) * 3, cmp1);
    for (int i = 0; i < m; i++) {
        if (find(road[i][1]) == find(road[i][2])) continue;
        r += road[i][0];
        cnt++;
        uni(road[i][1], road[i][2]);
    }
    if (cnt < n - 1) printf("-1");
    else printf("%lld", s - r);
    return 0;
}