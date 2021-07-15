#include <stdio.h>

/*
문제 : 색상들이 주어지면 처음 16개 색상들 가운데 가장 가까운 색상을 골라 해당 색상과 연결된 결과를 출력한다.
색상 사이의 거리는 RGB값 차이의 제곱의 합을 제곱근한 것과 같다.

해결 방법 : 16개 색상 각각에 대해 색상 거리를 구한 다음 가장 가까운 색상을 찾아 그 둘을 연결지으면 된다.

주요 알고리즘 : 브루트 포스, 사칙연산

출처 : MidC 1994 1번
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
    //freopen("E:\\PS\\ICPC\\North America\\Mid Central\\mcpc1994\\problem1.in", "r", stdin);
    for (int i = 0; i < 16; i++) {
        scanf("%d %d %d", &target[i][0], &target[i][1], &target[i][2]);
    }
    while (scanf("%d %d %d", &color[0], &color[1], &color[2]) != EOF) {
        best = 0;
        for (int i = 1; i < 16; i++) {
            if (getdist(i) < getdist(best)) best = i;
        }
        printf("%3d %3d %3d maps to %3d %3d %3d\n", color[0], color[1], color[2], target[best][0], target[best][1], target[best][2]);
    }
    return 0;
}