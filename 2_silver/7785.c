#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char p[1048576][8];

int main(void) {
    int n, l = 0;
    char b[8];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s %s", p[i], b);
    }
    qsort(p, n, sizeof(char) * 8, strcmp);
    for (int i = n - 1; i >= 0; i--) {
        if (strcmp(p[i], p[i + 1])) {
            if (l & 1) printf("%s\n", p[i + 1]);
            l = 1;
        }
        else l++;
    }
    if (l & 1) printf("%s\n", p[0]);
    return 0;
}