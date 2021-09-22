#include <stdio.h>
#include <stdlib.h>

/*
문제 : 5개의 점들이 일직선상에 있고, 인접한 점들끼리의 거리 4개가 주어질 때, 모든 점들 사이의 거리를 구한다.

해결 방법 : 먼저, 첫 번째 점과 나머지 점 사이의 거리를 누적 합을 이용해 구한다.
그러면 나머지 점들의 거리는 두 점과의 거리를 첫 번째 점과의 거리를 이용해 구할 수 있다.

주요 알고리즘 : 수학, 누적 합

출처 : CCC 2018 J3번
*/

int dists[4], res[5][5];

int main(void) {
    scanf("%d %d %d %d", &dists[0], &dists[1], &dists[2], &dists[3]);
    for (int i = 1; i < 5; i++) {
        res[0][i] = res[0][i - 1] + dists[i - 1];
    }
    for (int i = 1; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            res[i][j] = abs(res[0][i] - res[0][j]);
        }
    }
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", res[i][j]);
        }
        printf("\n");
    }
    return 0;
}