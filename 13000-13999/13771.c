#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 100)개의 실수 가운데 2번째로 작은 것을 구한다. 같은 값은 존재하지 않는다.

해결 방법 : 수들을 정렬한 다음 2번째 수를 뽑으면 된다.

주요 알고리즘 : 구현, 정렬

출처 : NZPC 2016 A번
*/

double a[128];

int cmp1(const void* a, const void* b) {
    double ai = *(double*)a;
    double bi = *(double*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lf", &a[i]);
    }
    qsort(a, n, sizeof(double), cmp1);
    printf("%.2f", a[1]);
    return 0;
}