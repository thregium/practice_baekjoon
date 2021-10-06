#include <stdio.h>
#include <stdlib.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
���� : N(N <= 100000)������ �ҵ��� �������� �ִ�. ���� ��ġ�� �ִ� �ҵ��� ���� �ҵ��� ������ 2 ������ �ִ�.
�̶�, ������ ���� �ҵ��� �������� ������ ������ �������� �Ѵٸ�(�� ������ �ְų� �� ������ ���ų�),
�׷��� ��� ��� �� ������ ���� ū �ʺ� ���Ѵ�. ������ �ʺ�� ���� �������� ���� ���ʿ� �ִ� �ҿ�
���� �����ʿ� �ִ� ���� ��ǥ �����̴�. �� �ҵ��� ��ġ�� 0 �̻� 10^9 ������ �����̴�.

�ذ� ��� : ������ ��� ����� �� ������ �ִ�. �� ������ �Ҹ� ��� ����� �� ������ �Ҹ� ��� ����̴�.
�� ������ �Ҵ� �ҵ��� ��ġ�� �����ϸ� ������ ���� �����ϴ�.
�� ������ �Ҹ� ��� ����� �� ���� ǰ���� �Ҹ� +1, �ٸ� ǰ���� �Ҹ� -1�� ���� ����, ���� ���� �̿��ϴ� ���̴�.
���� ������ �� ���� �պ��� ���� ���� ������ �ҿ� ���� �ʰ� ������ ���� ��ġ�� ���� ���� ����, 
���� �� ���� ���̰� ū ���� ���� �ȴ�.

�� ���� ����� �ִ��� ���� ���� ����, �� ū ���� ���� ���� �ȴ�.

�ֿ� �˰��� : ���� ��

��ó : USACO 2014O B2��
*/

int cow[103000][2], lowest[103000 * 2], highest[103000 * 2];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("fairphoto.in", "r");
        fo = fopen("fairphoto.out", "w");
    }
    int n, x, s = 103000, r = 0, last = -1, r2 = 0;
    char b;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %c", &cow[i][0], &b);
        if (b == 'G') cow[i][1] = 1;
        else cow[i][1] = -1;
    }
    qsort(cow, n, sizeof(int) * 2, cmp1);
    for (int i = 0; i < 206000; i++) lowest[i] = -1;
    for (int i = 0; i < n; i++) {
        if (i == 0) last = cow[i][0];
        else if (cow[i][1] != cow[i - 1][1]) {
            if (cow[i - 1][0] - last > r2) r2 = cow[i - 1][0] - last;
            last = cow[i][0];
        }

        if (lowest[s] < 0) lowest[s] = cow[i][0];
        s += cow[i][1];
        if (cow[i][0] > highest[s]) highest[s] = cow[i][0];
    }
    if (cow[n - 1][0] - last > r2) r2 = cow[n - 1][0] - last;
    for (int i = 0; i < 206000; i++) {
        if (lowest[i] < 0) continue;
        if (highest[i] - lowest[i] > r) r = highest[i] - lowest[i];
    }
    printf("%d", r > r2 ? r : r2);
    return 0;
}