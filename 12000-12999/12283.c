#include <stdio.h>

char maze[128][128], res[10240];
const char* dch = "ESWN";
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

int isvalid1(int n, int x, int y) {
    if (x < 0 || y < 0 || x >= n || y >= n) return 0;
    if (maze[x][y] == '#') return 0;
    return 1;
}

int isvalid2(int n, int x, int y) {
    if (x < 0 || y < 0 || x >= n || y >= n) return 1;
    if (maze[x][y] == '.') return 0;
    return 1;
}

int main(void) {
    int t, n, sx, sy, sd, x, y, d, ex, ey, rcnt;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%s", maze[i]);
        }
        scanf("%d %d %d %d", &sx, &sy, &ex, &ey);
        x = sx - 1, y = sy - 1;
        sd = 0;
        while (!isvalid2(n, x + dxy[(sd + 3) & 3][0], y + dxy[(sd + 3) & 3][1])) sd = ((sd + 1) & 3);
        d = sd;

        rcnt = 0;
        while (rcnt <= 10000) {
            if (x == ex - 1 && y == ey - 1) break;
            if (isvalid1(n, x + dxy[d][0], y + dxy[d][1]) &&
                isvalid2(n, x + dxy[d][0] + dxy[(d + 3) & 3][0], y + dxy[d][1] + dxy[(d + 3) & 3][1])) {
                res[rcnt++] = dch[d];
                x += dxy[d][0];
                y += dxy[d][1];
            }
            else if (isvalid1(n, x + dxy[d][0], y + dxy[d][1])) {
                res[rcnt++] = dch[d];
                if (x + dxy[d][0] == ex - 1 && y + dxy[d][1] == ey - 1) break;
                res[rcnt++] = dch[(d + 3) & 3];
                x += dxy[d][0] + dxy[(d + 3) & 3][0];
                y += dxy[d][1] + dxy[(d + 3) & 3][1];
                d = ((d + 3) & 3);
            }
            else d = ((d + 1) & 3);
            if (x == sx - 1 && y == sy - 1 && d == sd) {
                rcnt = 10001;
                break;
            }
        }
        res[rcnt] = '\0';
        printf("Case #%d: ", tt);
        if (rcnt > 10000) printf("Edison ran out of energy.\n");
        else printf("%d\n%s\n", rcnt, res);
    }
    return 0;
}