#include <stdio.h>
#define INF 1012345678
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
문제 : N(N <= 100000)개의 일렬로 늘어선 신호등 가운데 B개의 신호등이 고장나 있고, 각 고장난 신호등의 위치가 주어진다면
연속된 K개의 신호등을 고장나지 않은 상태로 만들기 위해서는 최소 몇 개의 신호등을 고쳐야 하는지 구한다.

해결 방법 : 고장난 신호등의 누적 합을 구해준 후, K번째부터 1칸씩 이동하며 i - k번째의 누적 합과의 비교를 통해 해당 구간의
고장난 신호등 수를 각각 구해준다. 고장난 신호등이 가장 적은 구간에서 고장난 신호등들을 고치면 된다.

주요 알고리즘 : 누적 합, 슬라이딩 윈도우

출처 : USACO 2017F S2번
*/

int broken[103000], sum[103000];

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("maxcross.in", "r");
        fo = fopen("maxcross.out", "w");
    }
    int n, k, b, x, best = INF;
    scanf("%d %d %d", &n, &k, &b);
    for (int i = 0; i < b; i++) {
        scanf("%d", &x);
        broken[x] = 1;
    }
    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + broken[i];
    }
    for (int i = k; i <= n; i++) {
        if (sum[i] - sum[i - k] < best) best = sum[i] - sum[i - k];
    }
    printf("%d", best);
    return 0;
}