#include <stdio.h>

/*
문제 : W * L(W, L <= 20) 크기의 방이 있다. 방의 사방은 '#'으로 벽이 쳐져 있고, 이 중 '*'에서
레이저를 쏜다. 레이저는 거울(/, \)에서 반사되어 나간다. 이때, 레이저가 나가는 칸의 위치를 출력한다.

해결 방법 : '*'이 있는 칸에서 시뮬레이션을 통해 레이저를 이동시켜 나가면 된다.

주요 알고리즘 : 구현, 시뮬레이션

출처 : MidC 2014 B번
*/

char house[32][32];
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

int main(void) {
    int w, l, x = -1, y = -1, d = -1;
    for (int tt = 1;; tt++) {
        scanf("%d %d", &w, &l);
        if (w == 0) break;
        for (int i = 0; i < l; i++) {
            scanf("%s", house[i]);
        }
        for (int i = 0; i < l; i++) {
            for (int j = 0; j < w; j++) {
                if (house[i][j] == '*') {
                    x = i, y = j;
                    if (j == 0) d = 0;
                    else if (i == 0) d = 1;
                    else if (j == w - 1) d = 2;
                    else if (i == l - 1) d = 3;
                    else return 1;
                }
            }
        }
        while (house[x][y] != 'x') {
            x += dxy[d][0];
            y += dxy[d][1];
            if (house[x][y] == '/') d = 3 - d;
            else if (house[x][y] == '\\') d ^= 1;
        }
        house[x][y] = '&';
        printf("HOUSE %d\n", tt);
        for (int i = 0; i < l; i++) {
            printf("%s\n", house[i]);
        }
    }
    return 0;
}