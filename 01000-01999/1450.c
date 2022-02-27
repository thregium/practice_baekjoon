#include <stdio.h>
#include <stdlib.h>

/*
���� : N(N <= 30)���� ���� ����(<= 10^9)�� �־��� ��, ��ü ������ ���� C(C <= 10^9) ���ϰ� �ǵ���
������ �δ� ����� ���Ѵ�. �ƹ��͵� ���� �ʴ� �͵� ��ȿ�� ����̴�.

�ذ� ��� : ������ ������ ������ �켱 ��� ����� ���� ���� ������ �д�.
�׸��� ������ ���ݿ� ���� ��� ��츦 Ȯ���ϸ鼭 �̺� Ž������ ���� ���� ���
���԰� �µ��� �δ� ����� �������� ���س����� �ȴ�.

�ֿ� �˰��� : �� �� �� �̵�, �̺� Ž��

��ó : ?
*/

int a[32];
long long weigh[32768];

int cmp1(const void* a, const void* b) {
    long long ai = *(long long*)a;
    long long bi = *(long long*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, c, n1, n2, lo, hi, mid;
    long long s, r = 0;
    scanf("%d %d", &n, &c);
    n1 = n >> 1;
    n2 = n - n1;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < (1 << n1); i++) {
        for (int j = 0; j < n1; j++) {
            weigh[i] += a[j] * ((i >> j) & 1);
        }
    }
    qsort(weigh, (1LL << n1), sizeof(long long), cmp1);
    for (int i = 0; i < (1 << n2); i++) {
        s = 0;
        for (int j = 0; j < n2; j++) {
            s += a[j + n1] * ((i >> j) & 1);
        }
        lo = -1, hi = (1 << n1) - 1;
        while (lo < hi) {
            mid = (lo + hi + 1) >> 1;
            if (weigh[mid] + s <= c) lo = mid;
            else hi = mid - 1;
        }
        r += lo + 1;
    }
    printf("%lld", r);
    return 0;
}