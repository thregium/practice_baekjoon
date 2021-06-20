#include <stdio.h>

/*
문제 : M * N(M, N <= 50) 크기의 성에서 각 방의 벽 상태가 주어질 때, 방의 개수와 가장 큰 방의 크기, 벽을 하나 허물었을 때의 가장 큰 방의 크기를 구한다.
단, 방은 최소 2개 이상 있다.

해결 방법 : 모든 방들을 차례로 확인하며 아직 탐색하지 않은 방이 있는 경우 해당 방에서 플러드필을 진행한다.
플러드필을 진행하며 같은 방인 경우 해당 방의 번호를 기록하고, 해당 방의 크기를 1 늘린다. 이를 반복해 모든 방에 대해 처리하면
방의 개수와 가장 큰 방의 크기를 얻을 수 있고, 모든 인접한 두 방에 대해 서로 다른 방에 속하는 경우 두 방의 크기의 합을 각각 확인하면
벽을 하나 허물었을 때의 가장 큰 방의 크기도 구할 수 있다.

주요 알고리즘 : 그래프 이론, 플러드필, 브루트 포스

출처 : IOI 1994 2번
*/

int castle[64][64], rooms[64][64], size[4096];
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
int m, n, rc = 0, biggest = 0, bigroom = 0;

int isvalid(int x, int y, int d) {
    if (x < 0 || y < 0 || x >= m || y >= n) return 0;
    if (rooms[x][y] || (castle[x][y] & (1 << d))) return 0; //방의 벽 상태가 비트마스킹 형태로 주어지므로 이동한 칸이 벽인지를 비트 상태로 확인 가능하다.
    return 1;
}

void fillroom(int x, int y) {
    size[rc]++;
    rooms[x][y] = rc;
    for (int i = 0; i < 4; i++) {
        if (!isvalid(x + dxy[i][0], y + dxy[i][1], i)) continue;
        fillroom(x + dxy[i][0], y + dxy[i][1]);
    }
}

int main(void) {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &castle[i][j]);
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (rooms[i][j] == 0) {
                rc++;
                fillroom(i, j);
                if (size[rc] > biggest) biggest = size[rc];
            }
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (rooms[i][j] != rooms[i][j - 1]) {
                if (size[rooms[i][j]] + size[rooms[i][j - 1]] > bigroom) bigroom = size[rooms[i][j]] + size[rooms[i][j - 1]];
            }
        }
    }
    for (int i = 1; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (rooms[i][j] != rooms[i - 1][j]) {
                if (size[rooms[i][j]] + size[rooms[i - 1][j]] > bigroom) bigroom = size[rooms[i - 1][j]] + size[rooms[i][j]];
            }
        }
    }
    printf("%d\n%d\n%d", rc, biggest, bigroom);
    return 0;
}