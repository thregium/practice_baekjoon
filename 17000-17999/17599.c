#include <stdio.h>
#include <stdlib.h>

/*
���� : N(N <= 100000)���� �ڿ���(<= 10^9)�� �־��� ��, �־��� �ڿ����� �������� ���Ѵ�.

�ذ� ��� : �ڿ������� ������ ����, ���� ���� ���̰� �ִ� ��(�� ������ ��)�� ������ ���ϸ� �ȴ�.

�ֿ� �˰��� : ����

��ó : TOPC 2019 B��
*/

int a[103000];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    qsort(a, n, sizeof(int), cmp1);
    for (int i = 0; i < n; i++) {
        if (a[i] != a[i + 1]) r++;
    }
    printf("%d", r);
    return 0;
}