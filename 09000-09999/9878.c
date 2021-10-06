#include <stdio.h>
#include <stdlib.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
���� : 1m/s�� �ӵ��� �̵��ϴ� ���� �ִ�. �� ���� ������ �Ÿ��� �̵��ϰų� ������ �ð��� �Ǹ� �ӵ��� ��������
N(N <= 10000)���� ������ �־��� ��, 1000m�� �̵��ϴ� �� �ɸ��� �ð��� ���Ѵ�. ���� �ݿø��Ͽ� ����Ѵ�.
�� �� ������ �� ���� �ӵ��� 1m/s -> (1/2)m/s -> (1/3)m/s -> (1/4)m/s ... ������ �پ���.

�ذ� ��� : �� �Ÿ��� ��ġ�� ������ ����, �Ź� �� ���� ������ �ͱ��� �̵��Ͽ� �װ����� �ӵ��� ���δ�.
���� �Ÿ������� �ҿ� �ð��� ���� �ð����� �̵� �Ÿ��� �ӵ��� �̿��ϸ� ������ ���� �� �ִ�.
�ӵ��� �پ�� ���� �ӵ��� 1 / (1 / spd + 1)��� ������ ���� �� �ִ�.
1000m�� �Ǵ� ������ ���� �ҿ� �ð��� ���ؼ� ����Ѵ�. �Ÿ� �迭�� 1000�� ����ְ� �����ϴ� �͵� ����.

�ֿ� �˰��� : ����, ����, ����

��ó : USACO 2014J B2/S1��
*/

int tm[10300], dt[10300];
int ttp = 0, ddp = 0;

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("slowdown.in", "r");
        fo = fopen("slowdown.out", "w");
    }
    int n, x, ti = 0, di = 0;
    char c;
    double time = 0.0, dist = 0.0, spd = 1.0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf(" %c %d", &c, &x);
        if (c == 'D') dt[ddp++] = x;
        else if (c == 'T') tm[ttp++] = x;
        else return 1;
    }
    dt[ddp++] = 1000.0;
    qsort(dt, ddp, sizeof(int), cmp1);
    qsort(tm, ttp, sizeof(int), cmp1);

    for (int i = 0; i <= n; i++) {
        if (ti == ttp || (di != ddp && (dt[di] - dist) / spd + time < tm[ti])) {
            time += (dt[di] - dist) / spd;
            dist = dt[di++];
            if (abs(dist - 1000.0) < 0.00001) {
                printf("%.0f", time);
                return 0;
            }
        }
        else {
            dist += (tm[ti] - time) * spd;
            time = tm[ti++];
        }
        spd = 1 / (1 / spd + 1);
    }
    return 1;
}