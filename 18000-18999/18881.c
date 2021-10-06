#include <stdio.h>
#include <stdlib.h>
#define FOUT 0
#define INF 1012345678
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
���� : N(N <= 1000)������ �ҵ��� ��ġ(<= 10^6)�� �������� �ɷȴ��� ���ΰ� �־�����. Ư���� �Ÿ� R �̳���
�������� �ɸ� �Ұ� �ִٸ� �����ȴٰ� �� ��, ó�� �������� �ɸ� �Ұ� �ּ� �� �������� ���Ѵ�.

�ذ� ��� : Ư���� �Ÿ� R�� ���� ���� �������� ó�� �ɸ� �Ұ� ���� ���� ������ �� �� �ִ�.
R�� �� �� �ִ� ���� ū ���� �������� �ɸ� �ҿ� �ɸ��� ���� ���� ���� ����� �Ÿ� - 1�̴�.
R�� �� �� �ִٸ� �������� R �Ÿ� ���� �������� �ɸ� �Ұ� �ִ� ���� �Ѿ�� �������� �ɸ� ���� �������� ����
���ʷ� �������� �ɸ� ���� �������� �� �� �ִ�.

�ֿ� �˰��� : ����, ����

��ó : USACO 2020O B2��
*/

int cow[1024][2];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("socdist2.in", "r");
        fo = fopen("socdist2.out", "w");
    }
    int n, r = 0, rng = INF;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &cow[i][0], &cow[i][1]);
    }
    qsort(cow, n, sizeof(int) * 2, cmp1);
    for (int i = 1; i < n; i++) {
        if (cow[i][1] + cow[i - 1][1] == 1 && cow[i][0] - cow[i - 1][0] < rng) {
            rng = cow[i][0] - cow[i - 1][0];
        }
    }
    for (int i = 0; i < n; i++) {
        if (cow[i][1] == 0) continue;
        if (i > 0 && cow[i][0] - cow[i - 1][0] < rng) continue;
        r++;
    }
    printf("%d", r);
    return 0;
}