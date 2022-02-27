#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>
#include <tuple>
using namespace std;

/*
���� : 5 * 5 ũ���� 0 �Ǵ� 1�� ���� ���� 5�� �ִ�. �� �ǵ��� ���ϴ� ������ �������� ���� ����,
������� �̷� ��� ���� ������ �ٸ��� ������ �̵��ϴµ� �ɸ��� �ð��� �ּ��� ����
�̵� �ð��� ���Ѵ�. � �̷ο����� �װ��� �Ұ����� ��� -1�� ����Ѵ�.

�ذ� ��� : �� ���� ȸ�� ���⸶�� �������� ����, �� ��츶���� �̷θ� ����� BFS�� ����
�ִ� �̵��Ÿ��� ���� ª�� ���� ã���� �ȴ�. ȸ���� �����ϴٴ� �� ������
�������� ������ �ϳ��� �����ص� �ȴ�.

�ֿ� �˰��� : �׷��� �̷�, BFS, ���Ʈ ����, ����

��ó : BaaaaaaaaaaarkingDog
*/

int used[8], board[8][4][8][8], maze[8][8][8], vis[8][8][8], dist[8][8][8];
int r = 103000;
int dxy[6][3] = { {0, 0, 1}, {0, 0, -1}, {0, 1, 0}, {0, -1, 0}, {1, 0, 0}, {-1, 0, 0} };
queue<tuple<int, int, int>> q;

int isvalid(int x, int y, int z) {
    if (x < 0 || y < 0 || z < 0 || x >= 5 || y >= 5 || z >= 5) return 0;
    else if (maze[x][y][z] == 0 || vis[x][y][z]) return 0;
    return 1;
}

int bfs(int x, int y, int z) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 5; k++) {
                vis[i][j][k] = 0;
                dist[i][j][k] = 0;
            }
        }
    }
    q.push(make_tuple(x, y, z));
    vis[x][y][z] = 1;
    while (q.size()) {
        x = get<0>(q.front());
        y = get<1>(q.front());
        z = get<2>(q.front());
        q.pop();
        for (int i = 0; i < 6; i++) {
            if (isvalid(x + dxy[i][0], y + dxy[i][1], z + dxy[i][2])) {
                q.push(make_tuple(x + dxy[i][0], y + dxy[i][1], z + dxy[i][2]));
                vis[x + dxy[i][0]][y + dxy[i][1]][z + dxy[i][2]] = 1;
                dist[x + dxy[i][0]][y + dxy[i][1]][z + dxy[i][2]] = dist[x][y][z] + 1;
            }
        }
    }
    if (!vis[4][4][4]) return -1;
    else return dist[4][4][4];
}

void track(int h) {
    if (h == 5) {
        if (maze[0][0][0] == 0) return;
        int t = bfs(0, 0, 0);
        if (t >= 0 && t < r) r = t;
        return;
    }
    for (int i = 0; i < 5; i++) {
        if (used[i]) continue;
        used[i] = 1;
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 5; k++) {
                for (int l = 0; l < 5; l++) {
                    maze[h][k][l] = board[i][j][k][l];
                }
            }
            track(h + 1);
        }
        used[i] = 0;
    }
}

int main(void) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 5; k++) {
                scanf("%d", &board[i][0][j][k]);
            }
        }
        for (int j = 1; j <= 3; j++) {
            for (int k = 0; k < 5; k++) {
                for (int l = 0; l < 5; l++) {
                    board[i][j][k][l] = board[i][j - 1][l][4 - k];
                }
            }
        }
    }
    track(0);
    printf("%d", r == 103000 ? -1 : r);
    return 0;
}