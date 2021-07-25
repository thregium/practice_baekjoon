#include <stdio.h>
#define FOUT 1
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
���� : N * N(N <= 400) ũ���� Ǯ�翡�� �� ĭ���� Ư���� �縸ŭ Ǯ���� �ִ�. ���ϴ� ��ġ���� ����ư �Ÿ��� K��ŭ ������ ������
Ǯ ���� ���� ���� ū ���� ���Ѵ�.

�ذ� ��� : �밢�� ���� ���� �̿��� �밢�� ���·� Ǯ���� �������� ���� ����, K * K ũ�� �������� ���������� Ǯ�� ����
���� ū �κ��� ã���� �Ѵ�.

�ֿ� �˰��� : ���� ��

��ó : USACO 2014M S2��
*/

int diag[1024][1024];

int big(int a, int b) {
    return a > b ? a : b;
}

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("lazy.in", "r");
        fo = fopen("lazy.out", "w");
    }
    int n, k, x, y, sum, best = 0;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &diag[i + j][n - i + j - 1]);
        }
    }
    x = (n + 1) & 1;
    y = n * 2 - 1;
    for (int i = 0; i < y; i++, x = 1 - x) {
        sum = 0;
        for (int ii = big(i - k, 0); ii < y && ii <= i + k; ii++) {
            for (int iii = big(x - k, 0); iii < y && iii <= x + k; iii++) {
                sum += diag[ii][iii];
            }
        }
        if (sum > best) best = sum;
        for (int ii = x + 1; ii + k < y; ii++) {
            for (int iii = big(i - k, 0); iii < y && iii <= i + k; iii++) {
                if (ii - k >= 1) sum -= diag[iii][ii - k - 1];
                sum += diag[iii][ii + k];
            }
            if ((ii & 1) == x && sum > best) best = sum;
        }
    }
    printf("%d", best);
    return 0;
}