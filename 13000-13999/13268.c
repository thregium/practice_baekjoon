#include <stdio.h>

/*
문제 : N(N <= 10000)만큼의 거리를 이동한 후 도달하는 위치를 구한다. 1번째 -> 2번째 -> 3번째 -> 4번째 콘으로
왕복하는 것을 반복한다. 각 콘은 5미터마다 있다.

해결 방법 : 각 거리마다 이동하는 방향을 확인하고 마지막에 도달한 곳을 찾으면 된다.

주요 알고리즘 : 구현, 시뮬레이션

출처 : KAIST 2016F D번
*/

int main(void) {
    int n, d = 1, x = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        if (d > 0) {
            x++;
            if (x == d * 5) d *= -1;
        }
        else {
            x--;
            if (x == 0 && d > -4) d = -d + 1;
            else if (x == 0 && d == -4) d = 1;
        }
    }
    printf("%d", (x + 4) / 5);
    return 0;
}