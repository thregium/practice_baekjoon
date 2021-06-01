#include <stdio.h>
#include <stdlib.h>

/*
���� : N(N <= 500000)���� ���� �����Ͽ� ����Ѵ�.

�ذ� ��� : �����ϰ� ����Ѵ�.

�ֿ� �˰��� : ����

��ó : �뱸���� 2018 0��
*/

int a[524288];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    qsort(a, n, sizeof(int), cmp1);
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}