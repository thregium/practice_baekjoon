#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 100)번동안 이동을 하며 지나야 하는 직사각형 외부 칸의 최소 개수를 구한다.
직사각형의 범위는 1 이상 100 이하의 자연수이다. 지나야 하는 외부 칸은 들어갈 때를 기준으로 한다.
이동은 상하좌우로만 가능하다.

해결 방법 : 각 이동마다 이동시 지나야 하는 외부 칸의 최소 개수를 매번 구해서 더하면 된다.
각 이동마다 최소 개수는 직접 이동과 직사각형 내부를 경유하는 이동 두 가지 중 더 적은 외부 칸을
지나는 것을 선택하면 된다. 직접 이동은 맨해튼 거리를 쓰면 되고, 경유 이동은 두 지점에서
직사각형 내부로의 거리를 구한 다음, 시작점이 직사각형 외부인 경우
거기서 1을 빼면(들어갈 때가 기준이므로) 된다.

주요 알고리즘 : 수학, 기하학

출처 : JAG 2019D B번
*/

int getdist(int x1, int y1, int x2, int y2, int a, int b, int c, int d) {
    int r1 = abs(x2 - x1) + abs(y2 - y1), r2 = 0;
    if (x1 < a) r2 += a - x1;
    if (x1 > c) r2 += x1 - c;
    if (y1 < b) r2 += b - y1;
    if (y1 > d) r2 += y1 - d;
    if (x2 < a) r2 += a - x2;
    if (x2 > c) r2 += x2 - c;
    if (y2 < b) r2 += b - y2;
    if (y2 > d) r2 += y2 - d;

    if (!(a <= x1 && x1 <= c && b <= y1 && y1 <= d)) r2--;
    if (r1 < r2) return r1;
    else return r2;
}

int main(void) {
    int n, a, b, c, d, x, y, xx, yy, r;
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        scanf("%d %d %d %d", &a, &b, &c, &d);
        scanf("%d %d", &x, &y);
        r = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d %d", &xx, &yy);
            r += getdist(x, y, xx, yy, a, b, c, d);
            x = xx, y = yy;
        }
        printf("%d\n", r);
    }
    return 0;
}