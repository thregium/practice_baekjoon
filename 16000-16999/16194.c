#include <stdio.h>
#define INF 1234567890

int p[1024], mem[1024];

int main(void) {
    int n, l;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &p[i]);
        l = INF;
        for (int j = 1; j <= n; j++) {
            if (i >= j && mem[i - j] + p[j] < l) l = mem[i - j] + p[j];
        }
        mem[i] = l;
    }
    printf("%d", mem[n]);
    return 0;
}