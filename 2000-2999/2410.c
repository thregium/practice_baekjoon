#include <stdio.h>
#define DIV 1000000000

int mem[24][1048576];

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i <= 20; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0) mem[i][j] = 1;
            else mem[i][j] = (mem[i - 1][j] + (((1 << i) > j) ? 0 : mem[i][j - (1 << i)])) % DIV;
        }
    }
    printf("%d", mem[20][n]);
    return 0;
}