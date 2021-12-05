#include <stdio.h>

/*
문제 : R * C(R, C <= 10) 크기의 격자에 'N', 'E', 'S', 'W' 중 하나가 각 칸에 적혀있다. 위쪽으로 왼쪽에서 Y번째 칸에 들어왔을 때,
나가게 되는, 또는 같은 칸을 반복해서 이동하게 되는 이동 횟수를 구한다.
각 칸에 도착할 때 마다 칸에 적힌 방향으로 이동한다.

해결 방법 : 각 칸에 처음 들어온 시점을 표시하고, 각 칸에 들어올 때 마다 칸의 범위 안인지 먼저 확인한다.
칸 밖으로 나갔다면 밖으로 나간 것이다. 또, 이미 들어온 칸에 다시 들어왔다면 계속 반복하는 것이다.
그 외에는 계속 주어진 방향대로 이동하면 된다.

주요 알고리즘 : 구현, 시뮬레이션

출처 : MidC 1999 F번
*/

char grid[16][16];
int step[16][16];

int main(void) {
    int r, c, x, y, time;
    while (1) {
        scanf("%d %d %d", &r, &c, &y);
        if (r == 0) break;
        y--;
        x = 0;
        for (int i = 0; i < r; i++) {
            scanf("%s", grid[i]);
            for (int j = 0; j < c; j++) step[i][j] = -1;
        }
        time = 0;
        while (x >= 0 && x < r && y >= 0 && y < c) {
            if (step[x][y] >= 0) {
                printf("%d step(s) before a loop of %d step(s)\n", step[x][y], time - step[x][y]);
                time = -1;
                break;
            }
            step[x][y] = time;
            if (grid[x][y] == 'N') x--;
            else if (grid[x][y] == 'E') y++;
            else if (grid[x][y] == 'S') x++;
            else if (grid[x][y] == 'W') y--;
            else return 1;
            time++;
        }
        if (time >= 0) printf("%d step(s) to exit\n", time);
    }
    return 0;
}