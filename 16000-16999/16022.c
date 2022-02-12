#include <stdio.h>
#include <stdlib.h>
#define INF 0x7A35090F

/*
���� : N(N <= 100)���� ������ ���������� �� ������ ��ġ(|| <= 10^9)�� �־��� ��,
�� ������ ���� ����� ������ ���̰� ���� ���� ���� �ش� ���̸� ���Ѵ�.

�ذ� ��� : ���� ����� ������ ���̴� �� �� ������ �Ÿ��� ���ݰ� ����.
����, ��� ������ ������ ����, 2��° ������ �ڿ��� 2��° ������ ���� �� �� �� ���� �Ÿ���
���� ª�� ���� �� ���� �� ���� ������ �ϸ� �ȴ�.

�ֿ� �˰��� : ����

��ó : CCC 2018S 1��
*/

int a[128];

int small(int a, int b) {
    return a < b ? a : b;
}

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, r = INF;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    qsort(a, n, sizeof(int), cmp1);
    for (int i = 1; i < n - 1; i++) {
        r = small(r, a[i + 1] - a[i - 1]);
    }
    printf("%d.%d", r >> 1, (r & 1) * 5);
    return 0;
}