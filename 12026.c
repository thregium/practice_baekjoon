#include <stdio.h>
#define INF 1234567890

char boj[1024];
int mem[1024][3];

int small(int a, int b) {
    return a < b ? a : b;
}

int main(void) {
    int n, r;
    scanf("%d", &n);
    scanf("%s", boj);
    mem[0][1] = INF;
    mem[0][2] = INF;
    for (int i = 1; i < n; i++) {
        mem[i][0] = INF;
        mem[i][1] = INF;
        mem[i][2] = INF;
        for (int j = i - 1; j >= 0; j--) {
            if (boj[i] == 'O' && boj[j] == 'B') {
                mem[i][1] = small(mem[i][1], mem[j][0] + (i - j) * (i - j));
            }
            if (boj[i] == 'J' && boj[j] == 'O') {
                mem[i][2] = small(mem[i][2], mem[j][1] + (i - j) * (i - j));
            }
            if (boj[i] == 'B' && boj[j] == 'J') {
                mem[i][0] = small(mem[i][0], mem[j][2] + (i - j) * (i - j));
            }
        }
    }
    r = small(small(mem[n - 1][0], mem[n - 1][1]), mem[n - 1][2]);
    printf("%d", r >= INF ? -1 : r);
    return 0;
}