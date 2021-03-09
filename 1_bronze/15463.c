#include <stdio.h>

int bb[2048][2048];

int main(void) {
    int a, b, c, d, r = 0;
    //FILE* fi = fopen("billboard.in", "r");
    //FILE* fo = fopen("billboard.out", "w");
    fscanf(stdin, "%d %d %d %d", &a, &b, &c, &d);
    for (int i = a; i < c; i++) {
        for (int j = b; j < d; j++) {
            bb[i + 1000][j + 1000] = 1;
        }
    }
    fscanf(stdin, "%d %d %d %d", &a, &b, &c, &d);
    for (int i = a; i < c; i++) {
        for (int j = b; j < d; j++) {
            bb[i + 1000][j + 1000] = 1;
        }
    }
    fscanf(stdin, "%d %d %d %d", &a, &b, &c, &d);
    for (int i = a; i < c; i++) {
        for (int j = b; j < d; j++) {
            bb[i + 1000][j + 1000] = 0;
        }
    }
    for (int i = 0; i <= 2000; i++) {
        for (int j = 0; j <= 2000; j++) {
            r += bb[i][j];
        }
    }
    fprintf(stdout, "%d", r);
    return 0;
}