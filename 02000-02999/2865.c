#include <stdio.h>
#include <stdlib.h>

/*
���� : N(N <= 100)�� ��� K(K <= N)���� ������ �Ѵ�. �� ����� M(M <= 100)���� �帣�� ���� �ɷ�ġ�� �־�����.
�� ����� �� ���� �帣�� �� �� �ִٸ� K���� �ϴ� �ɷ�ġ�� ���� �ִ밡 �� ���� �ɷ�ġ ���� ���Ѵ�.

�ذ� ��� : �� ����� �帣���� �ɷ�ġ�� ���� ������������ �����ϰ�, ���� �ɷ�ġ�� ���� �帣�� �������� �����Ͽ�
��� K���� �̴´�. �� ������� ���� ���� �帣�� �ɷ�ġ ���� ���ϸ� ���� �ȴ�.

�ֿ� �˰��� : �׸��� �˰���, ����

��ó : COCI 10/11#3 3��
*/

double score[128][128];

int cmp1(const void* a, const void* b) {
    double ai = *(double*)a;
    double bi = *(double*)b;
    return ai < bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, m, k, x;
    double r = 0;
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &x);
            scanf("%lf", &score[x - 1][i]);
        }
    }
    for (int i = 0; i < n; i++) {
        qsort(score[i], m, sizeof(double), cmp1);
    }
    qsort(score, n, sizeof(double) * 128, cmp1);
    for (int i = 0; i < k; i++) {
        r += score[i][0];
    }
    printf("%.1f", r);
    return 0;
}