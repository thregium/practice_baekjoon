#include <stdio.h>
#include <stdlib.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
���� : N(N <= 100)������ �ҵ鿡�Լ� ������ ¥�� �Ѵ�. �� �ҿ��Լ� ������ ¥�� �ð��� s���� t(s, t <= 1000)������ ������ �ְ�,
�� �ҿ��Լ� ������ ¥�µ� �ʿ��� �絿���� ���� B(B <= 10)���� ������ �ִٰ� �Ѵٸ�, ������ ¥�µ� �ʿ��� �絿���� �ּ� ���� ���Ѵ�.
����, ���ÿ� �� �絿�̷� ���� �ҵ鿡�Լ� ������ © ���� ����.

�ذ� ��� : s�� ���� ������� ������ ������ ����, ���� ����� �� �ִ� �絿�̸� ��ȣ�� ���� �� ���� ã�´�.
ã�� �絿�̴� t���� ����� �� ���� ���·� ����س��´�. ������ ������ Ȯ���� ���� ���� ū ��ȣ�� �絿�̰� ������ ���� ��ȣ�� ���� �ȴ�.

�ֿ� �˰��� : ����, �ùķ��̼�, �׸��� �˰���

��ó : USACO 2018D B2��
*/

int list[128][3], bucket[1024][1024];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("blist.in", "r");
        fo = fopen("blist.out", "w");
    }
    int n, p, mx = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &list[i][0], &list[i][1], &list[i][2]);
    }
    qsort(list, n, sizeof(int) * 3, cmp1);

    for (int i = 0; i < n; i++) {
        p = 0;
        for (int j = 0; j < list[i][2]; j++) {
            while (bucket[p][list[i][0]]) p++;
            for (int k = list[i][0]; k <= list[i][1]; k++) {
                bucket[p][k] = i + 1;
            }
            if (p > mx) mx = p;
        }
    }
    printf("%d", mx + 1);
    return 0;
}