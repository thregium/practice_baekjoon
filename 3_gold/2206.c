#include <stdio.h>

char map[1024][1024], vis[1024][1024][2];
int q[103000][3];
int qf = 0, qr = 1, n, m;
int dxy[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };

int isvalid(int x, int y, int c) {
    if (x < 1 || y < 1 || x > n || y > m) return 0;
    if (vis[x][y][c]) return 0;
    if (c) {
        if (map[x][y] == '0') return 2;
        else return 0;
    }
    else {
        if (map[x][y] == '0') return 1;
        else return 2;
    }
}

int main(void) {
    int x = 0, y = 0, c = 0, move = 1;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%s", map[i] + 1);
    }
    q[0][0] = 1;
    q[0][1] = 1;
    while (qr - qf) {
        for (int qs = qr > qf ? qr - qf : qr + 100000 - qf; qs;) {
            x = q[qf][0];
            y = q[qf][1];
            c = q[qf][2];
            qf++;
            if (qf >= 100000) qf -= 100000;
            qs--;
            if (vis[x][y][c]) continue;
            vis[x][y][c] = 1;
            if (x == n && y == m) break;
            for (int i = 0; i < 4; i++) {
                int v = isvalid(x + dxy[i][0], y + dxy[i][1], c);
                if (v) {
                    q[qr][0] = x + dxy[i][0];
                    q[qr][1] = y + dxy[i][1];
                    q[qr][2] = v - 1;
                    qr++;
                    if (qr >= 100000) qr -= 100000;
                }
            }
        }
        if (x == n && y == m) break;
        move++;
    }
    if (x == n && y == m) printf("%d", move);
    else printf("-1");
    return 0;
}
