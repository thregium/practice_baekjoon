#include <stdio.h>
#include <stdlib.h>

int x[1048576][2], xp[1048576];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, c = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x[i][0]);
        x[i][1] = i;
    }
    qsort(x, n, sizeof(int) * 2, cmp1);
    for (int i = 0; i < n; i++) {
        if (i > 0 && x[i][0] > x[i - 1][0]) {
            c++;
        }
        xp[x[i][1]] = c;
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", xp[i]);
    }
    return 0;
}