#include <stdio.h>
#define FOUT 1
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
문제 : N * N(N <= 400) 크기의 풀밭에서 각 칸마다 특정한 양만큼 풀들이 있다. 원하는 위치에서 맨해튼 거리로 K만큼 떨어진 영역의
풀 수의 합이 가장 큰 곳을 구한다.

해결 방법 : 대각선 누적 합을 이용해 대각선 형태로 풀들의 누적량을 구한 다음, K * K 크기 영역들을 움직여가며 풀의 양이
가장 큰 부분을 찾도록 한다.

주요 알고리즘 : 누적 합

출처 : USACO 2014M S2번
*/

int diag[1024][1024];

int big(int a, int b) {
    return a > b ? a : b;
}

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("lazy.in", "r");
        fo = fopen("lazy.out", "w");
    }
    int n, k, x, y, sum, best = 0;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &diag[i + j][n - i + j - 1]);
        }
    }
    x = (n + 1) & 1;
    y = n * 2 - 1;
    for (int i = 0; i < y; i++, x = 1 - x) {
        sum = 0;
        for (int ii = big(i - k, 0); ii < y && ii <= i + k; ii++) {
            for (int iii = big(x - k, 0); iii < y && iii <= x + k; iii++) {
                sum += diag[ii][iii];
            }
        }
        if (sum > best) best = sum;
        for (int ii = x + 1; ii + k < y; ii++) {
            for (int iii = big(i - k, 0); iii < y && iii <= i + k; iii++) {
                if (ii - k >= 1) sum -= diag[iii][ii - k - 1];
                sum += diag[iii][ii + k];
            }
            if ((ii & 1) == x && sum > best) best = sum;
        }
    }
    printf("%d", best);
    return 0;
}