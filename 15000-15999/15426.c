#include <stdio.h>

/*
문제 : N(N <= 50)개의 동작(좌회전, 직진, 우회전)이 순서대로 주어질 때, (0, 0)에서 y좌표가 증가하는 방향으로
처음 상태가 있을 때, (X, Y)(|X|, |Y| <= 50)로 가도록 동작 하나를 바꾸는 방법을 출력한다.
그러한 방법은 유일하다.

해결 방법 : 모든 동작에 대해 바꿀 수 있는 모든 경우를 전부 시도해본다. N의 범위가 작으므로 충분히 가능하다.

주요 알고리즘 : 구현, 시뮬레이션, 브루트 포스

출처 : NAQ 2017 F번
*/

char buff[16];
int mv[64], mvt[64];
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

int main(void) {
    int n, x, y, d, xf, yf;
    scanf("%d %d", &xf, &yf);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", buff);
        if (buff[0] == 'F') mv[i] = 0;
        else if (buff[0] == 'R') mv[i] = 1;
        else mv[i] = -1;
    }
    for (int i = 0; i < n; i++) {
        for (int j = -1; j <= 1; j++) {
            x = 0, y = 0, d = 0;
            for (int k = 0; k < n; k++) {
                mvt[k] = mv[k];
                if (k == i) mvt[k] = j;
                if (mvt[k] == 0) {
                    x += dxy[d][0];
                    y += dxy[d][1];
                }
                else if (mvt[k] == 1) d = ((d + 1) & 3);
                else d = ((d + 3) & 3);
            }
            if (x == xf && y == yf) {
                printf("%d %s", i + 1, j < 0 ? "Left" : j == 0 ? "Forward" : "Right");
                return 0;
            }
        }
    }
    return 1;
}