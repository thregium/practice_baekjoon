#include <stdio.h>
#include <stdlib.h>

/*
���� : N(N <= 1000)���� ���� ���� �ο� Ƚ��(<= 10000)�� �־��� ��, H-�ε����� ���Ѵ�.

�ذ� ��� : �ο� Ƚ���� ������������ ������ ����, ������ �ο� Ƚ������ Ŀ���� ������ ���� - 1�� ����ϸ� �ȴ�.
���ٸ� N�� ����Ѵ�.

�ֿ� �˰��� : ����, ����

��ó : Daejeon 2016I I��
*/

int a[1024];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai < bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    qsort(a, n, sizeof(int), cmp1);
    for (int i = 0; i < n; i++) {
        if (a[i] <= i) {
            printf("%d", i);
            return 0;
        }
    }
    printf("%d", n);
    return 0;
}