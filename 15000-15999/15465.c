#include <stdio.h>
#include <string.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

int cng[128][3], best[128];

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("measurement.in", "r");
        fo = fopen("measurement.out", "w");
    }
    int n, d, c, r = 0;
    int milk[3] = { 7, 7, 7 };
    char buff[16] = { 0, };
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %s %d", &d, buff, &c);
        if (!strcmp(buff, "Bessie")) {
            cng[d][0] += c;
        }
        else if (!strcmp(buff, "Elsie")) {
            cng[d][1] += c;
        }
        else if (!strcmp(buff, "Mildred")) {
            cng[d][2] += c;
        }
    }
    for (int i = 0; i <= 100; i++) {
        for (int j = 0; j < 3; j++) {
            milk[j] += cng[i][j];
        }
        if (milk[0] > milk[1] && milk[0] > milk[2]) best[i] = 1;
        else if (milk[1] > milk[0] && milk[1] > milk[2]) best[i] = 2;
        else if (milk[0] == milk[1] && milk[0] > milk[2]) best[i] = 3;
        else if (milk[2] > milk[1] && milk[2] > milk[0]) best[i] = 4;
        else if (milk[0] == milk[2] && milk[0] > milk[1]) best[i] = 5;
        else if (milk[1] == milk[2] && milk[1] > milk[0]) best[i] = 6;
        else if (milk[0] == milk[1] && milk[0] == milk[2]) best[i] = 7;

        if (i > 0) {
            if (best[i] != best[i - 1]) r++;
        }
    }
    printf("%d", r);
    return 0;
}