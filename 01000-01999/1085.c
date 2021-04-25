#include <stdio.h>

/*
문제 : (0, 0)과 (w, h)를 꼭짓점으로 하는 직사각형이 있을 때, (x, y)에서 직사각형의 테두리까지의 거리 가운데 가장 작은 값을 구한다.

해결 방법 : 수평 또는 수직 방향으로 이동하는 것이 가장 유리하므로 (x, y)에서 네 변까지의 거리를 구하고 그 가운데 가장 짧은 값을 출력한다.

주요 알고리즘 : 기하학
*/

int min(int a, int b) {
    return (a < b ? a : b);
}

int main(void) {
    int x, y, w, h;
    scanf("%d %d %d %d", &x, &y, &w, &h);
    printf("%d", min(min(w - x, x), min(h - y, y)));
    return 0;
}