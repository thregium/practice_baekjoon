#include <stdio.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
문제 : N(N <= 50000)개의 수 가운데 특정한 구간을 골랐을 때 구간의 합이 7의 배수가 되는 가장 큰 구간의 길이를 구한다.

해결 방법 : 각 수들까지의 누적 합을 구한다. 그 다음으로는 누적 합을 7로 나눈 나머지가 0부터 6까지인 수들의
최초 등장 지점과 최종 등장 지점들을 각각 구한다. 그 중 최초와 최종 지점이 가장 넓은 구간이 가장 큰 구간이 된다.

주요 알고리즘 : 수학, 정수론, 누적 합

출처 : USACO 2016J S2번
*/

int ids[51200], best[7][2];
long long sums[51200];

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("div7.in", "r");
        fo = fopen("div7.out", "w");
    }
    int n, r = 0;
    scanf("%d", &n);
    for (int i = 0; i < 7; i++) {
        best[i][0] = n;
        best[i][1] = 0;
    }
    best[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &ids[i]);
        sums[i] = sums[i - 1] + ids[i];
        if (i < best[sums[i] % 7][0]) best[sums[i] % 7][0] = i;
        if (i > best[sums[i] % 7][1]) best[sums[i] % 7][1] = i;
    }
    for (int i = 0; i < 7; i++) {
        if (best[i][1] - best[i][0] > r) r = best[i][1] - best[i][0];
    }
    printf("%d", r);
    return 0;
}