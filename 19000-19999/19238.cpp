#include <stdio.h>
#include <math.h>
#include <queue>
using namespace std;

/*
문제 : N * N(N <= 20) 크기의 격자에서 택시가 이동한다. 택시는 처음에 (X, Y)에 있고, 가장 가까운 손님 가운데 행 번호와 열 번호가 가장 작은 손님에게 간다.
손님에게 간 다음 목적지까지 이동하고, 손님을 태운 거리 * 2만큼의 연료를 받는다. 연료는 1칸을 이동할 때 마다 1씩 줄어든다.
모든 손님을 태운 후 남은 연료의 양을 구한다. 처음에 연료는 L만큼 있고, 중간에 연료가 전부 떨어지거나 모든 손님을 목적지로 보내는 것이 불가능하다면 -1을 출력한다.
손님은 모두 M(M <= 500)명이다.

해결 방법 : 시작점에서부터 BFS를 통해 태울 손님을 찾고, 해당 지점에서 다시 BFS를 통해 목적지까지의 거리를 구한다. 이를 M회 반복한 다음 남은 연료량을 구하면 되는데,
다 반복하지 않았음에도 태울 손님이 없거나 도중에 연료가 바닥나는 경우 중간에 끊고 -1을 출력하면 된다.

주요 알고리즘 : 그래프 이론, BFS, 시뮬레이션
*/

int city[32][32], vis[32][32], dist[32][32], cl[512][2];
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
int n, nx, ny, cnt;
queue<pair<int, int>> q;

void clearmap(void) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            vis[i][j] = 0;
            dist[i][j] = 0;
        }
    }
    while (q.size()) q.pop();
}

int isvalid(int x, int y) {
    if (x < 0 || y < 0 || x >= n || y >= n) return 0;
    else if (city[x][y] > 0 || vis[x][y]) return 0;
    else return 1;
}

int bfs1(int x, int y) {
    //가장 가까운 손님 확인, 반환값은 2^20 * 거리 + 2^10 * X + Y, 없다면 -1
    clearmap();
    q.push(pair<int, int>(x, y));
    vis[x][y] = 1;
    while (q.size()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            if (isvalid(x + dxy[i][0], y + dxy[i][1])) {
                q.push(pair<int, int>(x + dxy[i][0], y + dxy[i][1]));
                vis[x + dxy[i][0]][y + dxy[i][1]] = 1;
                dist[x + dxy[i][0]][y + dxy[i][1]] = dist[x][y] + 1;
            }
        }
    }

    int bestdist = 9999;
    x = -1;
    y = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (city[i][j] && vis[i][j] && dist[i][j] < bestdist) {
                bestdist = dist[i][j];
                x = i;
                y = j;
            }
        }
    }
    if (x < 0) return -1;
    return bestdist * 1048576 + x * 1024 + y;
}

int bfs2(int x, int y) {
    //목적지까지의 거리 확인, 도달 불가시엔 -9999
    clearmap();
    q.push(pair<int, int>(x, y));
    vis[x][y] = 1;
    int n = -city[x][y];
    city[x][y] = 0;
    while (q.size()) {
        x = q.front().first;
        y = q.front().second;
        if (cl[n][0] == x && cl[n][1] == y) {
            nx = cl[n][0];
            ny = cl[n][1];
            return dist[x][y];
        }
        q.pop();
        for (int i = 0; i < 4; i++) {
            if (isvalid(x + dxy[i][0], y + dxy[i][1])) {
                q.push(pair<int, int>(x + dxy[i][0], y + dxy[i][1]));
                vis[x + dxy[i][0]][y + dxy[i][1]] = 1;
                dist[x + dxy[i][0]][y + dxy[i][1]] = dist[x][y] + 1;
            }
        }
    }
    return -9999;
}

int main(void) {
    int m, l, x, y, a, b, c;
    scanf("%d %d %d", &n, &m, &l);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &city[i][j]);
        }
    }
    scanf("%d %d", &x, &y);
    x--; //칸을 맞추기 위함
    y--;
    for (int i = 1; i <= m; i++) {
        scanf("%d %d", &a, &b);
        city[a - 1][b - 1] = -i; //해당 위치에 손님을 넣어준다.
        scanf("%d %d", &cl[i][0], &cl[i][1]);
        cl[i][0]--; //위와 같은 이유
        cl[i][1]--;
    }

    for (int i = 1; i <= m; i++) {
        a = bfs1(x, y);
        if (a < 0) {
            l = -1; //손님을 모두 받지 않았지만 손님이 없는 경우
            break;
        }
        b = (a >> 20);
        c = bfs2((a >> 10) & 1023, a & 1023);
        if (c < 0) {
            l = -1; //목적지까지 갈 수 없는 경우
            break;
        }

        if (l < b + c) {
            l = -1; //연료가 떨어진 경우
            break;
        }
        else {
            l += c - b; //성공한 경우
            x = nx;
            y = ny;
        }
    }
    printf("%d", l);
    return 0;
}