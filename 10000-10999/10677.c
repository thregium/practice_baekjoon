#include <stdio.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
���� : �� 3�ڸ� �ڿ����� �־��� ��, �� �� �ڿ����� ���� ���� �� �ִ� �� ���� X, Y(10 <= X, Y <= 15000)�� ���Ѵ�.
X�� Y�� ���� �������� ����ȴ�.

�ذ� ��� : X�� ������ 10���� 15000���� �÷����� Y�� ���� �̺� Ž������ ã�´�. Y���� ���� �� �ڸ� �ڿ����� �����
(���� ū �ڸ��� Y�� �Ѿ���� �����Ѵ�), ������ �ڿ����� �� �ڸ����� ���ؼ� �� ũ�ٸ�
������ ���߰� �� �۴ٸ� ������ ���̸� Ž���ϸ� �ȴ�. ���� ��쿡�� �� ���� ����ϰ� �����Ѵ�.

�ֿ� �˰��� : ����, �̺� Ž��

��ó : USACO 2015J B3��
*/

long long yd[4], yd2[4];

int basem(long long n, long long m) {
    yd2[0] = n / (m * m);
    yd2[1] = n / m % m;
    yd2[2] = n % m;
    for (int i = 0; i < 3; i++) {
        if (yd2[i] != yd[i]) return yd2[i] < yd[i] ? 1 : -1;
    }
    return 0;
}

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("whatbase.in", "r");
        fo = fopen("whatbase.out", "w");
    }
    int k, x, y, l, h, mr = 0;
    long long n;
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        scanf("%d %d", &x, &y);
        yd[0] = y / 100;
        yd[1] = y / 10 % 10;
        yd[2] = y % 10;
        for (long long j = 10; j <= 15000; j++) {
            n = (x / 100) * j * j + (x / 10 % 10) * j + (x % 10);
            l = 10, h = 15000;
            mr = 1;
            while (l <= h) {
                mr = basem(n, (l + h) >> 1);
                if (mr == 0) {
                    printf("%d %d\n", j, (l + h) >> 1);
                    break;
                }
                else if (mr > 0) h = ((l + h) >> 1) - 1;
                else l = ((l + h) >> 1) + 1;
            }
            if (mr == 0) break;
        }
    }
    return 0;
}