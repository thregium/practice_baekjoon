#include <stdio.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
���� : N(N <= 100000)���� ���������� ������ �̸� �� ��, �� ���� �߰��� �� ���� �ٲپ� ���� ���� �̱�� ����� �¸� ���� ���Ѵ�.

�ذ� ��� : ���ʰ� �����ʿ������� ���� �� ���� ���� ���� ���Ѵ�. �� �������δ� ��� ������ ���� �ش� ���� ���ʰ�
�ش� ���� �����ʿ��� ������ �и� ���� �̱�� Ƚ���� ���� ���� ���� ���� �ȴ�.

�ֿ� �˰��� : ���� ��

��ó : USACO 2017J S2��
*/

int hps[103000], suml[103000][3], sumr[103000][3];

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("hps.in", "r");
        fo = fopen("hps.out", "w");
    }
    int n, best = 0;
    char c;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf(" %c", &c);
        if (c == 'H') hps[i] = 0;
        else if (c == 'P') hps[i] = 1;
        else if (c == 'S') hps[i] = 2;
        for (int j = 0; j < 3; j++) suml[i][j] = suml[i - 1][j] + (j == hps[i]);
    }
    for (int i = n; i > 0; i--) {
        for (int j = 0; j < 3; j++) sumr[i][j] = sumr[i + 1][j] + (j == hps[i]);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                if (suml[i - 1][j] + sumr[i][k] > best) best = suml[i - 1][j] + sumr[i][k];
            }
        }
    }
    printf("%d", best);
    return 0;
}