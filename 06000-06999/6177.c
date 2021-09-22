#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 500)개의 정수 X_i(|X_i| <= 5000)에 대한 평균과 중앙값을 구한다. N이 짝수인 경우 중앙값은 가운데 두 값의 평균이다.

해결 방법 : N개의 수 합을 구한 다음 N으로 나눈 값이 평균이 되고, 중앙값은 N개의 수를 정렬한 다음
가운데 수(N이 홀수인 경우, N / 2) 또는 가운데 두 수(짝수인 경우, N / 2 - 1, N / 2)의 평균을 구하면 된다.

주요 알고리즘 : 구현, 정렬, 수학

출처 : USACO 2008M B1번
*/

int a[512];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, s = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        s += a[i];
    }
    qsort(a, n, sizeof(int), cmp1);
    printf("%.9f\n", (double)s / n);
    if (n & 1) printf("%d", a[n >> 1]);
    else printf("%.9f", (a[n >> 1] + a[(n >> 1) - 1]) / 2.0);
    return 0;
}