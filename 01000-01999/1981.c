#include <stdio.h>

/*
문제 : N * N(N <= 100) 크기의 배열에 0 이상 200 이하의 수들이 쓰여 있다. 이때, 이 배열의 (1, 1)에서
상하좌우로 이동해 (N, N)으로 이동하며 경로에서 나올 수 있는 최댓값과 최솟값의 차이가
가장 작을 때의 차이를 구한다.

해결 방법 : 배열의 수 범위가 작은 편이므로 수의 시작점과 끝점을 한쪽 방향으로 옮겨가며
이동 가능한 값 가운데 차이가 최소인 경우를 찾아나가면 된다.
시작점과 끝점에서 들어갈 수 있는 지 여부를 미리 확인해야 함에 유의한다.

주요 알고리즘 : 그래프 이론, 플러드필, 투 포인터

출처 : TUD 2006 6번
*/

int a[128][128], vis[128][128];
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
int n, s = 0, e = 0;

int isvalid(int x, int y) {
    if (x < 0 || y < 0 || x >= n || y >= n) return 0;
    if (vis[x][y] || a[x][y] < s || a[x][y] > e) return 0;
    return 1;
}

int dfs(int x, int y) {
    if (!isvalid(x, y)) return 0;
    vis[x][y] = 1;
    int r = 0;
    if (x == n - 1 && y == n - 1) return 1;
    for (int i = 0; i < 4; i++) {
        if (isvalid(x + dxy[i][0], y + dxy[i][1])) r |= dfs(x + dxy[i][0], y + dxy[i][1]);
    }
    return r;
}

int main(void) {
    int r = 103000;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    while (s <= 200) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) vis[i][j] = 0;
        }
        while (e <= 200 && !dfs(0, 0)) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) vis[i][j] = 0;
            }
            e++;
        }
        if (e <= 200 && e - s < r) r = e - s;
        s++;
    }
    printf("%d", r);
    return 0;
}