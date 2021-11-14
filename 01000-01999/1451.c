#include <stdio.h>

/*
문제 : N * M(N, M <= 50) 크기의 직사각형의 각 칸들에 숫자들이 쓰여 있다. 이 직사각형을 3개의 직사각형으로 나누어
각 칸에 쓰인 숫자들의 합의 곱이 최대가 될 때의 그 값을 구한다.

해결 방법 : 브루트 포스를 통해 전체 직사각형을 3개로 나누는 모든 방법을 시도하고 그들 가운데 가장 큰 값을 구한다.
전체 직사각형은 재귀적으로 나누는 것이 좋다.

주요 알고리즘 : 브루트 포스, 재귀
*/

char s[64][64];

int big(int a, int b) {
    return a > b ? a : b;
}

long long track(int n, int xl, int xh, int yl, int yh) {
    long long r = 0;
    if (n == 1) {
        for (int i = xl; i <= xh; i++) {
            for (int j = yl; j <= yh; j++) r += s[i][j] - '0';
        }
        return r;
    }

    for (int i = xl; i < xh; i++) {
        if (n == 3) {
            r = big(r, track(1, xl, i, yl, yh) * track(2, i + 1, xh, yl, yh));
            r = big(r, track(2, xl, i, yl, yh) * track(1, i + 1, xh, yl, yh));
        }
        else r = big(r, track(1, xl, i, yl, yh) * track(1, i + 1, xh, yl, yh));
    }
    for (int i = yl; i < yh; i++) {
        if (n == 3) {
            r = big(r, track(1, xl, xh, yl, i) * track(2, xl, xh, i + 1, yh));
            r = big(r, track(2, xl, xh, yl, i) * track(1, xl, xh, i + 1, yh));
        }
        else r = big(r, track(1, xl, xh, yl, i) * track(1, xl, xh, i + 1, yh));
    }
    return r;
}

int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s", s[i]);
    }
    printf("%lld", track(3, 0, n - 1, 0, m - 1));
    return 0;
}