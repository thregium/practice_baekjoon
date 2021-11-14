#include <stdio.h>
#include <stdlib.h>

/*
문제 : 4개의 점이 주어질 때, 4개의 점으로 정사각형을 만들 수 있는지 구한다. 각 점의 좌표는 절댓값이 100000 이하인 정수이다.

해결 방법 : 모든 점의 쌍에 대해 거리를 구하고, 내림차순으로 정렬한다.
만약 이 사각형이 정사각형이라면 두 대각선의 길이가 같고 모든 변의 길이가 같을 것이다.
따라서 가장 긴 거리 2개와, 나머지 거리 4개를 비교해 두 그룹의 원소들 간에 거리가 서로 같다면 정사각형이다.

주요 알고리즘 : 기하학, 피타고라스, 정렬
*/

long long point[4][2], dist[8];

long long sqr(long long x) {
    return x * x;
}

int cmp1(const void* a, const void* b) {
    long long ai = *(long long*)a;
    long long bi = *(long long*)b;
    return ai < bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int t, n, p;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        for (int i = 0; i < 4; i++) {
            scanf("%lld %lld", &point[i][0], &point[i][1]);
        }
        p = 0;
        for (int i = 0; i < 4; i++) {
            for (int j = i + 1; j < 4; j++) {
                dist[p++] = sqr(point[i][0] - point[j][0]) + sqr(point[i][1] - point[j][1]);
            }
        }
        qsort(dist, p, sizeof(long long), cmp1);
        if (dist[0] == dist[1] && dist[2] == dist[5]) printf("1\n");
        else printf("0\n");
    }
    return 0;
}