#include <stdio.h>
#include <queue>
using namespace std;

/*
문제 : R * C(R, C <= 1000) 크기의 격자가 있다. 이 격자에는 /와 \ 기호들이 있는데, /과 \는 각각 X와 Y좌표의 합이 홀수, 짝수
또는 그 반대인 칸에만 존재한다.(서로 홀짝성이 다르다.) 이 격자에서 /과 \로 싸여진 공간은 통과할 수 없다면,
모든 칸에서 바깥과 통하기 위해 제거해야 할 /나 \의 수를 구한다.

해결 방법 : /와 \로 싸여진 공간을 방이라고 하면, /나 \를 제거하면 서로 다른 방 2개를 연결 가능하다.
바깥쪽 방과 연결한다고 생각하면 제가해야 할 /와 \의 수는 방의 개수와 같다.
방의 개수를 세는 방법은 각 칸의 꼭짓점들을 정점으로 보고 BFS를 수행하는 것이다. 이때, /와 \의 홀짝성이 다르므로
/이 짝수인 칸에 나타나면 좌표의 합이 짝수, /이 홀수인 칸에 나타나면 홀수인 경우만 보면 된다.
BFS를 수행할 때에는 바깥과 연결된 칸인지 보기 위해 좌표 계산 과정에서 범위 바깥이 되는 경우 바깥에 있는 것으로 보고
방의 수를 증가시키지 않는다. 범위 바깥이 되는 경우가 없을 때에만 증가시키면 된다.

주요 알고리즘 : 그래프 이론, BFS, 구현

출처 : PacNW 2019 M번/Z번 // SEUSA 2019D1 I번
*/

char maze[1024][1024];
int vis[1024][1024];
int dxy[4][2] = { {1, 1}, {1, -1}, {-1, -1}, {-1, 1} };
int r, c, odd = 0, cellcnt = 0;
queue<pair<int, int>> q;

int blocking(int x, int y, int d) {
    //해당 칸으로 가는데 장애물이 존재하는지 확인한다.
    if (d == 0 && maze[x + 1][y + 1] == '/') return 1;
    if (d == 1 && maze[x + 1][y] == '\\') return 1;
    if (d == 2 && maze[x][y] == '/') return 1;
    if (d == 3 && maze[x][y + 1] == '\\') return 1;
    return 0;
}

int isvalid(int x, int y) {
    //해당 칸이 적절한 칸인지 구한다.
    if (x < 0 || y < 0 || x > r || y > c) return -1; //바깥으로 나가는 경우는 별도의 값으로 관리한다.
    if ((odd == -1 && ((x + y) & 1)) || (odd == 1 && !((x + y) & 1))) return 0;
    if (vis[x][y]) return 0;
    return 1;
}

void bfs(int x, int y) {
    int v, isout = 0;
    q.push(pair<int, int>(x, y));
    vis[x][y] = 1;
    while (q.size()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            if (blocking(x, y, i)) continue;
            v = isvalid(x + dxy[i][0], y + dxy[i][1]);
            if (v == -1) {
                isout = 1; //바깥으로 나가는 경우 바깥임을 따로 체크한다.
                continue;
            }
            if (v == 0) continue;
            q.push(pair<int, int>(x + dxy[i][0], y + dxy[i][1]));
            vis[x + dxy[i][0]][y + dxy[i][1]] = 1;
        }
    }
    if (isout == 0) cellcnt++;
    while (q.size()) q.pop();
}

int main(void) {
    scanf("%d %d", &r, &c);
    for (int i = 1; i <= r; i++) {
        scanf("%s", maze[i] + 1);
    }
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            if (maze[i][j] == '/') {
                if ((i + j) % 2 == 0) odd = -1;
                else odd = 1;
            }
            else if (maze[i][j] == '\\') {
                if ((i + j) % 2 == 0) odd = 1;
                else odd = -1;
            }
        }
    }
    if (odd == 0) {
        printf("0");
        return 0;
    }
    for (int i = 0; i <= r; i++) {
        for (int j = 0; j <= c; j++) {
            if (!isvalid(i, j)) continue; //이미 방문했거나 방문할 필요가 없는 칸인 경우
            bfs(i, j);
        }
    }
    printf("%d", cellcnt);
    return 0;
}