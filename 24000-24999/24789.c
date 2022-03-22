#include <stdio.h>

/*
문제 : X자 교차하는 선로가 X(X <= 1000)개, Y자로 나가는 선로가 Y(Y <= 1000)개 주어질 때,
이 선로들과 무한한 직선, 곡선 선로들로 회로를 만들 수 있는 지 구한다.

해결 방법 : X자 선로는 몇 개든 상관 없지만 Y자 선로는 짝수개가 있어야만 회로를 만들 수 있음을 알 수 있다.

주요 알고리즘 : 애드 혹?

출처 : VTH 2016 G번
*/

int main(void) {
    int x, y;
    scanf("%d %d", &x, &y);
    printf("%s", (y & 1) ? "impossible" : "possible");
    return 0;
}