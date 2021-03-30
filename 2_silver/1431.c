#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct cer {
    char s[64];
    int l;
    int n;
} cer;

cer a[1024];

int cmp1(const cer* a, const cer* b) {
    if (a->l > b->l) return 1;
    else if (a->l < b->l) return -1;
    if (a->n > b->n) return 1;
    if (a->n < b->n) return -1;
    return strcmp(a->s, b->s);
}

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", a[i].s);
        a[i].l = strlen(a[i].s);
        a[i].n = 0;
        for (int j = 0; j < a[i].l; j++) {
            if (isdigit(a[i].s[j])) a[i].n += a[i].s[j] - '0';
        }
    }
    qsort(a, n, sizeof(cer), cmp1);
    for (int i = 0; i < n; i++) {
        printf("%s\n", a[i].s);
    }
    return 0;
}