#include <stdio.h>
#define IN stdin
#define OUT stdout

int c[128][3], g[128];

int main(void) {
    int n, a, b, s, r = 0;
    //FILE* fi = fopen("shell.in", "r");
    //FILE* fo = fopen("shell.out", "w");
    fscanf(IN, "%d", &n);
    c[0][0] = 1;
    c[0][1] = 2;
    c[0][2] = 3;
    for (int i = 1; i <= n; i++) {
        fscanf(IN, "%d %d %d", &a, &b, &g[i]);
        if ((a == 1 && b == 2) || (a == 2 && b == 1)) {
            c[i][0] = c[i - 1][1];
            c[i][1] = c[i - 1][0];
            c[i][2] = c[i - 1][2];
        }
        else if ((a == 1 && b == 3) || (a == 3 && b == 1)) {
            c[i][0] = c[i - 1][2];
            c[i][1] = c[i - 1][1];
            c[i][2] = c[i - 1][0];
        }
        else {
            c[i][0] = c[i - 1][0];
            c[i][1] = c[i - 1][2];
            c[i][2] = c[i - 1][1];
        }
    }
    for (int i = 1; i <= 3; i++) {
        s = 0;
        for (int j = 1; j <= n; j++) {
            if (c[j][g[j] - 1] == i) s++;
        }
        if (s > r) r = s;
    }
    fprintf(OUT, "%d", r);
    return 0;
}