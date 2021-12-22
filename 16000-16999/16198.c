#include <stdio.h>

/*
문제 : N(N <= 10)개의 자연수(<= 1000)가 주어질 때, 문제에 주어진 방식대로 합하여 얻을 수 있는 가장 많은 에너지 양을 구한다.
(과정 생략)

해결 방법 : 모든 경우의 수를 확인하면 된다. 재귀적으로 들어간다. 

주요 알고리즘 : 브루트 포스, 재귀
*/

int w[16][16];
int best = 0;

int big(int a, int b) {
    return a > b ? a : b;
}

void track(int n, int l, int r) {
    if (n == 2) {
        if (r > best) best = r;
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) w[l + 1][j] = w[l][j];
        for (int j = i; j < n; j++) w[l + 1][j] = w[l][j + 1];
        track(n - 1, l + 1, r + w[l][i - 1] * w[l][i + 1]);
    }
}

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &w[0][i]);
    }
    track(n, 0, 0);
    printf("%d", best);
    return 0;
}