#include <stdio.h>

int n, c = 0;
long long s = -1;

void track(int p, int r, long long x, int y) {
    if (p == r) {
        if (c == n) s = x;
        c++;
        return;
    }
    x *= 10;
    for (int i = 0; i < y; i++) {
        track(p, r + 1, x + i, i);
    }
}

int main(void) {
    scanf("%d", &n);
    for (int i = 1; i <= 10; i++) {
        track(i, 0, 0, 10);
    }
    printf("%lld", s);
    return 0;
}