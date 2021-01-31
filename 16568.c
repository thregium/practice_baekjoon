#include <stdio.h>

int mem[1048576];

int small(int a, int b) {
    return a < b ? a : b;
}

int main(void) {
    int n, a, b;
    scanf("%d %d %d", &n, &a, &b);
    for (int i = 1; i <= n; i++) {
        mem[i] = mem[i - 1] + 1;
        if (i > a) {
            mem[i] = small(mem[i], mem[i - (a + 1)] + 1);
        }
        if (i > b) {
            mem[i] = small(mem[i], mem[i - (b + 1)] + 1);
        }
    }

    printf("%d", mem[n]);
    return 0;
}