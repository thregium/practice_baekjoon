#include <stdio.h>
#include <stdlib.h>
#define INF 1012345678

/*
���� : N * 2(N <= 5000)���� �ڿ���(<= 100000)�� �־��� ��, �ڿ����� 2���� ¦��� ���� ���� ���� ����
���� ũ�� �Ϸ��� �� ��, �� ���� ���Ѵ�.

�ذ� ��� : �ڿ������� ������ ����, �� ���������� ���� ���س����� �׵� ��� ���� ���� ���� ���ϴ� ���� �ּ��̴�.

�ֿ� �˰��� : �׸��� �˰���, ����

��ó : Seoul 2020I I��
*/

int a[10240];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, r = INF;
    scanf("%d", &n);
    for (int i = 0; i < n * 2; i++) {
        scanf("%d", &a[i]);
    }
    qsort(a, n * 2, sizeof(int), cmp1);
    for (int i = 0; i < n; i++) {
        if (a[i] + a[n * 2 - i - 1] < r) r = a[i] + a[n * 2 - i - 1];
    }
    if (r == INF) return 1;
    printf("%d", r);
    return 0;
}