#include <stdio.h>
#include <stdlib.h>

/*
���� : N(N <= 1000)���� ������ ���� �׷������� ����ġ�� ���� ��� ���·� �־��� ��,
������ �ִ��� �����Ͽ��� ���� �׷����� �ǵ��� �� �� ���� ������ ����ġ �� ��� �ּڰ��� ���Ѵ�.

�ذ� ��� : �ּ� ���д� Ʈ���� ���ϸ� �ȴ�.

�ֿ� �˰��� : �׷��� �̷�, MST

��ó : ȫ�ʹ� 2018 E��
*/

int ed[1048576][3], g[1024];

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
    int n;
    long long r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &ed[i * n + j][0]);
            ed[i * n + j][1] = i + 1;
            ed[i * n + j][2] = j + 1;
        }
    }
    qsort(ed, n * n, sizeof(int) * 3, cmp1);
    for (int i = 0; i < n * n; i++) {
        if (find(ed[i][1]) == find(ed[i][2])) continue;
        r += ed[i][0];
        uni(ed[i][1], ed[i][2]);
    }
    printf("%lld", r);
    return 0;
}