#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 300000)개의 자연수로 이루어진 배열이 주어질 때, 이 배열을 비내림차순으로 정렬한 후,
Q(Q <= 300000)개의 쿼리에 응답한다.
L번째부터 R번째까지의 수의 합을 구한다.

해결 방법 : 배열을 정렬한 다음, 누적 합을 이용해 쿼리에 응답한다.

주요 알고리즘 : 누적 합, 정렬

출처 : 숭고한 2019 C번
*/

int a[327680];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, q, s, e;
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    qsort(a + 1, n, sizeof(int), cmp1);
    for (int i = 1; i <= n; i++) {
        a[i] += a[i - 1];
    }
    for (int i = 0; i < q; i++) {
        scanf("%d %d", &s, &e);
        printf("%d\n", a[e] - a[s - 1]);
    }
    return 0;
}