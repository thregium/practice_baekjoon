#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 100000)개의 자연수(<= 10^9)가 주어질 때, 주어진 자연수의 가짓수를 구한다.

해결 방법 : 자연수들을 정렬한 다음, 다음 수와 차이가 있는 수(와 마지막 수)의 개수를 구하면 된다.

주요 알고리즘 : 정렬

출처 : TOPC 2019 B번
*/

int a[103000];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    qsort(a, n, sizeof(int), cmp1);
    for (int i = 0; i < n; i++) {
        if (a[i] != a[i + 1]) r++;
    }
    printf("%d", r);
    return 0;
}