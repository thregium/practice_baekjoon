#include <stdio.h>
#include <stdlib.h>

/*
���� : N(N <= 1000)���� ������ M(M <= 10000)���� �������� �̷���� �׷������� �������� �� ���� �� �� ������ ���� ĥ�ߴ�.
���� ���� �ٸ� ������ �����ϴ� �������� �̷���� �׷��� ��� ���� �׷����� �Ǵ� ���� ���� ���� ����ġ�� ���Ѵ�.
�׷��� ���� ���ٸ� -1�� ����Ѵ�.

�ذ� ��� : ���� �ٸ� ������ �����ϴ� �������� �߸� ���� MST�� ����� �ȴ�.

�ֿ� �˰��� : �׷��� �̷�, MST

��ó : ���ϴ� 2017 J��
*/

int univ[1024], g[1024], road[10240][3];

int find(int x) {
    if (!g[x]) return x;
    else return g[x] = find(g[x]);
}

void uni(int x, int y) {
    if (find(x) == find(y)) return;
    g[find(y)] = find(x);
}

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, m, rsz = 0, cnt = 1, r = 0;
    char c;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf(" %c", &c);
        if (c == 'M') univ[i] = 1;
    }
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &road[rsz][1], &road[rsz][2], &road[rsz][0]);
        if (univ[road[rsz][1]] != univ[road[rsz][2]]) rsz++;
    }
    qsort(road, rsz, sizeof(int) * 3, cmp1);
    for (int i = 0; i < rsz; i++) {
        if (find(road[i][1]) == find(road[i][2])) continue;
        r += road[i][0];
        uni(road[i][1], road[i][2]);
        cnt++;
        if (cnt == n) {
            printf("%d", r);
            return 0;
        }
    }
    printf("-1");
    return 0;
}