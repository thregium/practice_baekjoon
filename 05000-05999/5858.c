#include <stdio.h>
#include <stdlib.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
���� : N(N <= 100000)�� �¿�� �̵��� ����� �־��� ��, 2�� �̻� �̵��� ������ ���̸� ���Ѵ�.
��������� �־ 10^9 �̳��θ� �̵��Ͽ���.

�ذ� ��� : �������� ���� �ذ� �����ϴ�. �� ������ �������� ������ ���� �迭�� �ְ� ��ġ ������ ������ ����,
�������� ���� �� ���� ���� �ø��� ������ ���� �� ���� ���� ���̴ٰ� 1���� 2�� �ö󰡸� �ش� ��ġ�� ����ϰ�
2���� 1�� �������� ����� ��ġ���� ���̸� ���ϴ� �ᱣ���� ���ϴ� ����̴�.

�ֿ� �˰��� : ����, ������

��ó : USACO 2013J B2��
*/

int paint[204800][2];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("paint.in", "r");
        fo = fopen("paint.out", "w");
    }
    int n, lx = 0, x = 0, u, coat = 0, r = 0;
    char dr;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %c", &u, &dr);
        if (dr == 'L') x -= u;
        else x += u;
        paint[i * 2][0] = lx;
        paint[i * 2 + 1][0] = x;
        if (lx < x) paint[i * 2 + 1][1] = 1;
        else paint[i * 2][1] = 1;
        lx = x;
    }
    qsort(paint, n * 2, sizeof(int) * 2, cmp1);

    for (int i = 0; i < n * 2; i++) {
        if (paint[i][1]) {
            coat--;
            if (coat == 1) r += paint[i][0] - lx;
        }
        else {
            coat++;
            if (coat == 2) lx = paint[i][0];
        }
    }
    printf("%d", r);
    return 0;
}