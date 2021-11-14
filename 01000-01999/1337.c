#include <stdio.h>
#include <stdlib.h>

/*
���� : N(N <= 50)���� ���� �ƴ� ���� �ٸ� ����(<= 10^9)�� �̷���� �迭�� ���� ��, �迭���� ������ 5���� ������
�������� �ϱ� ���� �߰��ؾ� �ϴ� ������ �ּ� ������ ���Ѵ�.

�ذ� ��� : �迭�� ������ ����, ��� ������ �ش� ������ 5���� ���� ������ �� ���� ���� ���� + 1�� ���� ���Ѵ�.
�� ���� ���� ū ���� ���ϰ�, �� ���� 5���� ���� ���� �ȴ�.

�ֿ� �˰��� : ����, �� ������
*/

int a[64];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, r = 5, p;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    qsort(a, n, sizeof(int), cmp1);
    for (int i = 0; i < n; i++) {
        for (p = i; p >= 0 && a[i] - a[p] < 5; p--);
        if (5 - (i - p) < r) r = 5 - (i - p);
    }
    printf("%d", r);
    return 0;
}