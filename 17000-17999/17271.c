#include <stdio.h>
#define DIV 1000000007

int mem[10240];

int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);
    mem[0] = 1;
    for (int i = 1; i <= n; i++) {
        mem[i] = (mem[i - 1] + (m > i ? 0 : mem[i - m])) % DIV;
    }
    printf("%d", mem[n]);
    return 0;
}