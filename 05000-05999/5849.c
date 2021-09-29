#include <stdio.h>
#include <stdlib.h>
#define FOUT 0
#define INF 1012345678
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
���� : �� ���༱ ���̸� N(N <= 100000)���� ������ �̾���. �� ������ �� ���� ��ġ�� �־��� ��, �������� �ʴ� ���� ������ ���Ѵ�.
�� ���� �� �� ��ǥ�� +- 10^6 ������ �ڿ����̸�, ���� ������ �����ϰų� ������ ���� ����.

�ذ� ��� : ���� ���� �κ��� ��ǥ�� �������� ������ ������ ����, ������� ������ Ȯ���Ѵ�.
���� ���ݱ��� ���Դ� ������ ��ǥ�� ������ �����ʿ��� ������ ���̶�� ���ÿ� �ش� ���� �߰��Ѵ�.
�ƴ� ��쿡�� ���ÿ��� �ش� ���� ������ �� ���Ŀ� ������ ��� ������ �����.
�̸� �ݺ��Ͽ� ��� ���� Ȯ���� ����, ���ÿ� ���� ���� ������ ���� �ȴ�.

�ֿ� �˰��� : �ڷᱸ��, ����

��ó : USACO 2013F B3��
*/

int cross[103000][2], stack[103000];
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
        fi = fopen("crossings.in", "r");
        fo = fopen("crossings.out", "w");
    }
    int n, last = -INF;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &cross[i][0], &cross[i][1]);
    }
    qsort(cross, n, sizeof(int) * 2, cmp1);
    for (int i = 0; i < n; i++) {
        if ((sz <= 0 || cross[i][1] > stack[sz - 1]) && cross[i][1] > last) {
            stack[sz++] = cross[i][1];
            last = cross[i][1];
        }
        else {
            while (sz > 0 && stack[sz - 1] >= cross[i][1]) sz--;
        }
    }
    printf("%d", sz);
    return 0;
}