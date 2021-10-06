#include <stdio.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
���� : R * C(R, C <= 15) ũ���� ���ڿ� 'R'�� 'B'�� ���� �ִ�. �̶�, ���� ���� �� ĭ���� ����ؼ� ���� ������ �Ʒ� ĭ����
�� ��� �� ���� ū ���� �ٸ� ĭ���� �̵��ϴ� ���� �ݺ��ϸ� ���� ������ �Ʒ� ĭ���� �̵��ϴ� ����� �������� ���Ѵ�.

�ذ� ��� : ���� �� ĭ���� ���ʷ� �̵��ϸ� �ش� ĭ�� ���� ���� �ִ� ��� ĭ�� ��� �ش� ĭ�� �ݴ� ���� ��� ĭ��
�������� ���ϴ� ���� �ݺ��ϸ� �ȴ�. �̶�, �� ���� �� ĭ�� 1�� �ʱ�ȭ�ؾ� �Կ� �����Ѵ�.

�ֿ� �˰��� : DP

��ó : USACO 2015F B3��
*/

char grid[32][32];
int mem[32][32];

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("hopscotch.in", "r");
        fo = fopen("hopscotch.out", "w");
    }
    int r, c;
    scanf("%d %d", &r, &c);
    for (int i = 1; i <= r; i++) {
        scanf("%s", grid[i] + 1);
    }
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            if (i == 1 && j == 1) mem[i][j] = 1;
            for (int ii = 1; ii < i; ii++) {
                for (int jj = 1; jj < j; jj++) {
                    if (grid[i][j] != grid[ii][jj]) mem[i][j] += mem[ii][jj];
                }
            }
        }
    }
    printf("%d", mem[r][c]);
    return 0;
}