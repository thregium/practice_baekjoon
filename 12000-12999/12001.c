#include <stdio.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

int cows[128][2], h[1048576], v[1048576];

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("balancing.in", "r");
        fo = fopen("balancing.out", "w");
    }
    int n, b, m, r = 12345;
    int ct[4] = { 0, };
    scanf("%d %d", &n, &b);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &cows[i][0], &cows[i][1]);
        h[cows[i][0]]++;
        v[cows[i][1]]++;
    }
    for (int i = 2; i < b; i += 2) {
        if (h[i - 1]) {
            for (int j = 2; j < b; j += 2) {
                if (v[j - 1]) {
                    for (int k = 0; k < n; k++) {
                        if (cows[k][0] > i && cows[k][1] > j) ct[0]++;
                        if (cows[k][0] > i && cows[k][1] < j) ct[1]++;
                        if (cows[k][0] < i && cows[k][1] > j) ct[2]++;
                        if (cows[k][0] < i && cows[k][1] < j) ct[3]++;
                    }
                    m = 0;
                    for (int k = 0; k < 4; k++) {
                        if (ct[k] > m) m = ct[k];
                        ct[k] = 0;
                    }
                    if (m < r) r = m;
                }
            }
        }
    }
    printf("%d", r);
    return 0;
}