#include <stdio.h>
#include <ctype.h>
#include <queue>
#include <tuple>
using namespace std;

/*
문제 : N * M(N, M <= 50) 크기의 미로에서 탈출하려고 한다. '0'에서 출발하고, '1'까지 가는데 걸리는 최단시간을 구한다.
'#'은 지나갈 수 없고, 알파벳 대문자(A - F)를 지나가기 위해서는 먼저 알파벳 소문자(a - f)를 지나야 한다.

해결 방법 : 각 알파벳 소문자를 얻었는지 여부를 비트마스킹을 통해 별도의 변수로 저장한다.
방문 배열에도 이를 따로 저장할 수 있고, XY좌표와 함께 BFS를 하면 된다.
만약 열쇠(알파벳 소문자)가 있는 칸에 도착한 경우 비트 or 연산을 통해 변수에 열쇠를 얻었다는 정보를 추가하는 것이 가능하고,
문(알파벳 대문자)이 있는 칸에 가려 하는 경우 역시 비트 and 연산을 통해 열쇠를 얻었는지 정보를 확인할 수 있다.
1이 여러개 존재 가능하므로 1이 등장한 순간 탐색을 종료하고 그때의 거리를 출력하면 된다.

주요 알고리즘 : 
*/

char maze[64][64], vis[64][64][64];
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
int n, m;
queue<tuple<int, int, int, int>> q; //x, y, 열쇠, 거리

int isvalid(int x, int y, int z) {
    if (x < 0 || y < 0 || x >= n || y >= m) return 0;
    if (vis[x][y][z] || maze[x][y] == '#') return 0;
    else if (isupper(maze[x][y])) {
        //문인 경우 열쇠를 얻었는지 여부를 추가로 확인한다.
        if (z & (1 << (maze[x][y] - 'A'))) return 1;
        else return 0;
    }
    else return 1;
}

int bfs(int x, int y) {
    int z, d;
    q.push(make_tuple(x, y, 0, 0));
    vis[x][y][0] = 1;
    while (q.size()) {
        x = get<0>(q.front());
        y = get<1>(q.front());
        z = get<2>(q.front());
        d = get<3>(q.front());
        q.pop();
        if (maze[x][y] == '1') return d; //탐색 종료
        else if (islower(maze[x][y])) z |= (1 << (maze[x][y] - 'a')); //열쇠가 있다면 열쇠 집기
        for (int i = 0; i < 4; i++) {
            if (isvalid(x + dxy[i][0], y + dxy[i][1], z)) {
                q.push(make_tuple(x + dxy[i][0], y + dxy[i][1], z, d + 1));
                vis[x + dxy[i][0]][y + dxy[i][1]][z] = 1;
            }
        }
    }
    return -1;
}

int main(void) {
    int x = -1, y = -1;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s", maze[i]);
        for (int j = 0; j < m; j++) {
            if (maze[i][j] == '0') {
                x = i;
                y = j;
            }
        }
    }
    if (x < 0) return 1;
    printf("%d", bfs(x, y));
    return 0;
}