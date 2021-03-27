#include <stdio.h>

int a[128], r = 0;

void track(int n, int x) {
    if (n == x) {
        r = 1;
        return;
    }
    if (r) return;
    int t, s;
    for (int i = 1; i <= 3; i++) {
        a[x] = i;
        s = 1;
        for (int j = 1; j <= ((x + 1) >> 1); j++) {
            t = 1;
            for (int k = 0; k < j; k++) {
                if (a[x - k] != a[x - j - k]) t = 0;
            }
            if (t) s = 0;
        }
        if (!s) continue;
        track(n, x + 1);
        if (r) return;
    }
}

int main(void) {
    int n;
    scanf("%d", &n);
    track(n, 0);
    for (int i = 0; i < n; i++) {
        printf("%d", a[i]);
    }
    return 0;
}