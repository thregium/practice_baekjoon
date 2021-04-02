#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char dm[524288][24], d[524288][24];
int ds = 0;

int cmp1(const void* a, const void* b) {
    char* s1 = (char*)a;
    char* s2 = (char*)b;
    return strcmp(a, b);
}

int main(void) {
    int n, m;
    char bm[24];
    void* t;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s", dm[i]);
    }
    qsort(dm, n, sizeof(char) * 24, cmp1);
    for (int i = 0; i < m; i++) {
        scanf("%s", bm);
        t = bsearch(bm, dm, n, sizeof(char) * 24, cmp1);
        if (t) {
            strcpy(d[ds++], t);
        }
    }
    qsort(d, ds, sizeof(char) * 24, cmp1);
    printf("%d\n", ds);
    for (int i = 0; i < ds; i++) {
        printf("%s\n", d[i]);
    }
    return 0;
}