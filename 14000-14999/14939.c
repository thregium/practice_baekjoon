#include <stdio.h>

/*
문제 : 10 * 10 크기의 격자에 전구들이 켜지거나 꺼진 상태로 있다.
각 전구들을 누르면 해당 전구와 상하좌우의 전구들의 상태가 반전될 때,
모든 전구를 끌 수 있는 지 구하고, 가능한 경우 그렇게 하기 위한 최소 누르는 횟수를 구한다.

해결 방법 : 맨 윗 줄의 전구들의 상태가 고정된 경우 그 아래 줄들은 윗줄의 전구를 끄도록
전구를 눌러야 함을 알 수 있다. 맨 윗 줄의 가능한 상태는 2^10 = 1024가지이므로,
이 모든 경우에 대해 맨 밑줄까지 해당 방법으로 전구를 누르고, 모든 전구가 꺼진 상태의
누르는 횟수를 구하면 된다. 모든 전구가 꺼진 상태를 만드는 방법은 반드시 유일하다.

주요 알고리즘 : 브루트 포스, 애드 혹?

출처 : 서강대 2017M E번
*/

char light[16][16], tmp[16][16];
int dxy[5][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0}, {0, 0} };
int best = 103000, cnt, t;

int isvalid(int x, int y) {
    if (x < 0 || y < 0 || x >= 10 || y >= 10) return 0;
    return 1;
}

char revlight(char c) {
    if (c == 'O') return '#';
    else return 'O';
}

void pushlight(int x, int y) {
    for (int i = 0; i < 5; i++) {
        if (isvalid(x + dxy[i][0], y + dxy[i][1])) {
            tmp[x + dxy[i][0]][y + dxy[i][1]] = revlight(tmp[x + dxy[i][0]][y + dxy[i][1]]);
        }
    }
    cnt++;
}

int main(void) {
    for (int i = 0; i < 10; i++) {
        scanf("%s", light[i]);
    }
    for (int i = 0; i < 1024; i++) {
        for (int j = 0; j < 10; j++) {
            for (int k = 0; k < 10; k++) tmp[j][k] = light[j][k];
        }
        cnt = 0;
        for (int j = 0; j < 10; j++) {
            if ((i >> j) & 1) pushlight(0, j);
        }
        for (int j = 1; j < 10; j++) {
            for (int k = 0; k < 10; k++) {
                if (tmp[j - 1][k] == 'O') pushlight(j, k);
            }
        }

        t = 1;
        for (int j = 0; j < 10; j++) {
            if (tmp[9][j] == 'O') t = 0;
        }
        if (t) {
            if (cnt < best) best = cnt;
        }
    }
    printf("%d", best == 103000 ? -1 : best);
    return 0;
}