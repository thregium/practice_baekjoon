#include <stdio.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
���� : N(N <= 100000)������ �ҵ��� �Ϸķ� �ְ�, ������ ǰ���� �־�����. �� ǰ���� 1, 2, 3�� �� �ϳ��̴�.
�̶�, Q(Q <= 100000)���� ������ �����Ѵ�.
[S <= E] ������ �ִ� ǰ�� �� �ҵ��� ���� ���Ѵ�.

�ذ� ��� : ���� ���� �̿��� �� ǰ������ ���� ���� �̸� ������� ���� ������ ���� ��, sum(e) - sum(s - 1)�� ������ָ� �ȴ�.

�ֿ� �˰��� : ���� ��

��ó : USACO 2015D S3��
*/

int breed[103000], sum[103000][3];

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("bcount.in", "r");
        fo = fopen("bcount.out", "w");
    }
    int n, q, s, e;
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &breed[i]);
        sum[i][0] = sum[i - 1][0] + (breed[i] == 1);
        sum[i][1] = sum[i - 1][1] + (breed[i] == 2);
        sum[i][2] = sum[i - 1][2] + (breed[i] == 3);
    }
    for (int i = 0; i < q; i++) {
        scanf("%d %d", &s, &e);
        printf("%d %d %d\n", sum[e][0] - sum[s - 1][0], sum[e][1] - sum[s - 1][1], sum[e][2] - sum[s - 1][2]);
    }
    return 0;
}