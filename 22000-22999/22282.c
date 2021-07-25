#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 100000)개의 수들 중 H개 이상인 수가 H개 이상인 가장 큰 H를 구한다.

해결 방법 : 수들을 정렬한 다음, 0과 N에서 시작해 매개 변수 탐색을 진행한다. i - 1번째 배열의 값이 i 이상인지를 확인해보면 된다.

주요 알고리즘 : 정렬, 이분 탐색

출처 : Rocky 2018 D번
*/

int c[103000];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai < bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, lo, hi;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &c[i]);
    }
    qsort(c, n, sizeof(int), cmp1);
    lo = 0, hi = n;
    while (lo < hi) {
        if (c[((lo + hi + 1) >> 1) - 1] >= ((lo + hi + 1) >> 1)) lo = (lo + hi + 1) >> 1;
        else hi = ((lo + hi + 1) >> 1) - 1;
    }
    printf("%d", hi);
    return 0;
}