#include <stdio.h>

/*
문제 : N(N <= 50)개의 서로 다른 정수(0 <=, <= 100)가 주어질 때, 최댓값과 최솟값을 제외한 합을 구한다.

해결 방법 : 모든 수의 합을 구하며 최댓값과 최솟값을 구하고, 합에서 두 값을 빼면 된다.

주요 알고리즘 : 구현

출처 : JOIG 2022 1번
*/

int main(void) {
    int n, x, hi = -1, lo = 103000, s = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        s += x;
        if (x > hi) hi = x;
        if (x < lo) lo = x;
    }
    printf("%d", s - hi - lo);
    return 0;
}