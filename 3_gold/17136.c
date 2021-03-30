#include <stdio.h>

int paper[10][10], rem[6] = { 0, 5, 5, 5, 5, 5 };
int best = 101;

int available(int x, int y, int p) {
    if (x + p > 10 || y + p > 10 || rem[p] < 1) return 0;
    for (int i = x; i < x + p; i++) {
        for (int j = y; j < y + p; j++) {
            if (paper[i][j] != 1) return 0;
        }
    }
    return 1;
}

void put(int x, int y, int p, int t) {
    for (int i = x; i < x + p; i++) {
        for (int j = y; j < y + p; j++) {
            paper[i][j] = t;
        }
    }
}

void track(int x, int y, int d) {
    int t = 1;
    for (int i = x; i < 10; i++) {
        for (int j = (i == x ? y : 0); j < 10; j++) {
            if (paper[i][j] != 1) continue;
            t = 0;
            for (int p = 5; p > 0; p--) {
                if (available(i, j, p)) {
                    put(i, j, p, 2);
                    rem[p]--;
                    track(i, j, d + 1);
                    rem[p]++;
                    put(i, j, p, 1);
                }
            }
            if (!t) break;
        }
        if (!t) break;
    }
    if (t) {
        if (d < best) best = d;
    }
}

int main(void) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            scanf("%d", &paper[i][j]);
        }
    }
    track(0, 0, 0);
    printf("%d", best > 100 ? -1 : best);
    return 0;
}