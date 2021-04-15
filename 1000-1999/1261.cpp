#include <stdio.h>
#include <queue>
#define INF 1012345678
using namespace std;

/*
문제 : 0과 1로 이루어진 미로가 있을 때, 1을 가장 적게 거치고 미로의 왼쪽 위에서 오른쪽 아래로 간 경우 거치게 되는 1의 수를 출력한다.

해결 방법 : 다익스트라를 이용해 1을 지난 경우 거리가 1이 되고, 0을 지나는 경우 거리가 0이 되도록 그래프를 만들고 최단거리를 출력한다.

주요 알고리즘 : 그래프 이론, 다익스트라
*/

char mz[128][128];
int path[128][128][4][3], dist[128][128], visit[128][128];
int dxy[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main(void) {
    int m, n, x, y, pb = 0;
    scanf("%d %d", &m, &n);
    for (int i = 1; i <= n; i++) {
        scanf("%s", mz[i] + 1);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int k = 0; k < 4; k++) {
                if (i + dxy[k][0] < 1 || j + dxy[k][1] < 1 || i + dxy[k][0] > n || j + dxy[k][1] > m) continue;
                path[i][j][k][0] = mz[i + dxy[k][0]][j + dxy[k][1]] - '0';
                path[i][j][k][1] = i + dxy[k][0];
                path[i][j][k][2] = j + dxy[k][1];
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) dist[i][j] = INF;
    }
    dist[1][1] = 0;
    pq.push(pair<int, int>(0, 1 + 1024));

    for (int i = 0; i < n * m; i++) {
        if (pb < pq.size()) pb = pq.size();
        x = pq.top().second / 1024;
        y = pq.top().second % 1024;
        while (visit[x][y]) {
            pq.pop();
            x = pq.top().second / 1024;
            y = pq.top().second % 1024;
        }
        visit[x][y] = 1;
        pq.pop();
        for (int i = 0; i < 4; i++) {
            if (path[x][y][i][1] == 0 && path[x][y][i][2] == 0) continue;
            if (visit[path[x][y][i][1]][path[x][y][i][2]]) continue;
            if (dist[path[x][y][i][1]][path[x][y][i][2]] > dist[x][y] + path[x][y][i][0]) dist[path[x][y][i][1]][path[x][y][i][2]] = dist[x][y] + path[x][y][i][0];
            pq.push(pair<int, int>(dist[path[x][y][i][1]][path[x][y][i][2]], path[x][y][i][1] * 1024 + path[x][y][i][2]));
        }
    }
    printf("%d", dist[n][m]);
    return 0;
}