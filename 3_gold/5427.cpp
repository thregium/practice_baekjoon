#include <stdio.h>
#include <queue>
using namespace std;

char mp[1024][1024];
int vish[1024][1024], disth[1024][1024], visf[1024][1024], distf[1024][1024];
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
int w, h;
queue<pair<int, int>> qh, qf;

int fvalid(int x, int y) {
    if (x < 0 || x >= h || y < 0 || y >= w) return 0;
    if (mp[x][y] != '.' || visf[x][y]) return 0;
    return 1;
}

int hvalid(int x, int y, int c) {
    if (x < 0 || x >= h || y < 0 || y >= w) return 0;
    if (mp[x][y] != '.' || (visf[x][y] && distf[x][y] <= c) || vish[x][y]) return 0;
    return 1;
}

void bfsf(void) {
    int x, y;
    while (qf.size()) {
        x = qf.front().first;
        y = qf.front().second;
        qf.pop();
        for (int i = 0; i < 4; i++) {
            if (fvalid(x + dxy[i][0], y + dxy[i][1])) {
                visf[x + dxy[i][0]][y + dxy[i][1]] = 1;
                distf[x + dxy[i][0]][y + dxy[i][1]] = distf[x][y] + 1;
                qf.push(pair<int, int>(x + dxy[i][0], y + dxy[i][1]));
            }
        }
    }
    return;
}

int bfsh(void) {
    int x, y;
    while (qh.size()) {
        x = qh.front().first;
        y = qh.front().second;
        if (x == 0 || y == 0 || x == h - 1 || y == w - 1) return disth[x][y] + 1;
        qh.pop();
        for (int i = 0; i < 4; i++) {
            if (hvalid(x + dxy[i][0], y + dxy[i][1], disth[x][y] + 1)) {
                vish[x + dxy[i][0]][y + dxy[i][1]] = 1;
                disth[x + dxy[i][0]][y + dxy[i][1]] = disth[x][y] + 1;
                qh.push(pair<int, int>(x + dxy[i][0], y + dxy[i][1]));
            }
        }
    }
    return -1;
}

int main(void) {
    int t, r;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d %d", &w, &h);
        for (int i = 0; i < h; i++) {
            scanf("%s", mp[i]);
            for (int j = 0; j < w; j++) {
                if (mp[i][j] == '@') {
                    qh.push(pair<int, int>(i, j));
                    vish[i][j] = 1;
                    mp[i][j] = '.';
                }
                if (mp[i][j] == '*') {
                    qf.push(pair<int, int>(i, j));
                    visf[i][j] = 1;
                    mp[i][j] = '.';
                }
            }
        }
        bfsf();
        r = bfsh();
        if (r < 0) printf("IMPOSSIBLE\n");
        else printf("%d\n", r);
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                vish[i][j] = 0;
                visf[i][j] = 0;
                disth[i][j] = 0;
                distf[i][j] = 0;
            }
        }
        while (!qh.empty()) qh.pop();
    }
    return 0;
}