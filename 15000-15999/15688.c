#include <stdio.h>
#include <stdlib.h>

/*
문제 : 정수 N(N <= 10^6)개를 정렬한다. 각 수는 절댓값이 10^6 이하다.

해결 방법 : qsort() 함수를 이용한다.

주요 알고리즘 : 정렬
*/

int a[1048576];

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
        printf("%d\n", a[i]);
    }
    return 0;
}