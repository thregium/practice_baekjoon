#include <stdio.h>
#define INF 1012345678

/*
문제 : N(N <= 10^6)개의 자연수들 가운데 최솟값과 최댓값을 각각 구한다.

해결 방법 : 최솟값과 최댓값을 각각 무한대와 -무한대로 초기화시킨 뒤, 수를 받을 때 마다 최솟값보다 작거나 최댓값보다 크다면
각 값들을 갱신시켜준다. 마지막에 나오는 수가 수열 전체의 최솟값과 최댓값이다.

주요 알고리즘 : 구현
*/

int main(void) {
    int t, n, x, lo, hi;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &n);
        lo = INF;
        hi = -INF;
        for (int i = 0; i < n; i++) {
            scanf("%d", &x);
            if (x > hi) hi = x;
            if (x < lo) lo = x;
        }
        printf("%d %d\n", lo, hi);
    }
    return 0;
}