#include <stdio.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("lostcow.in", "r");
        fo = fopen("lostcow.out", "w");
    }
    int x, y, t = 0;
    scanf("%d %d", &x, &y);
    for (int i = 0; ; i++) {
        if (i == 0) {
            if (x == y) break;
            x++;
            t++;
            continue;
        }
        for (int j = 0; j < (1 << (i - 1)) * 3; j++) {
            if (x == y) break;
            if (i % 2) x--;
            else x++;
            t++;
        }
        if (x == y) break;
    }
    printf("%d", t);
    return 0;
}