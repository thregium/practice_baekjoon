#include <stdio.h>
#include <stdlib.h>

/*
문제 : 4줄로 이루어진 격자칸에 세로로 번호를 붙였다. 주어진 두 번호를 붙인 칸끼리의 맨해튼 거리를 구한다.

해결 방법 : 주어진 번호가 N이라고 하면 이 칸의 좌표는 (N + 3) / 4열 (N + 3) % 4 + 1행이다.
이를 이용해 두 번호를 붙인 칸에 대해 좌표를 확인한 다음, 두 좌표의 X, Y값 차이를 더해 맨해튼 거리를 구하면 된다.

주요 알고리즘 : 수학, 사칙연산
*/

int main(void) {
    int a, b, ax, ay, bx, by;
    scanf("%d %d", &a, &b);
    ax = (a + 3) / 4;
    bx = (b + 3) / 4;
    ay = (a + 3) % 4 + 1;
    by = (b + 3) % 4 + 1;
    printf("%d", abs(ax - bx) + abs(ay - by));
    return 0;
}