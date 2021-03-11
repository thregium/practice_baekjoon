#include <stdio.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

char gen[1024][64];
int sp[64], pl[64];

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("cownomics.in", "r");
        fo = fopen("cownomics.out", "w");
    }
    int n, m, x, t, r = 0;
    int tr[3] = { 0, };
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s", gen[i]);
    }
    for (int i = n; i < n * 2; i++) {
        scanf("%s", gen[i]);
    }
    for (int i = 0; i < n * 2; i++) {
        for (int j = 0; j < m; j++) {
            if (gen[i][j] == 'A') gen[i][j] = 0;
            if (gen[i][j] == 'C') gen[i][j] = 1;
            if (gen[i][j] == 'G') gen[i][j] = 2;
            if (gen[i][j] == 'T') gen[i][j] = 3;
        }
    }
    for (tr[0] = 0; tr[0] < m; tr[0]++) {
        for (tr[1] = tr[0] + 1; tr[1] < m; tr[1]++) {
            for (tr[2] = tr[1] + 1; tr[2] < m; tr[2]++) {
                for (int i = 0; i < n; i++) {
                    x = 0;
                    for (int j = 0; j < 3; j++) {
                        x *= 4;
                        x += gen[i][tr[j]];
                    }
                    sp[x]++;
                }
                for (int i = n; i < n * 2; i++) {
                    x = 0;
                    for (int j = 0; j < 3; j++) {
                        x *= 4;
                        x += gen[i][tr[j]];
                    }
                    pl[x]++;
                }

                t = 1;
                for (int i = 0; i < 64; i++) {
                    if (sp[i] && pl[i]) t = 0;
                    sp[i] = 0;
                    pl[i] = 0;
                }
                r += t;
            }
        }
    }
    printf("%d", r);
    return 0;
}