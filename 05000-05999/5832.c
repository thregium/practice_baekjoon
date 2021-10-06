#include <stdio.h>
#include <stdlib.h>
#define FOUT 0
#define INF 1012345678
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
���� : 1���� N(N <= 10^9)������ ���� ������� �ִ�. �̶�, K(K <= 1000)���� ���� ���� ���� ������ ���� �� ���ٸ�
��� ���� ������ ������ ���� �ּڰ��� ���Ѵ�.

�ذ� ��� : �� �ֵ��� ���� ���� �������� �����Ѵ�. �� ����, �� �ֵ��� Ȯ���ϸ� ���� ���� �� ���� ���� ���� ���� ã�´�.
���� ���� ���� ���� ���� ���� �� ���� ������ �ִٸ� �װ����� ���ο� ������ �����ϰ� �ٽ� ���� ���� ���� ������ ������ �ȴ�.

�ֿ� �˰��� : �׸��� �˰���, ����

��ó : USACO 2013O B3��
*/

int unfr[1024][2];

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("photo.in", "r");
        fo = fopen("photo.out", "w");
    }
    int n, k, high = INF, r = 1;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < k; i++) {
        scanf("%d %d", &unfr[i][0], &unfr[i][1]);
        if (unfr[i][0] > unfr[i][1]) swap(&unfr[i][0], &unfr[i][1]);
    }
    unfr[k][0] = n;
    qsort(unfr, k, sizeof(int) * 2, cmp1);
    for (int i = 0; i <= k; i++) {
        if (unfr[i][0] >= high) {
            r++;
            high = INF;
        }
        if (unfr[i][1] < high) high = unfr[i][1];
    }
    printf("%d", r);
    return 0;
}