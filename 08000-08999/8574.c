#include <stdio.h>

/*
문제 : N(N <= 100000)개의 점(<= 10000, 음이 아닌 정수)이 주어질 때, (X, Y)(X, Y <= 10000, 음이 아닌 정수)에서
떨어진 거리가 K(K <= 100000)보다 큰 점의 개수를 구한다.

해결 방법 : 각 점에 대해 (X, Y)와의 거리의 제곱을 구한다. 이 값이 K의 제곱보다 큰 경우를 세면 된다.

주요 알고리즘 : 기하학, 피타고라스 정리

출처 : JPOI 2012 1-4번
*/

int main(void) {
    int n, k, x, y, xi, yi, r = 0;
    scanf("%d %d %d %d", &n, &k, &x, &y);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &xi, &yi);
        if ((xi - x) * (xi - x) + (yi - y) * (yi - y) > (long long)k * k) r++;
    }
    printf("%d", r);
    return 0;
}