#include <stdio.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

int a[128], id[128][4];

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("shuffle.in", "r");
        fo = fopen("shuffle.out", "w");
    }
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &id[i]);
    }
    for (int i = 1; i <= 3; i++) {
        for (int j = 0; j < n; j++) {
            id[j][i] = id[a[j] - 1][i - 1];
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%d\n", id[i][3]);
    }
    return 0;
}