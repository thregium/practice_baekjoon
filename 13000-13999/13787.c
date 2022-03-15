#include <stdio.h>
#include <ctype.h>

/*
문제 : H * W(H, W <= 100) 크기의 격자에 '.', '#', (E, S, W, N 중 하나의 알파벳)이 주어진다.
알파벳이 쓰인 칸에서 알파벳의 방향으로 출발해 그 방향으로 '#' 또는 격자의 밖으로 막힐 때 까지 이동하며,
막히게 되면 시계방향으로 막히지 않는 방향까지 돌아간 다음 그 방향으로 방향을 바꾸어 이동한다.
이때, L(L <= 10^18)번 이동한 후 어느 칸의 어느 위치에 있게 되는 지 구한다.

해결 방법 : 가능한 상태는 각 칸의 각 방향으로 최대 100 * 100 * 4가지이다. 이 모든 경우가 확인된 후에는
반드시 이전에 방문한 상태를 다시 방문하게 되고, 각 상태에서 다른 상태로 이동하는 것도
항상 일정하기 때문에 반복이 일어나게 된다.
따라서, 반복 마디를 찾은 다음, 첫 반복 이후의 다른 반복들을 전부 무시하고(반복 마디로 나눈 나머지 취하기)
이동을 시뮬레이션하면 답을 빠르게 찾을 수 있다.

주요 알고리즘 : 구현, 시뮬레이션, 수학

출처 : JAG 2011P A번
*/

char maze[128][128];
int dist[128][128][4];
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
char dirc[4] = "ESWN";

int isvalid(int h, int w, int x, int y) {
    if (x < 0 || y < 0 || x >= h || y >= w) return 0;
    if (maze[x][y] == '#') return 0;
    return 1;
}

int main(void) {
    int h, w, sx, sy, sd, x, y, d, xn, yn, tm, lp;
    long long l;
    while (1) {
        scanf("%d %d %lld", &h, &w, &l);
        if (h == 0) break;
        sx = -1, sy = -1, sd = -1;
        for (int i = 0; i < h; i++) {
            scanf("%s", maze[i]);
            for (int j = 0; j < w; j++) {
                if (isupper(maze[i][j])) {
                    sx = i, sy = j;
                    if (maze[i][j] == 'E') sd = 0;
                    else if (maze[i][j] == 'S') sd = 1;
                    else if (maze[i][j] == 'W') sd = 2;
                    else if (maze[i][j] == 'N') sd = 3;
                }
            }
        }
        if (sx < 0) return 1;

        x = sx, y = sy, d = sd, tm = 1;
        while (1) {
            while (1) {
                xn = x + dxy[d][0];
                yn = y + dxy[d][1];
                if (isvalid(h, w, xn, yn)) break;
                else d = ((d + 1) & 3);
            }
            x = xn, y = yn;
            if (dist[x][y][d]) {
                lp = tm - dist[x][y][d];
                tm = dist[x][y][d];
                break;
            }
            else dist[x][y][d] = tm++;
        }

        if (l > tm) l = (l - tm) % lp + tm;
        x = sx, y = sy, d = sd, tm = 1;
        while (1) {
            while (1) {
                xn = x + dxy[d][0];
                yn = y + dxy[d][1];
                if (isvalid(h, w, xn, yn)) break;
                else d = ((d + 1) & 3);
            }
            x = xn, y = yn;
            if (tm == l) {
                printf("%d %d %c\n", x + 1, y + 1, dirc[d]);
                break;
            }
            else dist[x][y][d] = tm++;
        }
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                maze[i][j] = '\0';
                for (int k = 0; k < 4; k++) dist[i][j][k] = 0;
            }
        }
    }
    return 0;
}