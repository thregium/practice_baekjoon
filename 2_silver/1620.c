#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct po {
    int n;
    char p[24];
} po;

char p[102400][24];
po ps[102400];

int cmp1(const void* a, const void* b) {
    po* s1 = (po*)a;
    po* s2 = (po*)b;
    return strcmp(s1->p, s2->p);
}

int main(void) {
    int n, m, x;
    char bm[24];
    void* t;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s", p[i]);
        strcpy(ps[i].p, p[i]);
        ps[i].n = i + 1;
    }
    qsort(ps, n, sizeof(po), cmp1);
    po pt;
    for (int i = 0; i < m; i++) {
        scanf("%s", bm);
        if (isalpha(bm[0])) {
            strcpy(pt.p, bm);
            t = bsearch(&pt, ps, n, sizeof(po), cmp1);
            printf("%d\n", ((po*)t)->n);
        }
        if (isdigit(bm[0])) {
            x = 0;
            for (int j = 0; j < strlen(bm); j++) {
                x *= 10;
                x += bm[j] - '0';
            }
            if (x > 0) printf("%s\n", p[x - 1]);
        }
    }
    return 0;
}