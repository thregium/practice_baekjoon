#include <stdio.h>
#include <stdlib.h>

/*
���� : N(N <= 15)���� ���� �־��� ��, �� ���� ���ʷ� �����ư��� ���� �������� �ڽ��� ������ ���� ���� �ִ�� �Ϸ� �Ѵ�.
�̶�, �� ���� �������� ���� ���� ���Ѵ�.

�ذ� ��� : �� ���� ������������ �����ϸ� Ȧ����°�� ������ ��������, ¦����°�� �İ��� �������� ���� �� �� �ִ�.
������ �����ָ� ���� �ȴ�.

�ֿ� �˰��� : �׸��� �˰���, ����

��ó : BAPC 2017 F��
*/

int arr[16];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai < bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, a = 0, b = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    qsort(arr, n, sizeof(int), cmp1);
    for (int i = 0; i < n; i += 2) a += arr[i];
    for (int i = 1; i < n; i += 2) b += arr[i];
    printf("%d %d", a, b);
    return 0;
}