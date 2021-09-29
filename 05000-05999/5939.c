#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 5000)개의 시각이 시, 분, 초 단위로 주어질 때, 시각을 오름차순으로 정렬해 주어진대로 출력한다.

해결 방법 : 각 시각을 초 단위로 바꾸고 정렬한 뒤, 시, 분, 초 단위로 다시 변환하여 순서대로 출력하면 된다.

주요 알고리즘 : 구현, 정렬

출처 : USACO 2010N B2번
*/

int times[5120];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, h, m, s;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &h, &m, &s);
        times[i] = h * 3600 + m * 60 + s;
    }
    qsort(times, n, sizeof(int), cmp1);
    for (int i = 0; i < n; i++) {
        printf("%d %d %d\n", times[i] / 3600, times[i] / 60 % 60, times[i] % 60);
    }
    return 0;
}