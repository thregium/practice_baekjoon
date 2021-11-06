#include <stdio.h>
#include <stdlib.h>

/*
문제 : -100 이상 100 이하의 정수 3개가 주어질 때, 나머지 한 개의 정수를 추가해 네 정수가 등차수열이 되도록 하는 정수를 구한다.
이러한 경우가 있는 경우만 주어진다.

해결 방법 : 3개의 수가 어떻게 주어지든 나머지 한 수는 -200 이하 200 이상의 수에서 찾을 수 있다.
따라서, 해당 구간에 대해 수를 추가한 다음 정렬하고 모든 인접한 수의 차이가 같은지 매번 확인해 보다가
그러한 경우를 찾으면 출력하고 프로그램을 종료하면 된다.

주요 알고리즘 : 브루트 포스, 정렬

출처 : COCI 07/08#3 1번
*/

int num[3], nnum[4];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    for (int i = 0; i < 3; i++) {
        scanf("%d", &num[i]);
    }
    for (int i = -1000; i <= 1000; i++) {
        for (int j = 0; j < 3; j++) {
            nnum[j] = num[j];
        }
        nnum[3] = i;
        qsort(nnum, 4, sizeof(int), cmp1);
        if (nnum[1] - nnum[0] == nnum[2] - nnum[1] && nnum[2] - nnum[1] == nnum[3] - nnum[2]) {
            printf("%d", i);
            return 0;
        }
    }
    return 1;
}