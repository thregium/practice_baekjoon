#include <stdio.h>

/*
문제 : H * W(H, W <= 100) 크기의 땅에서 N개의 지점의 높이가 측량되었다. 각 상하좌우로 인접한
지점들 사이 높이 차를 1 이하로 만들 수 있는 지 확인하고, 그러한 경우 전체 지점의 높이 합이
가장 작을 때의 높이 합을 구한다.

해결 방법 : 높은 지점부터 차례로 확인하면서 주변 지점으로 높이를 1씩 내려나간다.
이 과정에서 내려온 지형도 주변에 높이가 확정되지 않은 지점으로 높이를 1씩 내려나갈 수 있다.
이를 반복한 다음 인접한 지점 사이 높이 차가 2 이상인 지점이 있다면 만들 수 없는 것이고,
그 외에는 이렇게 하면 전체 높이 합이 최소가 되므로 높이 합을 구해 답을 출력하면 된다.

주요 알고리즘 : 그래프 이론, BFS

출처 : Yokohama 2019 B번
*/

int ht[128][128], vis[128][128];
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
int h, w;

int isvalid(int x, int y) {
    if (x < 0 || y < 0 || x >= h || y >= w) return 0;
    if (vis[x][y]) return -1;
    return 1;
}

int main(void) {
    int n, x, y, t, res = 0, va = 1;
    scanf("%d %d %d", &h, &w, &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &x, &y, &t);
        x--, y--;
        ht[x][y] = t;
        vis[x][y] = 1;
    }
    for (int i = 100; i >= -300; i--) {
        for (int j = 0; j < h; j++) {
            for (int k = 0; k < w; k++) {
                if (!vis[j][k] || ht[j][k] != i) continue;
                for (int d = 0; d < 4; d++) {
                    if (isvalid(j + dxy[d][0], k + dxy[d][1]) <= 0) continue;
                    ht[j + dxy[d][0]][k + dxy[d][1]] = i - 1;
                    vis[j + dxy[d][0]][k + dxy[d][1]] = 1;
                }
            }
        }
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            for (int d = 0; d < 4; d++) {
                if (!isvalid(i + dxy[d][0], j + dxy[d][1])) continue;
                if (abs(ht[i][j] - ht[i + dxy[d][0]][j + dxy[d][1]]) > 1) va = 0;
            }
            res += ht[i][j];
        }
    }
    if (va) printf("%d\n", res);
    else printf("No\n");
    return 0;
}