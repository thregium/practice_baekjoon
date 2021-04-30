#include <stdio.h>
#include <stdlib.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
���� : �ڿ��� A, B, C(A + B + C <= 10^9, A <= B, B <= C)�� ���� A, B, C, A + B, A + C, B + C, A + B + C�� ������ ������ �������� ��,
A, B, C�� ������� ����Ѵ�.

�ذ� ��� : �־��� 7���� ���� �����Ѵ�. �׷��� ���� ū ���� A + B + C�̰�, ���� ���� �� ���� A, B�� �ȴ�.(A�� C�� ���ϸ� B <= C�̹Ƿ� B���� Ŀ���� ������)
����, ���� ���� 2 ���� ���� ū ������ ���� �� ���� �� ���� ����ϸ� �ȴ�.

�ֿ� �˰��� : ����, ����

��ó : USACO 2020D B1��
*/

int a[7];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("f.in", "r");
        fo = fopen("f.out", "w");
    }
    for (int i = 0; i < 7; i++) {
        scanf("%d", &a[i]);
    }
    qsort(a, 7, sizeof(int), cmp1);
    printf("%d %d %d", a[0], a[1], a[6] - a[0] - a[1]);
    return 0;
}