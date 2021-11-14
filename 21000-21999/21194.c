#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 100000)개의 음이 아닌 정수(<= 10000)로 이루어진 배열이 주어질 때, 이 배열의 수들 중
K(K <= N)개의 수를 뽑아서 더했을 때 나올 수 있는 가장 큰 수를 구한다.

해결 방법 : 가장 큰 수부터 더해나가면 된다. 내림차순으로 정렬하고 앞의 K개의 합을 구한다.

주요 알고리즘 : 그리디 알고리즘, 정렬

출처 : SWERC 2020-2021 PB번
*/

int g[103000];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai < bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, k, r = 0;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &g[i]);
    }
    qsort(g, n, sizeof(int), cmp1);
    for (int i = 0; i < k; i++) {
        r += g[i];
    }
    printf("%d", r);
    return 0;
}