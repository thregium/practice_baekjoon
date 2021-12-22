#include <stdio.h>
#include <stdlib.h>

/*
���� : N(N <= 1000)���� �������� �̷���� ������ �Ķ� �������� �̾��� ���� �׷����� �־�����.
�̶�, �� �׷����� ���д� Ʈ�� ��� �Ķ� ������ ��Ȯ�� K���� ���� �ִ� �� ���Ѵ�.

�ذ� ��� : �� �׷����� ���д� Ʈ������ ������ �Ķ� ������ ���� ���������� ���������. �� ������ �� ���д� Ʈ������ �� ������
���� �ٸ� ����(��, ���� �ٸ� �κп� �ִ�)�� ������ ���ο� ���д� Ʈ���� �Ǵµ�, ���� ���ٸ� �Ķ� ������ ���� ���� ���̰�,
���� ���� ������ �Ķ�, ���� ������ �����̸� 1 �þ��, �� �ݴ��� 1 �پ��� ������ ������ ���� �ȿ����� ������ �ȴ�.

������ ������ �׸����ϰ� �׷����� �����Ͽ� �� �� �ִ�. �Ķ� ������ ���� ���� ���� �켱 �Ķ� �������� �ִ���
������ ���� �������� ���� �������� ä�� ����̰�, ���� ���� ���� �� �ݴ�� �� ����̴�.
K�� �ش� ���� �ȿ� �ִٸ� �׷��� ��찡 �ִ� ���̰�, ���� ���� ����� �׷��� ��찡 ���� ���̴�.

�ֿ� �˰��� : �׷��� �̷�, �׸��� �˰���, MST

��ó : UCIPC 2012 G��
*/

int ed[1048576][3], g[1024];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int cmp2(const void* a, const void* b) {
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
    int n, m, k, x, y, lo, hi;
    char c;
    //freopen("E:\\PS\\University\\NAIPC\\2012\\redblue.in", "r", stdin);
    while (1) {
        scanf("%d %d %d", &n, &m, &k);
        if (n == 0) break;
        for (int i = 0; i < m; i++) {
            scanf(" %c %d %d", &c, &ed[i][1], &ed[i][2]);
            ed[i][0] = (c == 'B');
        }
        lo = 0, hi = 0;
        qsort(ed, m, sizeof(int) * 3, cmp1);
        for (int i = 0; i < m; i++) {
            if (find(ed[i][1]) != find(ed[i][2])) {
                uni(ed[i][1], ed[i][2]);
                lo += ed[i][0];
            }
        }
        for (int i = 1; i <= n; i++) g[i] = 0;
        qsort(ed, m, sizeof(int) * 3, cmp2);
        for (int i = 0; i < m; i++) {
            if (find(ed[i][1]) != find(ed[i][2])) {
                uni(ed[i][1], ed[i][2]);
                hi += ed[i][0];
            }
        }
        for (int i = 1; i <= n; i++) g[i] = 0;
        
        printf("%d\n", k >= lo && k <= hi);
    }
    return 0;
}