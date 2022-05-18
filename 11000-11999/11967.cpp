#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

/*
문제 : N * N(N <= 100) 크기의 격자 형으로 방들이 있다. (1, 1)인 방에만 불이 켜져있고,
상하좌우로 불이 켜진 방으로 이동해 들어가는 것이 가능하다.
전체 M(M <= 20000)개의 스위치가 있고, 각 방에서 스위치가 연결된 방의 불을 켤 수 있다.
이때, 켤 수 있는 불의 최대 개수를 구한다.

해결 방법 : (1, 1)에서 출발하여 방들을 이동해 나간다. 방의 이동은 평범한 BFS와 같고,
불이 꺼진 방으로는 가지 않는다. 그 다음, 그 방에서 켤 수 있는 스위치를 모두 켠다.
그 가운데 이미 방문한 방과 인접한 방의 불이 켜진 경우 그 방으로 방문할 수 있었다는 의미이므로
큐에 그 방을 집어넣고 방문 처리를 해둔다. 이를 반복하여 불을 켠 횟수를 세면 답이 된다.

주요 알고리즘 : 그래프 이론, BFS

출처 : USACO 2015D S1번
*/

int vis[128][128], light[128][128];
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
vector<pair<int, int>> ed[128][128];
queue<pair<int, int>> q;

int isvalid(int x, int y, int n) {
    if (x < 1 || y < 1 || x > n || y > n) return 0;
    if (!light[x][y]) return 0;
    if (vis[x][y]) return -1;
    return 1;
}

int bfs(int x, int y, int n) {
    int res = 1;
    light[x][y] = 1;
    vis[x][y] = 1;
    q.push({ x, y });
    while (q.size()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            if (isvalid(x + dxy[i][0], y + dxy[i][1], n) > 0) {
                q.push({ x + dxy[i][0], y + dxy[i][1] });
                vis[x + dxy[i][0]][y + dxy[i][1]] = 1;
            }
        }

        for (auto& i : ed[x][y]) {
            if (!light[i.first][i.second]) {
                light[i.first][i.second] = 1;
                res++;
                for (int j = 0; j < 4; j++) {
                    if (isvalid(i.first + dxy[j][0], i.second + dxy[j][1], n) < 0) {
                        q.push({ i.first, i.second });
                        vis[i.first][i.second] = 1;
                        break;
                    }
                }
            }
        }
    }
    return res;
}

int main(void) {
    int n, m, a, b, c, d;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d %d", &a, &b, &c, &d);
        ed[a][b].push_back({ c, d });
    }
    printf("%d", bfs(1, 1, n));
    return 0;
}