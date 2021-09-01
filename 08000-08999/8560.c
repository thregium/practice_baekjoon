#include <stdio.h>
#include <stdlib.h>

/*
���� : L / 2^M(M <= 10)(L <= 2^M) ���� �м��� N(N <= 20000)�� �־��� ��, �м����� ũ�� ������ �����Ѵ�.
��, ���� ũ���� �м����� L�� ���� ������������ �����Ѵ�.

�ذ� ��� : �� �м����� L / 2^10�� ����� �� �������ָ� �ȴ�. ���� ����� ���� ���ٸ� L ������ �����Ѵ�.

�ֿ� �˰��� : ����, ����

��ó : PA 2001 2-1��
*/

int weights[20480][2];

int cmp1(const void* a, const void* b) {
    int al = *(int*)a;
    int bl = *(int*)b;
    int am = *((int*)a + 1);
    int bm = *((int*)b + 1);
    if ((al << (10 - am)) != (bl << (10 - bm))) return (al << (10 - am)) > (bl << (10 - bm)) ? 1 : -1;
    else return al > bl ? 1 : al == bl ? 0 : -1;
}

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &weights[i][0], &weights[i][1]);
    }
    qsort(weights, n, sizeof(int) * 2, cmp1);
    for (int i = 0; i < n; i++) {
        printf("%d %d\n", weights[i][0], weights[i][1]);
    }
    return 0;
}