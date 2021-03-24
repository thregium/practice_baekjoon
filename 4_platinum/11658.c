#include <stdio.h>

int fw[1280][1280];

int sums(int x, int y) {
    int r = 0;
    int yy;
    while (x) {
        yy = y;
        while (yy) {
            r += fw[x][yy];
            yy -= yy & -yy;
        }
        x -= x & -x;
    }
    return r;
}

int sum(int x1, int y1, int x2, int y2) {
    return sums(x2, y2) - sums(x2, y1 - 1) - sums(x1 - 1, y2) + sums(x1 - 1, y1 - 1);
}

void chg(int x, int y, int n) {
    int t = n - sum(x, y, x, y);
    int yy;
    while (x <= 1024) {
        yy = y;
        while (yy <= 1024) {
            fw[x][yy] += t;
            yy += yy & -yy;
        }
        x += x & -x;
    }
}

int main(void) {
    int n, m, a, x1, y1, x2, y2;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &a);
            chg(i, j, a);
        }
    }
    for (int i = 0; i < m; i++) {
        scanf("%d", &a);
        if (a) {
            scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
            printf("%d\n", sum(x1, y1, x2, y2));
        }
        else {
            scanf("%d %d %d", &x1, &y1, &a);
            chg(x1, y1, a);
        }
    }
    return 0;
}