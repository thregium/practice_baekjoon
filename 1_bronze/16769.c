#include <stdio.h>
#define IN stdin
#define OUT stdout

int c[3], m[3];

int small(int a, int b) {
    return a < b ? a : b;
}

int main(void) {
    int p;
    //FILE* fi = fopen("mixmilk.in", "r");
    //FILE* fo = fopen("mixmilk.out", "w");
    fscanf(IN, "%d %d%d %d%d %d", &c[0], &m[0], &c[1], &m[1], &c[2], &m[2]);
    for (int i = 0; i < 100; i++) {
        if (i % 3 == 0) {
            p = small(m[0], c[1] - m[1]);
            m[0] -= p;
            m[1] += p;
        }
        else if (i % 3 == 1) {
            p = small(m[1], c[2] - m[2]);
            m[1] -= p;
            m[2] += p;
        }
        else {
            p = small(m[2], c[0] - m[0]);
            m[2] -= p;
            m[0] += p;
        }
    }
    fprintf(OUT, "%d\n%d\n%d", m[0], m[1], m[2]);
    return 0;
}