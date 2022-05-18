#include <stdio.h>
#include <stdlib.h>

/*
���� : N(N <= 26)���� ���ÿ� 75�� ������ ���ΰ� �ִ�. �� ���ô� ����Ǿ��ְ�, �� ���δ� ���� 100 ���Ϸ�
�� ���ø� �����Ѵ�. �̶�, ��� ���ø� ����� ���·� �ϸ鼭 ���θ� �ּ������� ���� ��,
���� ���� ���� �ּڰ��� ���Ѵ�.

�ذ� ��� : MST�� ���ؼ� �� ũ�⸦ ����ϸ� �ȴ�. ũ�罺Į �˰����� �̿��� �� �ִ�.

�ֿ� �˰��� : �׷��� �̷�, MST

��ó : MidC 2002 G��
*/

int road[128][3], uf_g[32];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int uf_find(int x) {
    if (uf_g[x] < 0) return x;
    else return uf_g[x] = uf_find(uf_g[x]);
}

void uf_uni(int x, int y) {
    if (uf_find(x) == uf_find(y)) return;
    uf_g[uf_find(y)] = uf_find(x);
}

int main(void) {
    int n, m, x, rcnt, res;
    char st, ed;
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        rcnt = 0;
        for (int i = 1; i < n; i++) {
            scanf(" %c %d", &st, &m);
            for (int j = 0; j < m; j++) {
                scanf(" %c %d", &ed, &x);
                road[rcnt][0] = x;
                road[rcnt][1] = st - 'A';
                road[rcnt++][2] = ed - 'A';
            }
        }
        qsort(road, rcnt, sizeof(int) * 3, cmp1);

        res = 0;
        for (int i = 0; i < 26; i++) uf_g[i] = -1;
        for (int i = 0; i < rcnt; i++) {
            if (uf_find(road[i][1]) == uf_find(road[i][2])) continue;
            else {
                res += road[i][0];
                uf_uni(road[i][1], road[i][2]);
            }
        }
        printf("%d\n", res);
    }
    return 0;
}