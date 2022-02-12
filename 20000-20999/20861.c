#include <stdio.h>

/*
문제 : R * C(R, C <= 100) 크기의 화살표와 'A', 'B'로 이루어진 격자 중 맨 위 왼쪽 칸에서 출발하여
화살표를 따라가면 'A'에 도착하는 지, 'B'에 도착하는 지, 계속 도는 지 구한다.
격자의 밖으로 나가는 경우는 없다.

해결 방법 : (0, 0)에서 출발하여 화살표를 따라 계속 이동하면 된다.
다시 (0, 0)에 도착하는 경우 계속 돌 것이고, 그 외에는 10000번 내로 'A' 또는 'B'에 도착할 것이다.

주요 알고리즘 : 구현, 시뮬레이션

출처 : SwOI 2018OQ A번
*/

char s[128][128];

int main(void) {
    int r, c, x = 0, y = 0;
    scanf("%d%d", &r, &c);
    for (int i = 0; i < r; i++) {
        scanf("%s", s[i]);
    }
    for (int i = 0; i < 103000; i++) {
        if (s[x][y] == 'A') {
            printf("sushi");
            return 0;
        }
        else if (s[x][y] == 'B') {
            printf("samuraj");
            return 0;
        }
        if (s[x][y] == '^') x--;
        else if (s[x][y] == 'v') x++;
        else if (s[x][y] == '<') y--;
        else if (s[x][y] == '>') y++;
    }
    printf("cykel");
    return 0;
}