#include <stdio.h>
#include <stdlib.h>
#define FOUT 0
#define INF 1012345678
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
���� : ������ N(N <= 100000)���� ���� �������� �����̴� ������ �ִ�. �� ������ ���θ� �߿��� �� ���ٸ�
����� �ð��� ���� �� ������ �� ���� �׷��� �Ǵ��� ���Ѵ�.

�ذ� ��� : ���� ��� �� ���ķ� �� ���� ���� ��Ÿ���� �� ���� �� ���� ���� �׷쿡 �������� �ȴ�.
������ �տ� �ִ� ���� �� �ӵ� �̻��̶�� �������� �ʴ´�. �̸� ������ ���� �����ϸ� �� ���� ���� ���� ��(�Ǵ� ������ �� ��)
���� ������ ����, �� ���� ���ÿ� �߰��ϴ� ���� �ݺ��� ��, ������ ������ ������ ���� ������ ũ�Ⱑ ���� �ȴ�.

�ֿ� �˰��� : �ڷᱸ��, ����

��ó : USACO 2014D B3��
*/

int run[103000][2], stack[103000];
int sz = 0;

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("cowjog.in", "r");
        fo = fopen("cowjog.out", "w");
    }
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &run[i][0], &run[i][1]);
    }
    qsort(run, n, sizeof(int) * 2, cmp1);
    for (int i = 0; i < n; i++) {
        while (sz > 0 && stack[sz - 1] > run[i][1]) sz--;
        stack[sz++] = run[i][1];
    }
    printf("%d", sz);
    return 0;
}