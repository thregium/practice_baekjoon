#include <stdio.h>
#include <stdlib.h>

/*
���� : N(N <= 10000)���� ����� ������ �־��� ��, �� ���� �־��� 7���� ���ڸ��� ���
��ġ�� �ʴ� ���ڸ��� ������ ����� �ִ� �� ���ϰ�, �ִٸ� �� ������� ������ ������������ ����Ѵ�.
��ġ�� ���ϵ� ��� ����Ѵ�.

�ذ� ��� : �켱 7���� ���ڸ����� �����ϰ�, �� �ķδ� �� ���ڸ��� ��ġ�� �ʴ� ����� ���� ���� ���ÿ�
�� ������� ������ �����Ѵ�. �׷��� ����� �ϳ��� �ִٸ� ������ ������ �� ��� ����ϸ� �ȴ�.

�ֿ� �˰��� : ����, ����

��ó : �Ѿ�� 8ȸB E��
*/

int zod[12] = { 120, 219, 321, 420, 521, 622, 723, 823, 923, 1023, 1123, 1222 };
int occu[12], res[10240][2];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    if (ai != bi) return ai > bi ? 1 : -1;
    ai = *((int*)a + 1);
    bi = *((int*)b + 1);
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int getzod(int x) {
    for (int i = 0; i < 12; i++) {
        if (x < zod[i]) return i;
    }
    return 0;
}

int main(void) {
    int n, x, y, r = 0;
    for (int i = 0; i < 7; i++) {
        scanf("%d %d", &x, &y);
        occu[getzod(x * 100 + y)]++;
    }
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &x, &y);
        if (occu[getzod(x * 100 + y)] == 0) {
            res[r][0] = x;
            res[r++][1] = y;
        }
    }
    qsort(res, r, sizeof(int) * 2, cmp1);
    if (r == 0) printf("ALL FAILED");
    else {
        for (int i = 0; i < r; i++) {
            printf("%d %d\n", res[i][0], res[i][1]);
        }
    }
    return 0;
}