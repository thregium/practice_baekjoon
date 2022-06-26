#include <stdio.h>
#include <string.h>

/*
문제 : H * W(H, W <= 20) 크기의 직사각형에서 X표 쳐지지 않은 칸을 고르고 그 칸에서
상하좌우로 지워지지 않은 연속된 칸들을 지운다.
2명이 이를 반복하여 더이상 칸을 선택할 수 없는 사람이 진다고 할 때, 누가 이기게 되는 지 구한다.

해결 방법 : 전체 영역에서 범위를 좁혀가며 하위 직사각형 영역들로 내려가면서 다이나믹 프로그래밍을 한다.
스프라그-그런디 정리를 이용하여 각 영역에 대해 그런디 수를 저장하면서 최종적으로
전체 영역의 그런디 수를 살피면 답을 구할 수 있다.

주요 알고리즘 : DP, 게임 이론, 스프라그-그런디

출처 : JAG 2015SC L번
*/

char board[24][24];
int mem[24][24][24][24];
int tmx;

int dp(int xl, int yl, int xh, int yh) {
    if (xl > xh || yl > yh) return 0;
    if (mem[xl][yl][xh][yh] >= 0) return mem[xl][yl][xh][yh];
    int res = -1, mx = -1, g;
    int grnd[1024] = { 0, };
    for (int i = xl; i <= xh; i++) {
        for (int j = yl; j <= yh; j++) {
            if (board[i][j] == 'X') continue;
            g = dp(xl, yl, i - 1, j - 1) ^ dp(xl, j + 1, i - 1, yh) ^
                dp(i + 1, yl, xh, j - 1) ^ dp(i + 1, j + 1, xh, yh);
            grnd[g] = 1;
            if (g > mx) mx = g;
        }
    }

    if (mx > tmx) tmx = mx;
    for (int i = 0; i <= mx + 1; i++) {
        if (grnd[i] == 0) {
            res = i;
            break;
        }
    }
    return mem[xl][yl][xh][yh] = res;
}

int main(void) {
    int h, w, res;
    scanf("%d %d", &h, &w);
    for (int i = 0; i < h; i++) {
        scanf("%s", board[i]);
    }
    memset(mem, -1, sizeof(mem));
    res = dp(0, 0, h - 1, w - 1);
    printf("%s\n", res ? "First" : "Second");
    //printf("%d", tmx);
    return 0;
}