#include <stdio.h>
#include <stdlib.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
���� : 1���� N(N <= 100)������ �ڿ����� �̷���� ���̾��� 3�� �ִ� �ݰ� �ִ�. �ݰ��� �� ���� ��й�ȣ�� �ִµ�,
�� ���� ��й�ȣ �� �ϳ��� ��й�ȣ�� ��� ���̾��� ���̰� 2 ������ ��� �ݰ� ������.
�ݰ� ���� ����� �������� ���Ѵ�. N���� 1���� ����Ǿ� �ִ�.

�ذ� ��� : N�� ����� �����Ƿ� N^3���� ��츦 ���� Ȯ���ϸ� �ݰ� ������ ��츦 ���� ã���� �ȴ�.
�� ��й�ȣ�� ���� �� ���� ���̸� Ȯ���Ѵ�. �� ���� ���̴� N�� ���� ���� ���غ��� Ȯ�� �����ϴ�.
��� ���̰� 2 ������ ��� �ݰ� ������ ����̴�.

�ֿ� �˰��� : ����, ���Ʈ ����

��ó : USACO 2013N B1��
*/

int john[3], master[3];

int small(int a, int b) {
    return a < b ? a : b;
}

int getdiff(int n, int a, int b) {
    if (a > b) return small(abs(a - b), abs(b + n - a));
    else return small(abs(b - a), abs(a + n - b));
}

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("combo.in", "r");
        fo = fopen("combo.out", "w");
    }
    int n, r = 0;
    scanf("%d", &n);
    scanf("%d %d %d%d %d %d", &john[0], &john[1], &john[2], &master[0], &master[1], &master[2]);
    for (int i = 1; i <= n; i++) {
        if (getdiff(n, i, john[0]) > 2 && getdiff(n, i, master[0]) > 2) continue;
        for (int j = 1; j <= n; j++) {
            if (getdiff(n, j, john[1]) > 2 && getdiff(n, j, master[1]) > 2) continue;
            for (int k = 1; k <= n; k++) {
                if (getdiff(n, i, john[0]) <= 2 && getdiff(n, j, john[1]) <= 2 && getdiff(n, k, john[2]) <= 2) r++;
                else if (getdiff(n, i, master[0]) <= 2 && getdiff(n, j, master[1]) <= 2 && getdiff(n, k, master[2]) <= 2) r++;
            }
        }
    }
    printf("%d", r);
    return 0;
}