#include <stdio.h>
#include <stdlib.h>

/*
���� : N(N <= 100000)���� ����(|| <= 100000)�� �־��� ��, ��� �� ���� ���� ���̵�
L(L <= 100000) �̻��� �ǵ��� �ϱ� ���� �����ؾ� �ϴ� ������ ������ ���Ѵ�.

�ذ� ��� : ������ ������ �� 1��° ������ ���̸� L�� �θ� ���� �� �ִ� ������ �ִ� ������ ���Ѵ�.
�̸� N���� ���� ���� �ȴ�.

�ֿ� �˰��� : �׸��� �˰���, ����

��ó : Tehran 2020 J��
*/

int a[103000];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, l, r = 1, last;
    scanf("%d %d", &n, &l);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    qsort(a, n, sizeof(int), cmp1);
    last = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] - last >= l) {
            r++;
            last = a[i];
        }
    }
    printf("%d", n - r);
    return 0;
}