#include <stdio.h>

/*
문제 : 첫 16개의 색상 가운데 주어진 색상과 가장 가까운 것은 골라 매칭시킨 색을 구한다.

해결 방법 : 16개의 색상에 대해 전부 거리를 재보고 가장 가까운 것을 고르면 된다.

주요 알고리즘 : 브루트 포스, 수학

출처 : GNY 2001 A번
*/

int target[16][3], color[3];

int sqr(int a) {
    return a * a;
}

int getdist(int x) {
    return sqr(color[0] - target[x][0]) + sqr(color[1] - target[x][1]) + sqr(color[2] - target[x][2]);
}

int main(void) {
    int best;
    for (int i = 0; i < 16; i++) {
        scanf("%d %d %d", &target[i][0], &target[i][1], &target[i][2]);
    }
    while (1) {
        scanf("%d %d %d", &color[0], &color[1], &color[2]);
        if (color[0] < 0) break;
        best = 0;
        for (int i = 1; i < 16; i++) {
            if (getdist(i) < getdist(best)) best = i;
        }
        printf("(%d,%d,%d) maps to (%d,%d,%d)\n", color[0], color[1], color[2], target[best][0], target[best][1], target[best][2]);
    }
    return 0;
}