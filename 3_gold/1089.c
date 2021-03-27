#include <stdio.h>

int nums[10] = { 31599, 4681, 29671, 29647, 23497, 31183, 31215, 29257, 31727, 31695 };
char b[5][64];

int main(void) {
    int n, t, s, c;
    long long d = 1;
    double r = 0;
    scanf("%d", &n);
    for (int i = 0; i < 5; i++) {
        scanf("%s", b[i]);
    }
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < 5; j++) {
            if (b[j][i * 4 + 3] == '#') r = -1;
        }
        t = 0;
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 3; k++) {
                if (b[j][i * 4 + k] == '#') {
                    t += (1 << ((4 - j) * 3 + (2 - k)));
                    if ((j == 1 && k == 1) || (j == 3 && k == 1)) r = -1;
                }
            }
        }
        if (r < 0) break;
        s = 0;
        c = 0;
        for (int j = 0; j < 10; j++) {
            if ((t | nums[j]) == nums[j]) {
                s += j;
                c++;
            }
        }
        r += (double)s / c * d;
        d *= 10;
    }
    if (r < 0) printf("-1");
    else printf("%.10f", r);
    return 0;
}