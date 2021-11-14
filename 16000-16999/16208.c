#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 500000)개의 자연수(<= 100)로 이루어진 수열이 주어진다. 모든 자연수의 합 길이 막대를 각 수열의
자연수 길이대로 자르는 방법 가운데 가장 비용이 작은 것을 구한다. 막대를 자를 때의 비용은
자르는 두 부분 길이의 곱이다.

해결 방법 : 최대한 막대를 불균등하게 자르는 것이 최적임을 알 수 있다. 이러한 경우는 가장 작은 것 부터 자르는 것으로,
오름차순으로 정렬하고, 그 순서대로 자르면 된다. 전체 합을 미리 구해둬야 한다.

주요 알고리즘 : 그리디 알고리즘, 정렬

출처 : 대곽 2018 1번
*/

int a[524288];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n;
    long long s = 0, r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        s += a[i];
    }
    qsort(a, n, sizeof(int), cmp1);
    for (int i = 0; i < n - 1; i++) {
        s -= a[i];
        r += a[i] * s;
    }
    printf("%lld", r);
    return 0;
}