#include <stdio.h>

/*
문제 : 터틀에 대해 길이 500 이하의 이동 명령(전진, 후진, 좌회전, 우회전)이 주어질 때,
터틀이 움직인 궤적을 둘러싸고 축에 평행한 가장 작은 직사각형의 넓이를 구한다.
궤적이 선분 또는 점인 경우 답은 0이다.

해결 방법 : 터틀을 (0, 0)에 놓고 움직임을 시뮬레이션하면서 X와 Y좌표에 대해 최솟값과 최댓값을 구하고
양 축의 최댓값 - 최솟값을 각각 곱하면 된다.

주요 알고리즘 : 구현, 시뮬레이션

출처 : Daejeon 2011 L번
*/

char s[512];
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

int main(void) {
    int t, x, y, d, xl, yl, xh, yh;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%s", s);
        x = 0, y = 0, d = 0, xl = 0, yl = 0, xh = 0, yh = 0;
        for (int i = 0; s[i]; i++) {
            if (s[i] == 'F') {
                x += dxy[d][0];
                y += dxy[d][1];
            }
            else if (s[i] == 'B') {
                x -= dxy[d][0];
                y -= dxy[d][1];
            }
            else if (s[i] == 'L') d = ((d + 1) & 3);
            else if (s[i] == 'R') d = ((d + 3) & 3);
            else return 1;

            if (x < xl) xl = x;
            if (x > xh) xh = x;
            if (y < yl) yl = y;
            if (y > yh) yh = y;
        }
        printf("%d\n", (xh - xl) * (yh - yl));
    }
    return 0;
}