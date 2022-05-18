#include <stdio.h>

/*
문제 : R * C(R, C <= 100) 크기의 맵에 'G', '#', '.', 'S'가 있다. 'G'의 위치를 상하좌우로 T(T <= 10)회
움직여 'S'를 최대한 많이 먹으려 할 때, 먹을 수 있는 'S'의 최대 개수를 구한다.

해결 방법 : T의 범위가 작기 때문에 움직일 수 있는 경우를 모두 시도해보면 된다.
방문 처리에 유의한다.

주요 알고리즘 : 브루트 포스

출처 : 가희 1회 2번
*/

char map[128][128];
const int dxy[5][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0}, {0, 0} };
int r, c, best = 0;

int isvalid(int x, int y) {
    if (x < 0 || y < 0 || x >= r || y >= c) return 0;
    if (map[x][y] == '#') return 0;
    return 1;
}

void track(int x, int y, int t, int cnt) {
    char store;
    if (cnt > best) best = cnt;
    if (t == 0) return;
    for (int i = 0; i < 5; i++) {
        if (isvalid(x + dxy[i][0], y + dxy[i][1])) {
            store = map[x + dxy[i][0]][y + dxy[i][1]];
            map[x + dxy[i][0]][y + dxy[i][1]] = '.';
            track(x + dxy[i][0], y + dxy[i][1], t - 1, cnt + (store == 'S'));
            map[x + dxy[i][0]][y + dxy[i][1]] = store;
        }
    }
}

int main(void) {
    int t, x = -1, y = -1;
    scanf("%d %d %d", &r, &c, &t);
    for (int i = 0; i < r; i++) {
        scanf("%s", map[i]);
        for (int j = 0; j < c; j++) {
            if (map[i][j] == 'G') {
                if (x >= 0) return 1;
                x = i;
                y = j;
                map[i][j] = '.';
            }
        }
    }
    if (x < 0) return 1;

    track(x, y, t, 0);
    printf("%d", best);
    return 0;
}