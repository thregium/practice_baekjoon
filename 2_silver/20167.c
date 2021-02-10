#include <stdio.h>

int rate[24];

int big(int a, int b) {
    return a > b ? a : b;
}

int track(int n, int k, int p) {
    int s = 0, r = 0, t = 0;
    while (s < k && p < n) {
        s += rate[p++];
    }
    if (s > k) r += s - k;
    for (int i = p; i < n; i++) {
        t = big(t, track(n, k, i));
    }
    return r + t;
}

int main(void) {
    int n, k, e = 0;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &rate[i]);
    }
    for (int i = 0; i < n; i++) {
        e = big(e, track(n, k, i));
    }
    printf("%d", e);
    return 0;
}