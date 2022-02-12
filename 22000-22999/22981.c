#include <stdio.h>
#include <stdlib.h>
#define INF 1234567890987654321

/*
���� : N(2 <= N <= 200000)���� �۾� �ӵ�(<= 10^9)�� �־��� ��, �� ���� ������ �۾��ϸ�
K(K <= 10^18)�� �۾����� ���� �۾� �ð��� ���Ѵ�.
�� ���� �۾� �ð��� �ο��� * ���� ���� ����� �۾� �ӵ��̴�. �� ���� �ο��� �ּ� 1�� �̻� �ʿ��ϴ�.

�ذ� ��� : ���� ���� ����� �ִ� ���� �ִ��� ���� ����� �о�ִ� ���� �������� �� �� �ִ�.
����, ��� ����� �۾� �ð� ������ ������ ����, �� ���� ������ ��� ��츦 ���캸��
�� �� ���� �۾� �ð��� ���� ���� ���ϸ� �ȴ�.

�ֿ� �˰��� : �׸��� �˰���, ����, ���Ʈ ����

��ó : SUAPC 2021S A��
*/

int a[204800];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

long long small(long long a, long long b) {
    return a < b ? a : b;
}

long long divu(long long u, long long d) {
    return (u + d - 1) / d;
}

int main(void) {
    int n;
    long long k, res = INF;
    scanf("%d %lld", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    qsort(a, n, sizeof(int), cmp1);
    for (long long i = 1; i < n; i++) {
        res = small(res, divu(k, a[0] * i + a[i] * (n - i)));
    }
    printf("%lld", res);
    return 0;
}