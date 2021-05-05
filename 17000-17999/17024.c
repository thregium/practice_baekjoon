#include <stdio.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
���� : N(N <= 100000)���� ����� �̷���� Ʈ������ Ʈ���� ���� ���°� �־��� ��, �� �������� ������ ��� ����� ���� �ٸ��� �Ϸ��� �ʿ��� �ּ� ���� ���� ���Ѵ�.

�ذ� ��� : ���� ����� ��尡 ���� �������� ������ ��� ����� ���� �ٸ��� �ϸ� �ȴ�. ���� ���� ����� ��尡 ���� ������ ����� ����� �� + 1�� ����.

�ֿ� �˰��� : �׸��� �˰���, Ʈ��

��ó : USACO 2019J S1��
*/

int cnt[103000];

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("planting.in", "r");
        fo = fopen("planting.out", "w");
    }
    int n, a, b, r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++) {
        scanf("%d %d", &a, &b);
        cnt[a]++;
        cnt[b]++;
        if (cnt[a] > r) r = cnt[a];
        if (cnt[b] > r) r = cnt[b];
    }
    printf("%d", r + 1);
    return 0;
}