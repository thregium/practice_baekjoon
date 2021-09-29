#include <stdio.h>
#include <stdlib.h>

/*
문제 : R(R <= 50) * W(W <= 101, W는 홀수) 크기의 좌석이 있다. 이때, 마지막 줄의 가운데 좌석을 가장 선호하고,
이후로는 그 좌석에서 거리가 가까운 순으로 선호한다면 선호하는 좌석의 순서를 모든 좌석에 대해 출력한다.
거리가 같은 경우 뒤쪽 줄일 수록 선호하고, 같은 줄에서는 왼쪽일 수록 선호한다.

해결 방법 : 각 좌석별로 거리를 피타고라스의 정리를 이용해 계산하고 기록해 놓는다.
이를 한 배열에 옮긴 다음, 좌석의 위치와 함께 기록한다. 그 다음, 이 배열을 거리 순 -> 줄 순 -> 왼쪽 순으로 정렬한다.
정렬한 배열에서 다시 좌석의 위치를 찾아와서 순위를 기록한 다음, 이 값들을 출력하면 된다.

주요 알고리즘 : 기하학, 정렬

출처 : USACO 2010J B2번
*/

int res[64][128], sorting[8192][2];

int sqr(int a) {
    return a * a;
}

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    if (ai != bi) return ai > bi ? 1 : -1;
    int ap = *((int*)a + 1);
    int bp = *((int*)b + 1);
    if ((ap >> 7) != (bp >> 7)) return (ap >> 7) < (bp >> 7) ? 1 : -1;
    else return ap > bp ? 1 : ap == bp ? 0 : -1;
}

int main(void) {
    int w, r;
    scanf("%d %d", &w, &r);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < w; j++) {
            sorting[i * w + j][0] = sqr(i - (r - 1)) + sqr(j - (w >> 1));
            sorting[i * w + j][1] = i * 128 + j;
        }
    }
    qsort(sorting, r * w, sizeof(int) * 2, cmp1);
    for (int i = 0; i < r * w; i++) {
        res[sorting[i][1] >> 7][sorting[i][1] & 127] = i + 1;
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < w; j++) {
            printf("%d ", res[i][j]);
        }
        printf("\n");
    }
    return 0;
}