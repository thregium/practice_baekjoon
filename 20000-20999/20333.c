#include <stdio.h>
#include <stdlib.h>

/*
문제 : H * W(H, W <= 500) 크기의 격자에 건물들의 높이가 주어진다. 여기서 엘리베이터를 설치해 건물을 올라가지 않고도
모든 건물의 모든 층에 도달할 수 있도록 할 때, 필요한 엘리베이터의 최소 개수를 구한다. 단, 1층인 경우 엘리베이터 없이 이동 가능하다.

해결 방법 : 어떤 건물의 최상층에 도달 가능하다면 그 층에서 내려오면서 모든 층에 도달 가능하다.
따라서, 최상층이 높은 건물부터 차례로 내려오며 플러드필을 통해 도달 가능한 건물들을 체크하면 된다.
주변의 건물이 현재 건물보다 높지 않다면 이동 가능한 건물이다. 건물의 높이가 1 이하까지 내려오면 더이상 볼 필요가 없으므로 탐색을 종료한다.

주요 알고리즘 : 그래프 이론, 플러드필, 그리디 알고리즘

출처 : UKIEPC 2020 E번 // BAPC 2020 E번
*/

int grid[512][512], vis[512][512], heights[262144][3];
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
int h, w;

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai < bi ? 1 : ai == bi ? 0 : -1;
}

int isvalid(int x, int y, int ht) {
    if (x < 0 || y < 0 || x >= h || y >= w) return 0;
    if (vis[x][y] || grid[x][y] > ht || grid[x][y] == 0) return 0;
    return 1;
}

void dfs(int x, int y, int h) {
    vis[x][y] = 1;
    if (grid[x][y] < h) h = grid[x][y];
    for (int i = 0; i < 4; i++) {
        if (!isvalid(x + dxy[i][0], y + dxy[i][1], h)) continue;
        dfs(x + dxy[i][0], y + dxy[i][1], h);
    }
}

int main(void) {
    int cnt = 0;
    scanf("%d %d", &h, &w);
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            scanf("%d", &grid[i][j]);
            heights[i * w + j][0] = grid[i][j];
            heights[i * w + j][1] = i;
            heights[i * w + j][2] = j;
        }
    }

    qsort(heights, h * w, sizeof(int) * 3, cmp1);
    for (int i = 0; i < h * w; i++) {
        if (heights[i][0] <= 1) break;
        if (vis[heights[i][1]][heights[i][2]]) continue;
        cnt++;
        dfs(heights[i][1], heights[i][2], heights[i][0]);
    }
    printf("%d", cnt);
    return 0;
}