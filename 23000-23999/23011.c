#include <stdio.h>

/*
문제 : 3 * 3 크기의 행렬에서 가운데 칸을 제외한 나머지 칸들의 값(|| <= 10^9)이 주어진다.
이때, 가로, 세로, 대각선에 등차수열이 가장 많이 나오도록 가운데 칸의 값을 채운다면,
나올 수 있는 등차수열의 최대 개수를 구한다.

해결 방법 : 가운데 칸을 포함하는 모든 종류의 줄에 대해 등차수열을 만들 수 있다면(양 끝의 차이가 짝수라면)
등차수열을 만들어보고 전체 행렬의 등차수열 개수를 확인해가며 가장 많은 것을 고른다.
등차수열을 만들 수 없는 경우가 나올 수 있으므로 임의의 수로 한번 더 바꾸고 등차수열 개수를 확인해야 한다.

주요 알고리즘 : 수학, 브루트 포스, 케이스 워크

출처 : GKS 2021D A번
*/

long long g[3][3];

int big(int a, int b) {
    return a > b ? a : b;
}

int arithcheck(void) {
    int r = 0;
    for (int i = 0; i < 3; i++) {
        if (g[i][0] - g[i][1] == g[i][1] - g[i][2]) r++;
        if (g[0][i] - g[1][i] == g[1][i] - g[2][i]) r++;
    }
    if (g[0][0] - g[1][1] == g[1][1] - g[2][2]) r++;
    if (g[0][2] - g[1][1] == g[1][1] - g[2][0]) r++;
    return r;
}

int main(void) {
    int t, r;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                scanf("%lld", &g[i][j]);
                if (i == 1 && j == 0) j++;
            }
        }
        r = arithcheck();
        if (~(g[1][0] + g[1][2]) & 1) {
            g[1][1] = g[1][0] + ((g[1][2] - g[1][0]) >> 1);
            r = big(r, arithcheck());
        }
        if (~(g[0][1] + g[2][1]) & 1) {
            g[1][1] = g[0][1] + ((g[2][1] - g[0][1]) >> 1);
            r = big(r, arithcheck());
        }
        if (~(g[0][0] + g[2][2]) & 1) {
            g[1][1] = g[0][0] + ((g[2][2] - g[0][0]) >> 1);
            r = big(r, arithcheck());
        }
        if (~(g[2][0] + g[0][2]) & 1) {
            g[1][1] = g[2][0] + ((g[0][2] - g[2][0]) >> 1);
            r = big(r, arithcheck());
        }
        printf("Case #%d: %d\n", tt, r);
    }
    return 0;
}