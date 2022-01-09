#include <stdio.h>

/*
문제 : N * M(N, M <= 50) 크기의 지형에서 높이(<= 9, 자연수)가 주어질 때, 지형 안에 가두어 둘 수 있는 물의 양을 구한다.
상하좌우로 막혀있는 경우 가두어 둘 수 있는 부분이다.

해결 방법 : 높이 1부터 확인해 나가며 해당 높이 이하의 연결된 땅들을 확인한다. 만약 테두리로 나갈 수 있는 경우,
가두어 둘 수 없는 부분이고, 나갈 수 없다면 가두어 둘 수 있는 부분이다. 가두어 둘 수 있는 부분의 넓이를
모든 높이에 대해 전부 더하면 답이 된다.

주요 알고리즘 : 그래프 이론, 플러드필
*/

char height[64][64], vis[64][64];
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
int n, m;

int isvalid(int x, int y, int h) {
    if (x < 0 || y < 0 || x >= n || y >= m) return -1;
    else if (vis[x][y] || height[x][y] > h + '0') return 0;
    else return 1;
}

int dfs(int x, int y, int h) {
    int r = 1, t;
    vis[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        t = isvalid(x + dxy[i][0], y + dxy[i][1], h);
        if (t < 0) r = -1;
        else if (t > 0) {
            t = dfs(x + dxy[i][0], y + dxy[i][1], h);
            if (t < 0 || r < 0) r = -1;
            else r += t;
        }
    }
    return r;
}

int main(void) {
    int r = 0, t;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s", height[i]);
    }
    for (int i = 1; i <= 8; i++) {
        for (int x = 0; x < n; x++) {
            for (int y = 0; y < m; y++) {
                if (!vis[x][y] && height[x][y] <= i + '0') {
                    t = dfs(x, y, i);
                    if (t > 0) r += t;
                }
            }
        }

        for (int x = 0; x < n; x++) {
            for (int y = 0; y < m; y++) vis[x][y] = 0;
        }
    }
    printf("%d", r);
    return 0;
}