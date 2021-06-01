#include <stdio.h>
#include <stdlib.h>

/*
���� : N(N <= 2^20, N�� 2^x)���� ���� �̷���� ������ K(K <= N, K�� 2^y)���� �������� ������ ���� ������ ����� ���Ѵ�.

�ذ� ��� : ������ K���� �κ����� ������ ���� �����ϸ� �ȴ�.

�ֿ� �˰��� : ����

��ó : ���ϴ� 2015 H��
*/

int a[1048576];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, k;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        qsort(a + i * (n / k), (n / k), sizeof(int), cmp1);
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}