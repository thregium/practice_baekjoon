#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)
FILE* fi;
FILE* fo;

char* names[8] = { "Beatrice", "Belinda", "Bella", "Bessie", "Betsy", "Blue", "Buttercup", "Sue" };
char rules[8][2], sel[8], chk[8], buff[2][16];

void track(int n, int x, int r) {
    if (x == r) {
        for (int i = 0; i < 8; i++) {
            printf("%s\n", names[sel[i]]);
        }
        exit(0);
    }
    int t;
    for (int i = 0; i < 8; i++) {
        if (chk[i]) continue;
        t = 1;
        for (int j = 0; j < n; j++) {
            if (r == 0) break;
            if ((rules[j][0] == i && chk[rules[j][1]] && rules[j][1] != sel[r - 1]) || (rules[j][1] == i && chk[rules[j][0]] && rules[j][0] != sel[r - 1])) {
                t = 0;
                break;
            }
        }
        if (!t) continue;
        sel[r] = i;
        chk[i] = 1;
        track(n, x, r + 1);
        chk[i] = 0;
    }
}

int main(void) {
    fi = stdin;
    fo = stdout;
    if (FOUT) {
        fi = fopen("lineup.in", "r");
        fo = fopen("lineup.out", "w");
    }
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s must be milked beside %s", buff[0], buff[1]);
        for (int j = 0; j < 8; j++) {
            if (!strcmp(buff[0], names[j])) rules[i][0] = j;
            if (!strcmp(buff[1], names[j])) rules[i][1] = j;
        }
    }

    track(n, 8, 0);
    return 0;
}