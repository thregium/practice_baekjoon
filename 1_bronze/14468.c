#include <stdio.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

char cross[64];

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("circlecross.in", "r");
        fo = fopen("circlecross.out", "w");
    }
    int ic, jc, f, r = 0;
    scanf("%s", cross);
    for (int i = 0; i < 26; i++) {
        for (int j = i + 1; j < 26; j++) {
            ic = 0;
            jc = 0;
            f = 0;
            for (int k = 0; k < 52; k++) {
                if (cross[k] - 'A' == i) {
                    if (ic == 1 && jc == 1 && f < 0) r++;
                    if (ic == 0 && jc == 0) f = -1;
                    ic++;
                }
                if (cross[k] - 'A' == j) {
                    if (ic == 1 && jc == 1 && f > 0) r++;
                    if (ic == 0 && jc == 0) f = 1;
                    jc++;
                }
            }
        }
    }
    printf("%d", r);
    return 0;
}