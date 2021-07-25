#include <stdio.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
���� : N(N <= 100000)���� ���簢���� ��ǥ���� ĥ�Ѵ�. ��� ĥ�� ���� ���簢���� ��Ȯ�� K�� ������ �κ��� ���̸� ���Ѵ�.
ĥ�ϴ� ���簢���� ��ǥ�� ��� 0 �̻� 1000 ������ �����̴�.

�ذ� ��� : ��ǥ�� ������ ���� ���簢���� ������ �����Ƿ� ���� ���� �̿��� ���簢���� ������ ���Ѵ�.
2���� �������� ���� ���� ��, ������ �Ʒ��� ���� 1 ���̰� ������ ��, ���� �Ʒ��� ���� 1 ���� ����,
2���� �������� ���ϸ� ��� ��ǥ���� ���簢���� ������ ������ �ȴ�. ���� ���⼭ ���� K�� �κи� ã���� �ȴ�.

�ֿ� �˰��� : ���� ��

��ó : USACO 2019F S2��
*/

int diff[1024][1024], sums[1024][1024];

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("paintbarn.in", "r");
        fo = fopen("paintbarn.out", "w");
    }
    int n, k, x1, y1, x2, y2, r = 0;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        diff[x1 + 1][y1 + 1]++;
        diff[x1 + 1][y2 + 1]--;
        diff[x2 + 1][y1 + 1]--;
        diff[x2 + 1][y2 + 1]++;
    }
    for (int i = 0; i <= 1013; i++) {
        for (int j = 1; j <= 1013; j++) {
            sums[i][j] = sums[i][j - 1] + diff[i][j];
        }
    }
    for (int i = 0; i <= 1013; i++) {
        for (int j = 1; j <= 1013; j++) {
            sums[j][i] = sums[j - 1][i] + sums[j][i];
            if (sums[j][i] == k) r++;
        }
    }
    printf("%d", r);
    return 0;
}