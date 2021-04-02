#include <stdio.h>

char vis[256][256][256], r[256];
int a, b, c;

int big(int x, int y) {
    return x > y ? x : y;
}

int small(int x, int y) {
    return x < y ? x : y;
}

void track(int x, int y, int z) {
    if (vis[x][y][z]) return;
    vis[x][y][z] = 1;
    if (x == 0) r[z] = 1;
    track(big(x - (b - y), 0), small(x + y, b), z);
    track(big(x - (c - z), 0), y, small(x + z, c));
    track(small(x + y, a), big(y - (a - x), 0), z);
    track(x, big(y - (c - z), 0), small(y + z, c));
    track(small(x + z, a), y, big(z - (a - x), 0));
    track(x, small(y + z, b), big(z - (b - y), 0));
}

int main(void) {
    scanf("%d %d %d", &a, &b, &c);
    track(0, 0, c);
    for (int i = 0; i <= c; i++) {
        if (r[i]) printf("%d ", i);
    }
    return 0;
}