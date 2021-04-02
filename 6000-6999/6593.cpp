#include <stdio.h>
#include <queue>
#include <tuple>
using namespace std;

char bd[32][32][32], vis[32][32][32];
int dist[32][32][32];
int dxyz[6][3] = { {0, 0, 1}, {0, 0, -1}, {0, 1, 0}, {0, -1, 0}, {1, 0, 0}, {-1, 0, 0} };
int l, r, c;
queue<tuple<int, int, int>> q;

int isvalid(int x, int y, int z) {
    if (x < 0 || y < 0 || z < 0 || x >= l || y >= r || z >= c) return 0;
    if (bd[x][y][z] == '#' || vis[x][y][z]) return 0;
    return 1;
}

int bfs(tuple<int, int, int> s) {
    q.push(s);
    int x, y, z, r = 0;
    while (q.size()) {
        x = get<0>(q.front());
        y = get<1>(q.front());
        z = get<2>(q.front());
        q.pop();
        if (bd[x][y][z] == 'E') {
            r = 1;
            break;
        }
        for (int i = 0; i < 6; i++) {
            if (isvalid(x + dxyz[i][0], y + dxyz[i][1], z + dxyz[i][2])) {
                vis[x + dxyz[i][0]][y + dxyz[i][1]][z + dxyz[i][2]] = 1;
                dist[x + dxyz[i][0]][y + dxyz[i][1]][z + dxyz[i][2]] = dist[x][y][z] + 1;
                q.push(make_tuple(x + dxyz[i][0], y + dxyz[i][1], z + dxyz[i][2]));
            }
        }
    }
    while (q.size()) q.pop();
    if (r) return dist[x][y][z];
    else return -1;
}

int main(void) {
    int t;
    tuple<int, int, int> s, e;
    while (1) {
        scanf("%d %d %d", &l, &r, &c);
        if (l == 0 && r == 0 && c == 0) break;
        for (int i = 0; i < l; i++) {
            for (int j = 0; j < r; j++) {
                scanf("%s", bd[i][j]);
                for (int k = 0; k < c; k++) {
                    if (bd[i][j][k] == 'S') {
                        s = make_tuple(i, j, k);
                        vis[i][j][k] = 1;
                    }
                }
            }
        }
        t = bfs(s);
        if (t < 0) printf("Trapped!\n");
        else printf("Escaped in %d minute(s).\n", t);
        for (int i = 0; i < l; i++) {
            for (int j = 0; j < r; j++) {
                for (int k = 0; k < c; k++) {
                    vis[i][j][k] = 0;
                    bd[i][j][k] = 0;
                    dist[i][j][k] = 0;
                }
            }
        }
    }
    return 0;
}