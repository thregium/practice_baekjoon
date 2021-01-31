#include <stdio.h>
#include <math.h>
#define DIV 1000000

int mem[1048576];

int main(void) {
    int n;
    mem[0] = 1;
    for (int i = 1; i <= 1000000; i++) {
        mem[i] = (mem[(int)(i - sqrt(i))] + mem[(int)(log(i))] + mem[(int)(i * sin(i) * sin(i))]) % DIV;
    }
    while (1) {
        scanf("%d", &n);
        if (n < 0) break;
        printf("%d\n", mem[n]);
    }
    return 0;
}