#include <stdio.h>
#include <stdlib.h>

/*
���� : N(N <= 200000)���� ���� ��ǥ���� �־�����. ��� �� �ֵ��� ����ư �Ÿ� ���� ���Ѵ�.
�� ���� ��ǥ�� 10^6 ������ �ڿ����� �־�����.

�ذ� ��� : �� ���� ��ǥ�� X�� Y�� �����Ͽ� ���� ���ϴ��� ���� �������� �� �� �ִ�.
����, �� 1���� ��ǥ���� ������ ���� �� ������ �Ÿ��� �ߺ� Ƚ���� ���� ���� ���� ���ϸ� �� ����
�Ÿ� ���� �ȴ�. �ߺ� Ƚ���� �� ��ǥ�� ���� �� �� + ū �� ���̰� �Ÿ��� ������ �� ���� ���̴�.
�̸� ����� ���� ���س����� �ȴ�.

�ֿ� �˰��� : ����, ���շ�, ����, ������

��ó : Rocky 2020 G��
*/

int x[204800], y[204800];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n;
    long long r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &x[i], &y[i]);
    }
    qsort(x, n, sizeof(int), cmp1);
    qsort(y, n, sizeof(int), cmp1);
    for (long long i = 1; i < n; i++) {
        r += ((long long)x[i] - x[i - 1]) * i * (n - i);
        r += ((long long)y[i] - y[i - 1]) * i * (n - i);
    }
    printf("%lld", r);
    return 0;
}