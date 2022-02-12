#include <stdio.h>
#include <stdlib.h>

/*
���� : N(N <= 1000)���� ������ ��� K(K <= N)���, K���� ���� ������ ����� �հݽ�Ű���� �Ѵ�.
�� ����� ����(<= 1000, �ڿ���)�� �־��� ��, �հ��� ���� ���Ѵ�.

�ذ� ��� : ��� ����� ������ ������������ ������ ��, K��°�� ���� ������ ������ ���������
�ο����� ���ϸ� ���� �ȴ�.

�ֿ� �˰��� : ����, ����

��ó : Brasil 2017 F��
*/

int a[1024];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai < bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, k, r;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    qsort(a, n, sizeof(int), cmp1);
    r = k - 1;
    while (r < n - 1 && a[r] == a[r + 1]) r++;
    printf("%d", r + 1);
    return 0;
}