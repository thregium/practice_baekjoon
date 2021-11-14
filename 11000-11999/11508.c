#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 100000)개의 물건이 있다. 물건 3개를 묶음으로 사면 가장 싼 물건의 가격은 받지 않는다면
모든 물건을 사기 위해 필요한 금액의 최솟값을 구한다.

해결 방법 : 가능한 비싼 물건을 할인받는 것이 좋으므로 가격 기준 내림차순 정렬 후,
3의 배수 번째를 제외한 나머지의 물건 가격의 합만 구하면 된다.

주요 알고리즘 : 그리디 알고리즘, 정렬

출처 : COCI 15/16#1 2번
*/

int c[103000];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai < bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &c[i]);
    }
    qsort(c, n, sizeof(int), cmp1);
    for (int i = 0; i < n; i++) {
        if (i % 3 != 2) r += c[i];
    }
    printf("%d", r);
    return 0;
}