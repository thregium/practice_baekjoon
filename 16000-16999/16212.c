#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 500000)개의 수를 정렬하여 출력한다.

해결 방법 : 정렬하고 출력한다.

주요 알고리즘 : 정렬

출처 : 대구과고 2018 0번
*/

int a[524288];

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
        printf("%d ", a[i]);
    }
    return 0;
}