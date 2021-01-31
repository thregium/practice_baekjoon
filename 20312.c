#include <stdio.h>
#define DIV 1000000007

int com[524288], mem[524288];

int main(void) {
    int n, r = 0;
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        scanf("%d", &com[i]);
        if (i == 1) mem[i] = com[i];
        else mem[i] = ((long long)com[i] * ((long long)mem[i - 1] + 1)) % DIV;
    }
    for (int i = 1; i < n; i++) {
        r = (r + mem[i]) % DIV;
    }
    printf("%d", r);
    return 0;
}