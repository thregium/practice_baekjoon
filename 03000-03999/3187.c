#include <stdio.h>

/*
문제 : R * C(R, C <= 250) 크기의 격자에서 울타리와 양, 늑대의 위치가 주어진다. 각 울타리로 둘러싸인 영역 안에서
양, 늑대는 상하좌우로 움직일 수 있다. 같은 영역의 양의 수가 늑대의 수보다 많다면 양이 모든 늑대를 쫓아내고,
그 외에는 늑대가 모든 양을 먹는다면 남아있는 양과 늑대의 수를 구한다. 울타리 밖에는 양과 늑대가 없다.

해결 방법 : 플러드필을 통해 울타리 영역마다 안에 있는 양과 늑대의 수를 구한다. 둘 중 더 많은 쪽만 남기고(같은 경우 늑대),
나머진 버린 다음 결과에 더하는 것을 반복한다. 그리고 결과를 출력하면 된다.

주요 알고리즘 : 그래프 이론, 플러드필

출처 : CHCI 2005RS 3번
*/

char f[256][256];
int vis[256][256];
int r, c;

int isvalid(int x, int y) {
    if (x < 0 || y < 0 || x >= r || y >= c) return 0;
    if (f[x][y] == '#' || vis[x][y]) return 0;
    return 1;
}

long long dfs(int x, int y, long long sw) {
    vis[x][y] = 1;
    if (f[x][y] == 'k') sw += 1000000;
    else if (f[x][y] == 'v') sw++;
    if (isvalid(x, y + 1)) sw += dfs(x, y + 1, 0);
    if (isvalid(x + 1, y)) sw += dfs(x + 1, y, 0);
    if (isvalid(x, y - 1)) sw += dfs(x, y - 1, 0);
    if (isvalid(x - 1, y)) sw += dfs(x - 1, y, 0);
    return sw;
}

int main(void) {
    int s = 0, w = 0;
    long long sw;
    scanf("%d %d", &r, &c);
    for (int i = 0; i < r; i++) {
        scanf("%s", f[i]);
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (!isvalid(i, j)) continue;
            sw = dfs(i, j, 0);
            if (sw / 1000000 > sw % 1000000) s += sw / 1000000;
            else w += sw % 1000000;
        }
    }
    printf("%d %d", s, w);
    return 0;
}