#include <stdio.h>

/*
문제 : 원의 중심(|| <= 10^9, 정수)과 반지름(<= 10^9, 자연수)이 주어질 때,
이 원에 외접하는 가장 작은 정사각형 중 하나를 출력한다.

해결 방법 : 원의 중심에서 상하좌우로 반지름만큼 떨어진 수직, 수평선을 그으면 된다.

주요 알고리즘 : 기하학

출처 : BAPC 2021 A번
*/

int main(void) {
    int x, y, r;
    scanf("%d %d%d", &x, &y, &r);
    printf("%d %d\n%d %d\n%d %d\n%d %d", x - r, y - r, x - r, y + r, x + r, y + r, x + r, y - r);
    return 0;
}
