#include <stdio.h>

/*
문제 : R * C(R, C <= 5) 크기의 격자에서 왼쪽 아래부터 오른쪽 위까지 'T'인 부분을 지나지 않고
같은 칸을 2번 이상 지나지 않는 길이 K(K <= 25)의 경로 개수를 구한다.

해결 방법 : R과 C가 작기 때문에 백트래킹을 이용해 모든 경우를 해볼 수 있다. 각 방향으로 이동하며 지나온 길을 표시하고,
이동할 곳이 없다면 마지막 칸을 지우고 이전 칸에서 마저 탐색하는 방식이다.

주요 알고리즘 : 브루트 포스, 백트래킹

출처 : USACO 2009J B2번
*/

char map[8][8], chk[8][8];
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
int r, c, k, res = 0;

int isvalid(int x, int y) {
    if (x < 0 || y < 0 || x >= r || y >= c) return 0;
    if (chk[x][y] || map[x][y] == 'T') return 0;
    return 1;
}

void track(int x, int y, int d) {
    if (x == 0 && y == c - 1) {
        if (d == k) res++;
        return;
    }
    chk[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        if (isvalid(x + dxy[i][0], y + dxy[i][1])) track(x + dxy[i][0], y + dxy[i][1], d + 1);
    }
    chk[x][y] = 0;
}

int main(void) {
    scanf("%d %d %d", &r, &c, &k);
    for (int i = 0; i < r; i++) {
        scanf("%s", map[i]);
    }
    track(r - 1, 0, 1);
    printf("%d", res);
    return 0;
}