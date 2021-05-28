#include <stdio.h>
#include <stdlib.h>

/*
문제 : 길이 N(N <= 1000)의 수열 3개가 주어지면 N개의 원소들에 대해 수열 3개 중 2번째로 큰 i번째 원소를 각각 출력한다.

해결 방법 : 수들을 입력받은 다음 각각 정렬해서 2번째 값을 출력하면 된다.

주요 알고리즘 : 구현

출처 : UKIEPC 2020 M번
*/

int dist[1024][3];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &dist[j][i]);
        }
    }
    for (int i = 0; i < n; i++) {
        qsort(dist[i], 3, sizeof(int), cmp1);
        printf("%d ", dist[i][1]);
    }
    return 0;
}