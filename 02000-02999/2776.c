#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 10^6)개의 수가 주어지고 다시 M(M <= 10^6)개의 수가 주어질 때, 이후에 주어진 수들이
이전에 주어진 수들 가운데 있었는지 각각 구한다.

해결 방법 : 들어온 N개의 수들을 정렬한 다음 M개의 수들이 들어올 때 마다 이분 탐색을 통해 수들이 존재하는지 구한다.

주요 알고리즘 : 정렬, 이분 탐색
*/

int exist[1048576];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int t, n, m, x;
    char* r;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &exist[i]);
        }
        qsort(exist, n, sizeof(int), cmp1);
        scanf("%d", &m);
        for (int i = 0; i < n; i++) {
            scanf("%d", &x);
            r = bsearch(&x, exist, n, sizeof(int), cmp1);
            printf("%d\n", r == NULL ? 0 : 1);
        }
    }
    return 0;
}