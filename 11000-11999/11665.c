#include <stdio.h>
#define INF 1023

/*
문제 : 직육면체 N(N <= 1000)개가 모두 겹치는 부분의 부피를 구한다.

해결 방법 : 처음에는 전체 공간에서 시작해서 직육면체가 나올 때 마다 공간을 줄여나가면 된다.
각 좌표축마다 최솟값과 최댓값을 잡아놓고 시작점이 그 이상이거나 끝점이 그 이하인 경우 최소, 최대를 그 좌표로 갱신한다.
N개의 직육면체에 대해 모두 끝나면 최솟값이 최댓값보다 커지지 않았는지 검사하고 최솟값 > 최댓값인 경우 답은 0, 그 외에는 공간의 부피이다.

주요 알고리즘 : 기하학, 3차원 기하학
*/

int main(void) {
    int n, xl = -INF, xh = INF, yl = -INF, yh = INF, zl = -INF, zh = INF, x1, y1, z1, x2, y2, z2;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d %d %d %d", &x1, &y1, &z1, &x2, &y2, &z2);
        if (x1 > xl) xl = x1;
        if (y1 > yl) yl = y1;
        if (z1 > zl) zl = z1;
        if (x2 < xh) xh = x2;
        if (y2 < yh) yh = y2;
        if (z2 < zh) zh = z2;
    }
    if (xl > xh || yl > yh || zl > zh) printf("0");
    else printf("%d", (xh - xl) * (yh - yl) * (zh - zl));
    return 0;
}