#include <stdio.h>

int mem[16];
int count = 0, r = 0;

void track(int a, int b, int c, int d) {
    if (a == c) {
        count++;
        if (count == b) {
            printf("%d", mem[0]);
            for (int i = 1; i < d; i++) {
                printf("+%d", mem[i]);
            }
            r = 1;
        }
        return;
    }
    if (a < c) {
        return;
    }

    for (int i = 1; i <= 3; i++) {
        mem[d] = i;
        track(a, b, c + i, d + 1);
        mem[d] = 0;
    }
}

int main(void) {
    int n, k;
    scanf("%d %d", &n, &k);
    track(n, k, 0, 0);
    if (!r) printf("-1");
    return 0;
}