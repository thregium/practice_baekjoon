#include <stdio.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
문제 : N(N <= 100000)마리의 소들이 일렬로 있고, 각각의 품종이 주어진다. 각 품종은 1, 2, 3번 중 하나이다.
이때, Q(Q <= 100000)개의 쿼리에 응답한다.
[S <= E] 구간에 있는 품종 별 소들의 합을 구한다.

해결 방법 : 누적 합을 이용해 각 품종들의 누적 합을 미리 계산해준 다음 쿼리가 들어올 때, sum(e) - sum(s - 1)을 계산해주면 된다.

주요 알고리즘 : 누적 합

출처 : USACO 2015D S3번
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