#include <stdio.h>

/*
���� : N * M(N, M <= 400)���� 10000 ������ �ڿ��� ��� 2 ��°�� ���� ���� ���� ���� ���Ѵ�.

�ذ� ��� : ���� ��� ���� ���� Ƚ���� ���Ѵ�. �� ���� ���� ���� ���� ���� ���� Ƚ���� ���� ��,
�׺��� �����鼭 ���� ���� ���� ���� ���� Ƚ���� ���� ���� �� ���� ���� Ƚ���� ���� ���� ���� ����ϸ� �ȴ�.

�ֿ� �˰��� : ����

��ó : Latin 2004 G��
*/

int pts[10240];

int main(void) {
    int n, m, x, best, second;
    while (1) {
        scanf("%d %d", &n, &m);
        if (n == 0 && m == 0) break;
        for (int i = 0; i < n * m; i++) {
            scanf("%d", &x);
            pts[x]++;
        }
        best = -1;
        second = -1;
        for (int i = 1; i <= 10000; i++) {
            if (pts[i] > best) best = pts[i];
        }
        for (int i = 1; i <= 10000; i++) {
            if (pts[i] > second && pts[i] < best) second = pts[i];
        }
        for (int i = 1; i <= 10000; i++) {
            if (pts[i] == second) printf("%d ", i);
            pts[i] = 0;
        }
        printf("\n");
    }
    return 0;
}