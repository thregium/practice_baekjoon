#include <stdio.h>
#include <stdlib.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
���� : N(N <= 20000)������ �ҵ��� �ְ�, ������ �ҵ��� ������ �µ� ������ �ִ�. �� ���� ���� �ִٸ� �� �Ҵ� Y��ŭ��
������ �����ϰ�, �� �̸��̶�� X, �׸� �ʰ��Ѵٸ� Z��ŭ�� ������ �����Ѵ�. ���� ������ ���� ������ ���� ������ ���� ���Ѵ�.
�µ��� ������ 10^9 ������ �ڿ����̰�, X, Y, Z�� 0 �̻� 1000 �̸��� �����̴�.

�ذ� ��� : ��� �ҵ��� �µ� ������ �������� ���� + 1(Z��ŭ �����ϱ� ���۵Ǵ� ����)�� �����Ѵ�.
�� ����, ���� ���귮�� X * N���� ���� ���� ���� �µ����� �������� Ȯ���ϱ� �����Ѵ�. �µ� ������ �������� ������
Y - X(X���� Y�� ��ȯ)�� ���ϰ�, ������ ������ Z - Y(Y���� Z�� ��ȯ)�� ���Ѵ�.
���� �µ��� ���������� ������ ���� �ִ񰪰� ���� �ִ��� �����ϰ� ���� �ִ��� ���ϸ� �ȴ�.

�ֿ� �˰��� : ����, ������

��ó : USACO 2013N B2��
*/

int tst[40960][2];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("milktemp.in", "r");
        fo = fopen("milktemp.out", "w");
    }
    int n, x, y, z, res = 0, milk;
    scanf("%d %d %d %d", &n, &x, &y, &z);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &tst[i * 2][0], &tst[i * 2 + 1][0]);
        tst[i * 2 + 1][0]++;
        tst[i * 2 + 1][1] = 1;
    }
    tst[n * 2][0] = -1;
    qsort(tst, n * 2, sizeof(int) * 2, cmp1);

    milk = x * n;
    for (int i = 0; i < n * 2; i++) {
        if (tst[i][1]) milk += z - y;
        else milk += y - x;
        if (tst[i][0] != tst[i + 1][0] && milk > res) res = milk;
    }
    printf("%d", res);
    return 0;
}