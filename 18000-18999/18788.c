#include <stdio.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
���� : N(N <= 100)���� ���� �̷���� �迭���� A1 - A2 ������ ������, B1 - B2 ������ ������ ���� K(K <= 10^9)ȸ �ݺ��� �� �迭�� ����� ����Ѵ�.

�ذ� ��� : �迭���� �ش� ������ ������ ����, 1 - N��° ���� �̵��� ��ġ�� ������ ���´�. �� �� ��� �迭�� �̿��Ͽ�
������ 2^Nȸ ������ ������ �̵� ��ġ���� �����ϰ�, �� ��ġ�� ���� Kȸ ������ ������ �̵� ��ġ���� ���� Ȯ���ϸ� ���ϴ�.

�ֿ� �˰��� : �ڷᱸ��, ��� �迭

��ó : USACO 2020F B3��
*/

int a[128], mv[32][128];

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("swap.in", "r");
        fo = fopen("swap.out", "w");
    }
    int n, k, a1, a2, b1, b2, x;
    scanf("%d %d%d %d%d %d", &n, &k, &a1, &a2, &b1, &b2);
    for (int i = 0; i < n; i++) a[i] = i + 1;
    for (int j = a1, k = a2; j < k; j++, k--) {
        swap(&a[j - 1], &a[k - 1]);
    }
    for (int j = b1, k = b2; j < k; j++, k--) {
        swap(&a[j - 1], &a[k - 1]);
    }
    for (int i = 0; i < n; i++) mv[0][i] = a[i] - 1;
    for (int i = 1; i <= 30; i++) {
        for (int j = 0; j < n; j++) {
            mv[i][j] = mv[i - 1][mv[i - 1][j]];
        }
    }
    for (int i = 0; i < n; i++) {
        x = i;
        for (int j = 0; j <= 30; j++) {
            if (k & (1 << j)) {
                x = mv[j][x];
            }
        }
        printf("%d\n", x + 1);
    }
    return 0;
}