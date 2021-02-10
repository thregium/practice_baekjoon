#include <stdio.h>

int mem[32];

int main(void) {
    int n, r = 0;
    scanf("%d", &n);
    mem[0] = 3;
    for (int i = 1; i < 28; i++) {
        mem[i] = mem[i - 1] * 2 + i + 3;
    }
    for (int i = 27; i >= 0; i--) {
        if (n > mem[i - 1]) {
            n -= mem[i - 1];
            if (n == 1) {
                r = 2;
                break;
            }
            else if (n > 1 && n <= i + 3) {
                r = 1;
                break;
            }
            n -= i + 3;
        }
    }
    if (r == 1) printf("o");
    else if (r == 2) printf("m");
    return 0;
}