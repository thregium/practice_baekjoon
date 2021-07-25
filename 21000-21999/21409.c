#include <stdio.h>
#include <math.h>

/*
문제 : 체스에서 폰을 제외한 흑과 백의 기물이 있을 때, 상대를 잡을 수 있는 기물은 무엇인지 구한다.

해결 방법 : 상대가 있는 위치로 이동 가능한 기물이라면 상대를 잡을 수 있다. 퀸, 룩, 비숍은 상대와 같은 줄에 있는지 확인하면 되고,
킹이나 나이트는 가로와 세로의 거리를 확인해 구할 수 있다.

주요 알고리즘 : 구현, 케이스 워크

출처 : ROI 2007H A번
*/

char white[8], black[8];

int big(int a, int b) {
    return a > b ? a : b;
}

int small(int a, int b) {
    return a < b ? a : b;
}

int main(void) {
    int wx, wy, bx, by, ww = 0, bw = 0;
    scanf("%s%s", white, black);
    wx = white[1] - 'a';
    wy = white[2] - '1';
    bx = black[1] - 'a';
    by = black[2] - '1';
    if (big(abs(wx - bx), abs(wy - by)) <= 1) {
        if (white[0] == 'K') ww = 1;
        if (black[0] == 'K') bw = 1;
    }
    if (wx == bx || wy == by || wx + wy == bx + by || wx - wy == bx - by) {
        if (white[0] == 'Q') ww = 1;
        if (black[0] == 'Q') bw = 1;
    }
    if (wx == bx || wy == by) {
        if (white[0] == 'R') ww = 1;
        if (black[0] == 'R') bw = 1;
    }
    if (wx + wy == bx + by || wx - wy == bx - by) {
        if (white[0] == 'B') ww = 1;
        if (black[0] == 'B') bw = 1;
    }
    if (big(abs(wx - bx), abs(wy - by)) == 2 && small(abs(wx - bx), abs(wy - by)) == 1) {
        if (white[0] == 'N') ww = 1;
        if (black[0] == 'N') bw = 1;
    }
    if (ww && bw) printf("BOTH");
    else if (ww) printf("WHITE");
    else if (bw) printf("BLACK");
    else printf("NONE");
    return 0;
}