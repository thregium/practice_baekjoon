#include <stdio.h>

int mem[32][16];

int bc(int a, int b) {
    if (mem[a][b]) mem[a][b];
    if (b == 0) return mem[a][b] = 1;
    if (a == b) return mem[a][b] = 1;
    return mem[a][b] = bc(a - 1, b - 1) + bc(a - 1, b);
}

int main(void) {
    int n, m, k, kx, ky;
    scanf("%d %d %d", &n, &m, &k);
    if (k == 0) {
        n--;
        m--;
        printf("%d", bc(n + m, m));
    }
    else {
        kx = (k - 1) / m;
        ky = (k - 1) % m;
        m--;
        n--;
        printf("%d", bc(kx + ky, ky) * bc(n - kx + m - ky, m - ky));
    }
    return 0;
}