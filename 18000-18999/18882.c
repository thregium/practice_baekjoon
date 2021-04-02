#include <stdio.h>
#include <stdlib.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

char con[128];
int ina[256][3], cont[128], po[128];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("tracing.in", "r");
        fo = fopen("tracing.out", "w");
    }
    int n, t, tx, tm, x, y;
    int pz = 0, kl = 256, kh = 0;
    scanf("%d %d", &n, &t);
    scanf("%s", con);
    for (int i = 0; i < t; i++) {
        scanf("%d %d %d", &tm, &x, &y);
        ina[i][0] = tm;
        ina[i][1] = x - 1;
        ina[i][2] = y - 1;
    }
    qsort(ina, t, sizeof(int) * 3, cmp1);
    for (int i = 0; i < n; i++) {
        if (con[i] == '0') continue;
        for (int k = 0; k <= t; k++) {
            for (int ii = 0; ii < n; ii++) {
                cont[ii] = -1;
            }
            cont[i] = 0;
            for (int j = 0; j < t; j++) {
                if (cont[ina[j][1]] >= 0) {
                    cont[ina[j][1]]++;
                    if (cont[ina[j][1]] <= k && cont[ina[j][2]] < 0) {
                        cont[ina[j][2]] = 0;
                        continue;
                    }
                }
                if (cont[ina[j][2]] >= 0) {
                    cont[ina[j][2]]++;
                    if (cont[ina[j][2]] <= k && cont[ina[j][1]] < 0) {
                        cont[ina[j][1]] = 0;
                        continue;
                    }
                }
            }
            tx = 1;
            for (int j = 0; j < n; j++) {
                if ((con[j] == '0' && cont[j] >= 0) || (con[j] == '1' && cont[j] < 0)) {
                    tx = 0;
                    break;
                }
            }
            if (tx) {
                po[i] = 1;
                if (k < kl) kl = k;
                if (k > kh) {
                    kh = k;
                    if (k == t) kh = 999;
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        pz += po[i];
    }
    printf("%d %d ", pz, kl);
    if (kh == 999) printf("%s", "Infinity");
    else printf("%d", kh);
    return 0;
}