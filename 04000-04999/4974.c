#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 100)개의 값들 중 최솟값과 최댓값을 뺀 평균을 구한다. 소숫점 아래는 버림한다.

해결 방법 : 정렬한 다음 첫 값과 마지막 값을 뺀 값을 더한 후 N - 2로 나누면 된다.

주요 알고리즘 : 수학, 사칙연산, 구현, 정렬

출처 : JDC 2007 A번
*/

int a[128];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, s;
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        qsort(a, n, sizeof(int), cmp1);
        s = 0;
        for (int i = 1; i < n - 1; i++) s += a[i];
        printf("%d\n", s / (n - 2));
    }
    return 0;
}