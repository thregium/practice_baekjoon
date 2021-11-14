#include <stdio.h>
#include <stdlib.h>

/*
문제 : 수직선상에 N(N <= 30000)개의 좌표와 해당 위치에서의 최대 이동 거리가 주어질 때, 마지막 점까지 도달 가능한지 구한다.

해결 방법 : 각 점을 좌표 기준 오름차순으로 정렬한 후, 현재 점까지 확인했을 때 가능한 최대 이동 거리를 매번 구한다.
그 값이 다음 점에 미치지 못하는 지점이 있다면 도달 불가능하고, 끝까지 그러한 점이 없다면 도달 가능하다.

주요 알고리즘 : 그리디 알고리즘, 정렬

출처 : 선린 2회예 E번
*/

int a[32768][2];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, l = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i][0]);
    }
    for (int i = 0; i < n - 1; i++) {
        scanf("%d", &a[i][1]);
    }
    qsort(a, n, sizeof(int) * 2, cmp1);
    for (int i = 0; i < n; i++) {
        if (a[i][0] + a[i][1] > l) l = a[i][0] + a[i][1];
        if (a[i + 1][0] - a[i][0] > l) {
            printf("엄마 나 전역 늦어질 것 같아");
            return 0;
        }
    }
    printf("권병장님, 중대장님이 찾으십니다");
    return 0;
}