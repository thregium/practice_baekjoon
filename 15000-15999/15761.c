#include <stdio.h>
#include <stdlib.h>

/*
���� : N(N <= 100000)���� ���� ���� �Ѵ�. �� ����� ���� ����� w_i(w_i <= 10^9)�� ������ ��� ���� ����.
������� ���� ������ ������ �� �ִٸ� ���� �ִ��� ���� �� �� ���� ���� ��� ���� ���Ѵ�.

�ذ� ��� : w_i ���� ���� ������� ���� ���� �����̴�. ����, ������������ ������ ����, w_i�� i���� Ŀ���� ���
�׶��� i���� ����ϸ� �ȴ�. �׷��� ��찡 ���ٸ� N�� ����Ѵ�.

�ֿ� �˰��� : �׸��� �˰���, ����

��ó : USACO 2018O S2��
*/

int w[103000];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai < bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &w[i]);
    }
    qsort(w, n, sizeof(int), cmp1);
    for (int i = 0; i < n; i++) {
        if (w[i] < i) {
            printf("%d", i);
            return 0;
        }
    }
    printf("%d", n);
    return 0;
}