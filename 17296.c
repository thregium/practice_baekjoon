#include <stdio.h>

int main(void) {
    int n, r = 0, p = 0;
    double t;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lf", &t);
        t *= 2;
        if ((int)t % 2) {
            if (p == 0) {
                r += t / 2 + 1;
                p = 1;
            }
            else {
                r += t / 2;
            }
        }
        else {
            r += t / 2;
            p = 1;
        }
    }
    printf("%d", r);
    return 0;
}