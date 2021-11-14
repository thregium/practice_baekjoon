#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 100)개의 자연수(<= 10^6)가 주어질 때, 문제에 주어진 순서대로 출력한다.

해결 방법 : 배열을 정렬한 다음, 홀수와 짝수번째를 나누어 구하면 된다.

주요 알고리즘 : 구현, 정렬

출처 : CCC 2017 S2번
*/

int a[128];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    qsort(a, n, sizeof(int), cmp1);
    for (int i = 0; i < n; i++) {
        if (i & 1) printf("%d ", a[(n + i) >> 1]);
        else printf("%d ", a[(n - i - 1) >> 1]);
    }
    return 0;
}