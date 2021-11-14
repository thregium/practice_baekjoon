#include <stdio.h>
#include <string.h>

/*
문제 : 로봇의 움직임을 시뮬레이션한다. N(N <= 1000)개의 명령이 있고, 각 명령은 90도 회전과 앞쪽으로 x칸 이동의 두 가지가 있다.
만약 명령 도중 범위를 벗어나는 경우 -1을 출력하고 그렇지 않다면 마지막의 로봇 위치를 출력한다.

해결 방법 : 로봇의 방향과 이동을 명령에 맞게 바꾼다. 방향 배열을 사용하면 이동을 간단하게 처리 가능하다.
방향 처리시 좌표축의 확인을 잘 해야 한다.

주요 알고리즘 : 구현, 시뮬레이션

출처 : Daejeon 2016 I번
*/

char oper[8];
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

int main(void) {
    int m, n, x = 0, y = 0, d = 1, arg;
    scanf("%d %d", &m, &n);
    for (int i = 0; i < n; i++) {
        scanf("%s %d", oper, &arg);
        if (!strcmp(oper, "MOVE")) {
            x += dxy[d][0] * arg;
            y += dxy[d][1] * arg;
            if (x < 0 || y < 0 || x > m || y > m) {
                printf("-1");
                return 0;
            }
        }
        else if (!strcmp(oper, "TURN")) {
            if (arg) d = ((d + 1) & 3);
            else d = ((d + 3) & 3);
        }
    }
    printf("%d %d", x, y);
    return 0;
}