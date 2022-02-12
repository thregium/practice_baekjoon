#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 10^6)개의 자연수(<= 100000) 가운데 K(K <= N)번째로 작은 수를 구한다. 중복을 포함한다.

해결 방법 : 수열을 정렬한 다음, K - 1번 원소를 출력하면 된다.

주요 알고리즘 : 정렬

출처 : AMPPZ 2007 I번
*/

int a[1048576];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int t, n, k;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d %d", &n, &k);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        qsort(a, n, sizeof(int), cmp1);
        printf("%d\n", a[k - 1]);
    }
    return 0;
}