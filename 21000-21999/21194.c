#include <stdio.h>
#include <stdlib.h>

/*
���� : N(N <= 100000)���� ���� �ƴ� ����(<= 10000)�� �̷���� �迭�� �־��� ��, �� �迭�� ���� ��
K(K <= N)���� ���� �̾Ƽ� ������ �� ���� �� �ִ� ���� ū ���� ���Ѵ�.

�ذ� ��� : ���� ū ������ ���س����� �ȴ�. ������������ �����ϰ� ���� K���� ���� ���Ѵ�.

�ֿ� �˰��� : �׸��� �˰���, ����

��ó : SWERC 2020-2021 PB��
*/

int g[103000];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai < bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, k, r = 0;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &g[i]);
    }
    qsort(g, n, sizeof(int), cmp1);
    for (int i = 0; i < k; i++) {
        r += g[i];
    }
    printf("%d", r);
    return 0;
}