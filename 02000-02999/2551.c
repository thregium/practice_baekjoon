#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 5 * 10^6)개의 자연수(<= 10000)가 있을 때, 편차의 합, 편차의 제곱의 합을 각각
가장 작게 만드는 수 중 가장 작은 수를 구한다.

해결 방법 : 첫 번째는 중앙값이고, 두 번째는 평균이다. 이를 각각 구하면 된다.

주요 알고리즘 : 수학, 정렬

출처 : 정올 2009 중1번
*/

int a[5242880];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n;
    long long sum = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        sum += a[i];
    }
    qsort(a, n, sizeof(int), cmp1);
    printf("%d %lld", a[(n - 1) >> 1], (sum + (n + 1) / 2 - 1) / n);
    return 0;
}