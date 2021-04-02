#include <stdio.h>
#define FOUT 1
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

int fd[2048][2048];

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("mowing.in", "r");
        fo = fopen("mowing.out", "w");
    }
    int n, s, t = 1, x = 1024, y = 1024, m = 1234567890;
    char d;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("\n%c %d", &d, &s);
        for (int j = 0; j < s; j++) {
            if (fd[x][y]) {
                if (t - fd[x][y] < m) m = t - fd[x][y];
            }
            fd[x][y] = t;
            if (d == 'N') x--;
            else if (d == 'E') y++;
            else if (d == 'S') x++;
            else if (d == 'W') y--;
            t++;
        }
    }
    if (fd[x][y]) {
        if (t - fd[x][y] < m) m = t - fd[x][y];
    }
    printf("%d", m > 123456789 ? -1 : m);
    return 0;
}