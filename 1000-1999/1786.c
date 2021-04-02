#include <stdio.h>
#include <string.h>

char t[1048576], p[1048576];
int k[1048576], s[1048576];
int si = 0;

int main(void) {
    int f = 0;
    fgets(t, 1024000, stdin);
    fgets(p, 1024000, stdin);
    int n = strlen(t) - 1;
    int m = strlen(p) - 1;
    for (int i = 1; i < m; i++) {
        while (f > 0 && p[i] != p[f]) f = k[f - 1];
        if (p[f] == p[i]) k[i] = ++f;
    }
    f = 0;
    for (int i = 0; i < n; i++) {
        
        while (f > 0 && t[i] != p[f]) f = k[f - 1];

        if (t[i] == p[f]) {
            if (f == m - 1) {
                s[si++] = i - m + 2;
                f = k[f];
            }
            else f++;
        }
    }
    printf("%d\n", si);
    for (int i = 0; i < si; i++) {
        printf("%d ", s[i]);
    }
    return 0;
}