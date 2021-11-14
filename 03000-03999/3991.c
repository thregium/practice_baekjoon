#include <stdio.h>

/*
문제 : H * W(H, W <= 10) 크기의 격자판에 C(C <= 9)가지 색상의 구슬을 배치한다. 각 구슬의 개수가 주어지고,
각 구슬은 H * W개이다. 이때, 점수가 가장 높아지도록 구슬을 배치하는 방법 중 하나를 구한다.

해결 방법 : 모든 같은 색의 구슬들이 서로 인접하도록 배치하면 점수가 가장 높아진다.
지그재그로 배치하는 것이 그 중에는 가장 쉬운 방법으로 보인다.

주요 알고리즘 : 그리디 알고리즘, 구성적

출처 : NEERC 2012 A번
*/

char res[16][16];

int main(void) {
    int h, w, c, cc, x = 0, y = 0, d = 0;
    scanf("%d %d %d", &h, &w, &c);
    for (int i = 0; i < c; i++) {
        scanf("%d", &cc);
        for (int j = 0; j < cc; j++) {
            res[x][y] = i + '1';
            if (d == 0) {
                y++;
                if (y >= w) {
                    x++;
                    d = 1;
                    y--;
                }
            }
            else {
                y--;
                if (y < 0) {
                    x++;
                    d = 0;
                    y++;
                }
            }
        }
    }
    for (int i = 0; i < h; i++) {
        printf("%s\n", res[i]);
    }
    return 0;
}