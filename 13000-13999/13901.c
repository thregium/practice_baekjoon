#include <stdio.h>

/*
문제 : R * C(R, C <= 1000) 크기의 판에서 로봇의 이동 방향과 장애물의 위치 등이 주어지면 로봇이 멈추게 되는 곳의 위치를 구한다.

해결 방법 : 문제에 주어진대로 시뮬레이션한다. 자세한 내용은 추가 예정

주요 알고리즘 : 구현, 시뮬레이션

출처 : 서강대 12회C B번
*/

char vis[1024][1024];
int inst[4];
const int dxy[5][2] = { {0, 0}, {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
int r, c;

int isvalid(int x, int y) {
    if (x < 0 || y < 0 || x >= r || y >= c) return 0;
    if (vis[x][y]) return 0;
    return 1;
}

int main(void) {
    int k, br, bc, sr, sc, chk;
    scanf("%d %d%d", &r, &c, &k);
    for (int i = 0; i < k; i++) {
        scanf("%d %d", &br, &bc);
        vis[br][bc] = 1;
    }
    scanf("%d %d", &sr, &sc);
    vis[sr][sc] = 1;
    for (int i = 0; i < 4; i++) {
        scanf("%d", &inst[i]);
    }
    while (1) {
        chk = 0;
        for (int i = 0; i < 4; i++) {
            if (isvalid(sr + dxy[inst[i]][0], sc + dxy[inst[i]][1])) {
                sr += dxy[inst[i]][0];
                sc += dxy[inst[i]][1];
                vis[sr][sc] = 1;
                chk = 1;
            }
        }
        if (!chk) break;
    }
    printf("%d %d", sr, sc);
    return 0;
}