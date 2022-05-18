#include <stdio.h>

int a[20480];

int main(void) {
    int n, k, nz;
    while(1) {
        scanf("%d %d", &n, &k);
        if (n < 0) break;
        for (int i = n; i >= 0; i--) {
            scanf("%d", &a[i]);
        }
        for (int i = 0; i <= n - k; i++) {
            a[i + k] -= a[i];
            a[i] = 0;
        }
        nz = n + 1;
        for (int i = 0; i <= n; i++) {
            if (a[i]) {
                nz = i;
                break;
            }
        }
        for (int i = n; i >= nz; i--) printf("%d ", a[i]);
        if (nz > n) printf("0\n");
        else printf("\n");
    }
    return 0;
}