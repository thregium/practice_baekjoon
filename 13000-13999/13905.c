#include <stdio.h>
#include <stdlib.h>

/*
���� : N(N <= 100000)���� ������ M(M <= 300000)���� �������� �̷���� �׷������� ���� S�� ���� E ���� �̵��ϴ� ��ΰ�
����� ���ؼ� �־�� �ϴ� ���� ��� �ּҸ� ���Ѵ�. �̵� �Ұ����� ��� 0�� ����Ѵ�.

�ذ� ��� : ũ�罺Į �˰����� ���� �� �������� ������ ū ������ ������ ����, S�� E�� ����Ǵ� ������ ������ ���ؼ�
�׶��� ������ ����ϸ� �ȴ�.

�ֿ� �˰��� : �׷��� �̷�, MST

��ó : ������ 12ȸC F��
*/

int brd[327680][3], g[103000];

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
    return ai < bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, m, s, e;
    scanf("%d %d", &n, &m);
    scanf("%d %d", &s, &e);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &brd[i][1], &brd[i][2], &brd[i][0]);
    }
    qsort(brd, m, sizeof(int) * 3, cmp1);
    for (int i = 0; i < m; i++) {
        uni(brd[i][1], brd[i][2]);
        if (find(s) == find(e)) {
            printf("%d", brd[i][0]);
            return 0;
        }
    }
    printf("0");
    return 0;
}