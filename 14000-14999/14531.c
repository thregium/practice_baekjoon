#include <stdio.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

char sp[128][128], pl[128][128];
int sc[4], pc[4];

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("cownomics.in", "r");
        fo = fopen("cownomics.out", "w");
    }
    int n, m, p, r = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s", sp[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%s", pl[i]);
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (sp[j][i] == 'A') sc[0]++;
            if (sp[j][i] == 'C') sc[1]++;
            if (sp[j][i] == 'G') sc[2]++;
            if (sp[j][i] == 'T') sc[3]++;
            if (pl[j][i] == 'A') pc[0]++;
            if (pl[j][i] == 'C') pc[1]++;
            if (pl[j][i] == 'G') pc[2]++;
            if (pl[j][i] == 'T') pc[3]++;
        }

        p = 1;
        for (int j = 0; j < 4; j++) {
            if (sc[j] && pc[j]) p = 0;
            sc[j] = 0;
            pc[j] = 0;
        }
        r += p;
    }
    printf("%d", r);
    return 0;
}