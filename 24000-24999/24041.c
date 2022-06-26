#include <stdio.h>
#include <stdlib.h>
#define MX 2147483647

/*
���� : N(N <= 200000)���� ������ ������Ѱ� ���� �ӵ�, �߿��� �� ���ΰ� �־�����,
�߿����� ���� ��Ḧ K������ ���� ������ ���� G(G <= 10^9) ���ϰ� �� �� �ִ�
������ �Դ� ������ ������ ���Ѵ�. �׻� 1�������� ������ ���� �� �ֵ��� �־�����.

�ذ� ��� : ������ �Դ� �������� �Ű� ���� Ž���� �Ѵ�. �Ź� ������ �� ���� G ������ �� Ȯ���ϸ� �ȴ�.
�� ������ �� ����� ������ ���� �� ����, ������������ �����ϰ� �׸����ϰ� ������ ������ Ȯ���� �� �ִ�.
��, ��� �������� �����÷ο� �����Ѵ�. Ư�� ������ ���� �� ������ ���� G�� �Ѿ�� �ٷ� �����ؾ�
�����÷θ� ������ �� �ִ�. ����, ������ �ִ��� 2 * 10^9�ӿ��� �����Ѵ�.

�ֿ� �˰��� : �׸��� �˰���, �Ķ��Ʈ��, ����

��ó : GBOJ 2021 C��
*/

unsigned long long mkt[204800][3], germ[204800][2];

int cmp1(const void* a, const void* b) {
    unsigned long long ai = *(unsigned long long*)a;
    unsigned long long bi = *(unsigned long long*)b;
    return ai < bi ? 1 : ai == bi ? 0 : -1;
}

int edible(unsigned long long n, unsigned long long g, unsigned long long k, unsigned long long m) {
    unsigned long long sum = 0;
    for (int i = 0; i < n; i++) {
        if (m <= mkt[i][1]) germ[i][0] = mkt[i][0];
        else germ[i][0] = mkt[i][0] * (m - mkt[i][1]);
        germ[i][1] = mkt[i][2];
    }
    qsort(germ, n, sizeof(unsigned long long) * 2, cmp1);
    for (int i = 0; i < n; i++) {
        if (k > 0 && germ[i][1] == 1) {
            k--;
            continue;
        }
        sum += germ[i][0];
        if (sum > g) return 0;
    }
    return 1;
}

int main(void) {
    unsigned long long n, g, k, lo = 0, hi = MX, mid;
    scanf("%llu %llu %llu", &n, &g, &k);
    for (int i = 0; i < n; i++) {
        scanf("%llu %llu %llu", &mkt[i][0], &mkt[i][1], &mkt[i][2]);
    }
    while (lo < hi) {
        mid = (lo + hi + 1) >> 1;
        if (edible(n, g, k, mid)) lo = mid;
        else hi = mid - 1;
    }
    printf("%llu", lo);
    return 0;
}