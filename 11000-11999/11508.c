#include <stdio.h>
#include <stdlib.h>

/*
���� : N(N <= 100000)���� ������ �ִ�. ���� 3���� �������� ��� ���� �� ������ ������ ���� �ʴ´ٸ�
��� ������ ��� ���� �ʿ��� �ݾ��� �ּڰ��� ���Ѵ�.

�ذ� ��� : ������ ��� ������ ���ι޴� ���� �����Ƿ� ���� ���� �������� ���� ��,
3�� ��� ��°�� ������ �������� ���� ������ �ո� ���ϸ� �ȴ�.

�ֿ� �˰��� : �׸��� �˰���, ����

��ó : COCI 15/16#1 2��
*/

int c[103000];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai < bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &c[i]);
    }
    qsort(c, n, sizeof(int), cmp1);
    for (int i = 0; i < n; i++) {
        if (i % 3 != 2) r += c[i];
    }
    printf("%d", r);
    return 0;
}