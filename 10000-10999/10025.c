#include <stdio.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
문제 : N(N <= 100000)개의 얼음이 직선 상의 X_i(X_i <= 10^6) 위치에 각각 존재한다. 각 얼음의 크기는 g_i(g_i <= 10000)이다.
이때, 특정한 지점에서 주위 K(K <= 2 * 10^6) 거리 안에 있는 얼음의 크기 합이 최대가 되도록 하면
그때의 얼음의 크기 합을 구한다.

해결 방법 : 미리 누적 합을 통해 전체 값들을 전처리 해준 다음, 0부터 100만까지의 모든 수에 대해 주위 K 거리 안의
얼음 크기 합들을 확인하며 가장 큰 것을 고른다.

주요 알고리즘 : 누적 합

출처 : USACO 2014M B2번
*/

int bucket[1048576], sum[1048576];

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("lazy.in", "r");
        fo = fopen("lazy.out", "w");
    }
    int n, k, g, x, r = 0, psum;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &g, &x);
        bucket[x + 1] = g;
    }
    for (int i = 1; i <= 1000001; i++) {
        sum[i] = bucket[i] + sum[i - 1];
    }
    for (int i = 0; i <= 1000001; i++) {
        psum = sum[(i + k > 1000001 ? 1000001 : i + k)] - sum[(i - k - 1 < 0 ? 0 : i - k - 1)];
        if (psum > r) r = psum;
    }
    printf("%d", r);
    return 0;
}