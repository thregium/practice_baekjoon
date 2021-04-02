#include <stdio.h>

int two[1024][1024], five[1024][1024], mem2[1024][1024], mem5[1024][1024];

int small(int a, int b) {
    if (a < 0 && b < 0) return -1;
    if (a < 0) return b;
    if (b < 0) return a;
    return a < b ? a : b;
}

int main(void) {
    int n, x, c, u, l;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &x);
            if (x == 0) {
                two[i][j] = -1;
                five[i][j] = -1;
                continue;
            }
            c = 0;
            for (int y = x; !(y % 2); y /= 2) c++;
            two[i][j] = c;
            c = 0;
            for (int y = x; !(y % 5); y /= 5) c++;
            five[i][j] = c;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 && j == 0) {
                mem2[i][j] = two[i][j];
                mem5[i][j] = five[i][j];
                continue;
            }
            u = (i == 0) ? -1 : mem2[i - 1][j];
            l = (j == 0) ? -1 : mem2[i][j - 1];
            mem2[i][j] = small(u, l);
            if (mem2[i][j] >= 0) mem2[i][j] += two[i][j];
            if (two[i][j] < 0) mem2[i][j] = -1;
            u = (i == 0) ? -1 : mem5[i - 1][j];
            l = (j == 0) ? -1 : mem5[i][j - 1];
            mem5[i][j] = small(u, l);
            if (mem5[i][j] >= 0) mem5[i][j] += five[i][j];
            if (five[i][j] < 0) mem5[i][j] = -1;
        }
    }
    printf("%d", small(mem2[n - 1][n - 1], mem5[n - 1][n - 1]));
    return 0;
}