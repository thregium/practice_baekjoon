#include <stdio.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

int r[1024];

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("cbarn.in", "r");
        fo = fopen("cbarn.out", "w");
    }
    int n, s, x = 1234567890;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &r[i]);
    }
    for (int i = 0; i < n; i++) {
        s = 0;
        for (int j = 0; j < n; j++) {
            s += r[(i + j) % n] * j;
        }
        if (s < x) x = s;
    }
    printf("%d", x);
    return 0;
}