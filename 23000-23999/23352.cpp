#include <stdio.h>
#include <queue>
using namespace std;

/*
문제 : N * M(N, M <= 50) 크기의 격자에서 0인 칸을 지나지 않고 만들 수 있는 가장 긴 경로(최단경로 사용) 가운데,
시작점과 끝점의 합이 가장 큰 것의 합을 구한다. 시작점과 끝점이 같을 수 있다. 경로가 없다면 0을 출력한다.

해결 방법 : 모든 지점에서 해당 지점에서 시작하여 갈 수 있는 모든 지점까지의 거리를 구하고,
가장 먼 거리와 합을 계산해가며 답을 찾아가면 된다.

주요 알고리즘 : 그래프 이론, BFS, 브루트 포스

출처 : 항공대 1회 E번
*/

int num[64][64], vis[64][64], dist[64][64];
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
int n, m;
queue<pair<int, int>> q;

int isvalid(int x, int y) {
    if (x < 0 || y < 0 || x >= n || y >= m) return 0;
    if (vis[x][y] || num[x][y] == 0) return 0;
    return 1;
}

void bfs(int x, int y) {
    int d;
    vis[x][y] = 1;
    q.push(pair<int, int>(x, y));
    while (q.size()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        d = dist[x][y];
        for (int i = 0; i < 4; i++) {
            if (!isvalid(x + dxy[i][0], y + dxy[i][1])) continue;
            q.push(pair<int, int>(x + dxy[i][0], y + dxy[i][1]));
            vis[x + dxy[i][0]][y + dxy[i][1]] = 1;
            dist[x + dxy[i][0]][y + dxy[i][1]] = dist[x][y] + 1;
        }
    }
}

int main(void) {
    int bdist = -1, res = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &num[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (num[i][j] == 0) continue;
            bfs(i, j);

            for (int x = 0; x < n; x++) {
                for (int y = 0; y < m; y++) {
                    if (vis[x][y] && dist[x][y] > bdist) {
                        bdist = dist[x][y];
                        res = num[i][j] + num[x][y];
                    }
                    else if (vis[x][y] && dist[x][y] == bdist && res < num[i][j] + num[x][y]) res = num[i][j] + num[x][y];
                    vis[x][y] = 0;
                    dist[x][y] = 0;
                }
            }
        }
    }
    printf("%d", res);
    return 0;
}