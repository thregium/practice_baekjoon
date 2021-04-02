#include <stdio.h>
#define IN stdin
#define OUT stdout

int big(int a, int b) {
    return a > b ? a : b;
}

int small(int a, int b) {
    return a < b ? a : b;
}

int main(void) {
    int a, b, c, d, e, f, g, h, r;
    FILE* fi = fopen("square.in", "r");
    FILE* fo = fopen("square.out", "w");
    fscanf(IN, "%d %d %d %d", &a, &b, &c, &d);
    fscanf(IN, "%d %d %d %d", &e, &f, &g, &h);
    r = big(big(c, g) - small(a, e), big(d, h) - small(b, f));
    fprintf(OUT, "%d", r * r);
    return 0;
}