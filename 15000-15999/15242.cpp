#include <stdio.h>
#include <queue>
using namespace std;

/*
문제 : 체스판에서 나이트가 특정 장소에서 특정 장소로 가는데 필요한 최소 이동횟수를 출력한다.

해결 방법 : BFS를 통해 체스판의 칸별 최단거리를 구할 수 있고, 도착지의 최단거리를 출력하면 된다.

주요 알고리즘 : 그래프 이론, BFS

출처 : AIPO 2017F 5번
*/

int vis[8][8], dist[8][8];
int mv[8][2] = { {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2} }; //나이트의 이동
queue<pair<int, int>> q;

int isvalid(int x, int y) {
    if (x < 0 || y < 0 || x >= 8 || y >= 8) return 0;
    if (vis[x][y]) return 0;
    return 1;
}

int bfs(int x, int y, int xx, int yy) {
    q.push(pair<int, int>(x, y));
    vis[x][y] = 1;
    while (q.size()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for (int i = 0; i < 8; i++) {
            if (isvalid(x + mv[i][0], y + mv[i][1])) {
                vis[x + mv[i][0]][y + mv[i][1]] = 1;
                dist[x + mv[i][0]][y + mv[i][1]] = dist[x][y] + 1;
                q.push(pair<int, int>(x + mv[i][0], y + mv[i][1]));
            }
        }
    }
    return dist[xx][yy];
}

int main(void) {
    char t1[8], t2[8];
    scanf("%s%s", t1, t2);
    printf("%d", bfs(t1[0] - 'a', t1[1] - '1', t2[0] - 'a', t2[1] - '1'));
    return 0;
}
