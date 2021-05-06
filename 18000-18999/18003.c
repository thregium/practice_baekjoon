#include <stdio.h>

/*
문제 : R * C(R, C <= 50) 크기의 보드를 출력한다. 맨 왼쪽 위 칸은 검은색이며, 흰색과 검은색이 지그재그로 나타나야 한다.
각 가로, 세로줄의 넓이는 V, H개의 수로 각각 주어진다.

해결 방법 : 본문에서 주어진대로 구현한다.

주요 알고리즘 : 구현

출처 : PacNW 2019 N번
*/

int vs[64], hs[64];

int main(void) {
    int r, c, v, h;
    scanf("%d %d %d %d", &r, &c, &v, &h);
    for (int i = 0; i < v; i++) {
        scanf("%d", &vs[i]);
    }
    for (int i = 0; i < h; i++) {
        scanf("%d", &hs[i]);
    }
    for (int i = 0; i < v; i++) {
        for (int ii = 0; ii < vs[i]; ii++) {
            for (int j = 0; j < h; j++) {
                for (int jj = 0; jj < hs[j]; jj++) {
                    printf("%c", ((i + j) & 1) ? 'W' : 'B');
                }
            }
            printf("\n");
        }
    }
    return 0;
}