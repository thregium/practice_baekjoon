#include <stdio.h>
#define INF 1234567890

int opers[1048576];

int small(int a, int b) {
    return a < b ? a : b;
}

int main(void) {
    int n;
    scanf("%d", &n);
    opers[1] = 0;
    for (int i = 2; i <= n; i++) {
        opers[i] = INF;
        if (i % 3 == 0) opers[i] = small(opers[i], opers[i / 3] + 1);
        if (i % 2 == 0) opers[i] = small(opers[i], opers[i / 2] + 1);
        opers[i] = small(opers[i], opers[i - 1] + 1);
    }

    printf("%d\n%d ", opers[n], n);
    while (opers[n]) {
        if (n % 3 == 0 && opers[n / 3] < opers[n]) {
            printf("%d ", n / 3);
            n /= 3;
            continue;
        }
        if (n % 2 == 0 && opers[n / 2] < opers[n]) {
            printf("%d ", n / 2);
            n /= 2;
            continue;
        }
        printf("%d ", n - 1);
        n--;
        continue;
    }
    return 0;
}