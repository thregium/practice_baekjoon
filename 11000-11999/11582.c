#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 2^20, N은 2^x)개의 수로 이루어진 수열을 K(K <= N, K는 2^y)개의 조각으로 나누어 각각 정렬한 결과를 구한다.

해결 방법 : 수열을 K개의 부분으로 나누고 각각 정렬하면 된다.

주요 알고리즘 : 정렬

출처 : 인하대 2015 H번
*/

int a[1048576];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, k;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        qsort(a + i * (n / k), (n / k), sizeof(int), cmp1);
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}