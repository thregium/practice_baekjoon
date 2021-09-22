#include <stdio.h>
#include <stdlib.h>

/*
문제 : N * N(N < 100, N은 홀수) 크기의 배열에 1000 이하의 자연수가 채워져 있다.
이때, 각 행의 중앙값을 모은 배열의 중앙값을 구한다.

해결 방법 : 각 행을 입력받으며 정렬한다. 이 값의 중앙값(N / 2번째 원소)을 새로운 배열에 넣은 후,
새로운 배열을 다시 정렬해서 중앙값을 출력하면 된다.

주요 알고리즘 : 구현, 정렬

출처 : USACO 2008M B3번
*/

int beauty[128], beauty2[128];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &beauty[j]);
        }
        qsort(beauty, n, sizeof(int), cmp1);
        beauty2[i] = beauty[n >> 1];
    }
    qsort(beauty2, n, sizeof(int), cmp1);
    printf("%d", beauty2[n >> 1]);
    return 0;
}