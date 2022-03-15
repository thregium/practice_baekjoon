#include <stdio.h>

/*
문제 : 두 직교 직사각형이 주어질 때, 첫 번째 직사각형의 두 번째 직사각형에 대한 여집합의 넓이를 구한다.
두 직사각형의 좌표 범위는 10000 이하의 자연수로 주어진다.

해결 방법 : 두 직사각형의 교집합의 넓이를 최소 범위로 구한 후 첫 번째 직사각형의 넓이에서 뺀다.
단, 교집합의 넓이가 음수가 되지 않도록 주의한다.

주요 알고리즘 : 기하학

출처 : Taejeon 2002 A번
*/

int small(int a, int b) {
    return a < b ? a : b;
}

int big(int a, int b) {
    return a > b ? a : b;
}

int main(void) {
    int t, x1, y1, x2, y2, x3, y3, x4, y4, xl, yl, xh, yh;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d %d %d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);
        xl = big(x1, x3);
        yl = big(y1, y3);
        xh = small(x2, x4);
        yh = small(y2, y4);
        if (xh < xl || yh < yl) printf("%d\n", (x2 - x1) * (y2 - y1));
        else printf("%d\n", (x2 - x1) * (y2 - y1) - (xh - xl) * (yh - yl));
    }
    return 0;
}