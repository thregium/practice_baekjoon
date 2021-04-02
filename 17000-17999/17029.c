#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

char ani[128][128][32];
int k[128];

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("guess.in", "r");
        fo = fopen("guess.out", "w");
    }
    int n, ti, tj, d, r = 1;
    char buff[32];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s %d", buff, &k[i]);
        for (int j = 0; j < k[i]; j++) {
            scanf("%s", ani[i][j]);
        }
        qsort(ani[i], k[i], sizeof(char) * 32, strcmp);
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            ti = 0;
            tj = 0;
            d = 1;
            while (ti < k[i] || tj < k[j]) {
                if (ti >= k[i]) tj++;
                else if (tj >= k[j]) ti++;
                else {
                    if (!strcmp(ani[i][ti], ani[j][tj])) {
                        d++;
                        ti++;
                    }
                    else if (strcmp(ani[i][ti], ani[j][tj]) < 0) ti++;
                    else tj++;
                }
            }
            if (d > r) r = d;
        }
    }
    printf("%d", r);
    return 0;
}