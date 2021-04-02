#include <stdio.h>

int mem[32];

int main(void) {
    int n;
    scanf("%d", &n);
    mem[0] = 0;
    mem[1] = 1;
    mem[2] = 2;
    mem[3] = 4;
    mem[4] = 7;
    for (int i = 4; i <= n; i++) {
        if (i % 2) {
            mem[i] = mem[i - 1] + mem[i - 2] + mem[i - 3] + mem[i - 4];
        }
        else {
            mem[i] = mem[i - 1] + mem[i - 2] + mem[i - 3];
        }
    }
    printf("%d", mem[n]);
    return 0;
}