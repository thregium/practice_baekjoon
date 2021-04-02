#include <stdio.h>
#include <string.h>
#define DIV 204797

char fre[204800][32], b1[32], b2[32];
int g[204800], fn[204800];

int hash(char* x) {
    int r = 0;
    for (int i = 0; x[i]; i++) {
        r *= 127;
        r += x[i];
        r %= DIV;
    }
    while (strcmp(fre[r], x)) {
        if (fre[r][0] == '\0') {
            strcpy(fre[r], x);
            return r;
        }
        r = (r + 1) % DIV;
    }
    return r;
}

int find(int a) {
    if (g[a] < 0) return a;
    else return g[a] = find(g[a]);
}

void merge(int a, int b) {
    if (find(a) != find(b)) {
        fn[find(b)] += fn[find(a)];
        g[find(a)] = find(b);
    }
    else return;
}

int main(void) {
    int t, f, h1, h2;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        for (int i = 0; i < DIV; i++) {
            fn[i] = 1;
            g[i] = -1;
        }
        scanf("%d", &f);
        for (int i = 0; i < f; i++) {
            scanf("%s %s", b1, b2);
            h1 = hash(b1);
            h2 = hash(b2);
            if (find(h1) == find(h2)) {
                printf("%d\n", fn[find(h1)]);
            }
            else {
                merge(h1, h2);
                printf("%d\n", fn[find(h1)]);
            }
        }
    }
    return 0;
}