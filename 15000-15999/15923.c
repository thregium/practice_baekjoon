#include <stdio.h>
#include <math.h>

/*
문제 : N(N <= 20)개의 꼭짓점으로 이루어진 직각으로 볼록한 도형의 둘레를 구한다.

해결 방법 : 1번째 지점을 제외하고는 마지막 지점과의 거리 차를 전부 더한다. 마지막 지점을 확인한 후에는 마지막 지점과
1번째 지점과의 거리도 더한다.

주요 알고리즘 : 기하학, 수학

출처 : 선린 2회 H번
*/

int main(void) {
    int n, x, y, sx = 0, sy = 0, lx = 0, ly = 0, r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &x, &y);
        if (i) {
            r += abs(x - lx) + abs(y - ly);
        }
        else {
            sx = x;
            sy = y;
        }
        lx = x;
        ly = y;
    }
    r += abs(sx - lx) + abs(sy - ly);
    printf("%d", r);
    return 0;
}