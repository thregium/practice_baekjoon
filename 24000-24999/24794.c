#include <stdio.h>
#include <stdlib.h>

/*
���� : N(N <= 64)���� ī�忡 ���� ��(0 <=, <= 10000, ����)���� �־��� ��, ó�� C(0 <= C < N)����
ī��� �ѱ� ���� �� ������ ū ī�尡 ������ ����ٰ� �Ѵ�. (������ ������ ������ �ʴ´�.).
�̶�, ������ ī�忡 ���� ���� ����� ���Ѵ�.

�ذ� ��� : C���� �̾Ƽ� ���� ���� ū ī���� ���� ���� ���� �� �ִ� ����� ���� ����� ���ϰ�,
�̸� ���� ���� ���� �ٽ� ��ü ����� ���� ������ �ȴ�. ���� ū ���� ������ ���� ��� �����
�� ū ���� ����̰� ����� ���� (��°�� - 1)_C_(c-1)�̴�.
���� ū ī�带 �̾Ҵٸ� ����� ���� ���� ����, ����� ���� ū ���� ������ ��� ���� ����̴�.
��ü ����� ���� N_C_c�̴�.
��, C�� 0�� ��쿡�� ��ü ����� ���� �ǹǷ� ���� ó���� �ϴ� ���� ����.

�ֿ� �˰��� : ����, Ȯ����, ���շ�

��ó : VTH 2017 B��
*/

int a[64];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, c;
    double tot = 1, sum = 0, cmb, tsum;
    scanf("%d %d", &n, &c);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    if (c == 0) {
        for (int i = 0; i < n; i++) {
            sum += a[i];
        }
        printf("%.9f", sum / n);
        return 0;
    }
    for (int i = n; i > n - c; i--) tot *= i;
    for (int i = 1; i <= c; i++) tot /= i;
    qsort(a, n, sizeof(int), cmp1);
    for (int i = c; i < n; i++) {
        cmb = 1;
        for (int j = i - 1; j > i - c; j--) cmb *= j;
        for (int j = 1; j < c; j++) cmb /= j;
        tsum = 0;
        for (int j = i; j < n; j++) tsum += a[j];
        tsum /= n - i;
        sum += tsum * cmb;
    }
    cmb = 1;
    for (int i = n - 1; i > n - c; i--) cmb *= i;
    for (int i = 1; i < c; i++) cmb /= i;
    tsum = 0;
    for (int i = 0; i < n - 1; i++) tsum += a[i];
    tsum /= n - 1;
    sum += tsum * cmb;
    printf("%.9f", sum / tot);
    return 0;
}