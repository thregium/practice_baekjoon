#include <stdio.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

int fb[16], sb[16], fri[2048], t[16];
int fg = 1000, sg = 1000;

void track(int d) {
    if (d == 4) {
        fri[fg]++;
        return;
    }

    int x;
    if (d & 1) {
        for (int i = 0; i < 11; i++) {
            x = sb[i];
            fb[9] = x;
            sg -= x;
            fg += x;
            for (int j = i + 1; j < 11; j++) {
                sb[j - 1] = sb[j];
            }
            sb[10] = 0;
            track(d + 1);
            sg += x;
            fg -= x;
            for (int j = 10; j > i; j--) {
                sb[j] = sb[j - 1];
            }
            sb[i] = x;
        }
    }
    else {
        for (int i = 0; i < 10; i++) {
            x = fb[i];
            sb[10] = x;
            fg -= x;
            sg += x;
            for (int j = i + 1; j < 10; j++) {
                fb[j - 1] = fb[j];
            }
            fb[9] = 0;
            track(d + 1);
            fg += x;
            sg -= x;
            for (int j = 9; j > i; j--) {
                fb[j] = fb[j - 1];
            }
            fb[i] = x;
        }
    }
}

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("backforth.in", "r");
        fo = fopen("backforth.out", "w");
    }
    for (int i = 0; i < 10; i++) {
        scanf("%d", &fb[i]);
    }
    for (int i = 0; i < 10; i++) {
        scanf("%d", &sb[i]);
    }
    track(0);
    int r = 0;
    for (int i = 0; i <= 2000; i++) {
        r += !!fri[i];
    }
    printf("%d", r);
    return 0;
}