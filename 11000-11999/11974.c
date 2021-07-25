#include <stdio.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
���� : N(N <= 50000)���� �� ��� Ư���� ������ ����� �� ������ ���� 7�� ����� �Ǵ� ���� ū ������ ���̸� ���Ѵ�.

�ذ� ��� : �� ��������� ���� ���� ���Ѵ�. �� �������δ� ���� ���� 7�� ���� �������� 0���� 6������ ������
���� ���� ������ ���� ���� �������� ���� ���Ѵ�. �� �� ���ʿ� ���� ������ ���� ���� ������ ���� ū ������ �ȴ�.

�ֿ� �˰��� : ����, ������, ���� ��

��ó : USACO 2016J S2��
*/

int ids[51200], best[7][2];
long long sums[51200];

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("div7.in", "r");
        fo = fopen("div7.out", "w");
    }
    int n, r = 0;
    scanf("%d", &n);
    for (int i = 0; i < 7; i++) {
        best[i][0] = n;
        best[i][1] = 0;
    }
    best[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &ids[i]);
        sums[i] = sums[i - 1] + ids[i];
        if (i < best[sums[i] % 7][0]) best[sums[i] % 7][0] = i;
        if (i > best[sums[i] % 7][1]) best[sums[i] % 7][1] = i;
    }
    for (int i = 0; i < 7; i++) {
        if (best[i][1] - best[i][0] > r) r = best[i][1] - best[i][0];
    }
    printf("%d", r);
    return 0;
}