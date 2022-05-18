#include <stdio.h>
#define INF 1012345678

int x[1048576], lsum[1048576], rsum[1048576];

int main(void) {
    int n, r = INF;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &x[i]);
        if (x[i] == 1) rsum[i] = 1;
        else lsum[i] = 1;
        lsum[i] += lsum[i - 1];
    }
    for (int i = n; i >= 0; i--) rsum[i] += rsum[i + 1];
    for (int i = 0; i <= n; i++) {
        if (lsum[i] + rsum[i + 1] < r) r = lsum[i] + rsum[i + 1];
    }
    printf("%d", r);
    return 0;
}