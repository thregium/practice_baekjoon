#include <stdio.h>
#include <stdlib.h>

/*
���� : N(N <= 5 * 10^6)���� �ڿ���(<= 10000)�� ���� ��, ������ ��, ������ ������ ���� ����
���� �۰� ����� �� �� ���� ���� ���� ���Ѵ�.

�ذ� ��� : ù ��°�� �߾Ӱ��̰�, �� ��°�� ����̴�. �̸� ���� ���ϸ� �ȴ�.

�ֿ� �˰��� : ����, ����

��ó : ���� 2009 ��1��
*/

int a[5242880];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n;
    long long sum = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        sum += a[i];
    }
    qsort(a, n, sizeof(int), cmp1);
    printf("%d %lld", a[(n - 1) >> 1], (sum + (n + 1) / 2 - 1) / n);
    return 0;
}