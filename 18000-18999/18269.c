#include <stdio.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

char s[128];

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("whereami.in", "r");
        fo = fopen("whereami.out", "w");
    }
    int n, x, y, r = 1;
    scanf("%d", &n);
    scanf("%s", s);
    for (int i = 0; i < n; i++) {
        x = 0;
        for (int j = 0; j < n - i; j++) {
            for (int k = j + 1; k < n - i; k++) {
                y = 1;
                for (int l = 0; l <= i; l++) {
                    if (s[j + l] != s[k + l]) y = 0;
                }
                if (y) x = 1;
            }
        }
        r += x;
    }
    printf("%d", r);
    return 0;
}