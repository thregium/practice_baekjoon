#include <stdio.h>

long long mem[10240];

int main(void) {
    int t, p, q;
    scanf("%d", &t);
    if (t > 10000) return 1;
    for (int tt = 1; tt <= t; tt++) {
        scanf("%d %d", &p, &q);
        mem[1] = 1 % q;
        mem[2] = 1 % q;
        for (int i = 3; i <= p; i++) {
            mem[i] = (mem[i - 1] + mem[i - 2]) % q;
        }
        printf("Case #%d: %d\n", tt, mem[p]);
    }
    return 0;
}