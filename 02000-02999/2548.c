#include <stdio.h>
#include <stdlib.h>

/*
���� : N(N <= 20000)���� �ڿ����� �־��� ��, �־��� ��� �ڿ��������� ������ ���� ���� ���� �� ��� ���� ���� ���� ���Ѵ�.

�ذ� ��� : �߾Ӱ�(¦������ ��� �� �߾Ӱ� ������ ��)�� �� ���� ������ ���� �۴�. �̴� ������ ���� �ſ� ���� ���� �� �ִ�.

�ֿ� �˰��� : �׸��� �˰���, ����

��ó : ���� 2009 ��1��
*/

int a[20480];

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
    printf("%d", a[(n - 1) >> 1]);
    return 0;
}