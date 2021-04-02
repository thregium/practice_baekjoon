#include <stdio.h>

int f[128];

int main(void) {
    int a, b, c, d, r = 0;
    fscanf("%d %d %d %d", &a, &b, &c, &d);
    for (int i = a; i < b; i++) {
        f[i] = 1;
    }
    for (int i = c; i < d; i++) {
        f[i] = 1;
    }
    for (int i = 0; i <= 100; i++) {
        r += f[i];
    }
    printf("%d", r);
    return 0;
}