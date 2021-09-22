#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 50000)명의 후보에 대해 투표를 한다. 1차 투표에서 상위 K(K <= N)명을 두고 2차 투표를 한 다음,
2차 투표의 득표수가 가장 많은 사람이 당선된다. 당선되는 사람이 누구인지 구한다.
단, 모든 사람의 득표수는 다르다.

해결 방법 : 먼저, 1차 투표의 득표수 순으로 N명을 정렬한다. 그 다음, 앞의 K명에 대해서만 2차 투표의 득표수 순으로
정렬하면 당선되는 사람을 쉽게 알 수 있다.

주요 알고리즘 : 구현, 정렬

출처 : USACO 2008J B2번
*/

int votes[51200][3];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai < bi ? 1 : ai == bi ? 0 : -1;
}

int cmp2(const void* a, const void* b) {
    int ai = *((int*)a + 1);
    int bi = *((int*)b + 1);
    return ai < bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &votes[i][0], &votes[i][1]);
        votes[i][2] = i + 1;
    }
    qsort(votes, n, sizeof(int) * 3, cmp1);
    qsort(votes, k, sizeof(int) * 3, cmp2);
    printf("%d", votes[0][2]);
    return 0;
}