#include <stdio.h>

/*
문제 : N(N <= 2200)이 주어질 때, N을 절반의 두 구간(N이 홀수인 경우 왼쪽이 더 크게)으로 나누는 것을 반복하다
구간의 크기가 2가 되는 구간이 나오면 그 구간의 곱을 구하고, 전체 결과에 더한다. 1인 경우는 무시한다.
이때, 전체 결과를 구한다.

해결 방법 : 각 구간을 재귀를 통해 두 구간으로 나누어 가며 결과를 찾아나간다. 각 구간의 결과는 하위 구간의 합과 같으므로
하위 두 구간의 합을 반환하면 된다.

주요 알고리즘 : 구현, 재귀

출처 : USACO 2009D B1번
*/

int dance(int s, int e) {
    if (e == s + 1) return s * e;
    else if (e == s) return 0;
    return dance(s, (s + e) >> 1) + dance(((s + e) >> 1) + 1, e);
}

int main(void) {
    int n;
    scanf("%d", &n);
    printf("%d", dance(1, n));
    return 0;
}