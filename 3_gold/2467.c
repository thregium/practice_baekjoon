#include <stdio.h>
#include <math.h>
#define INF 1024000000

int s[102400];

int main(void) {
    int n;
    int r[2] = { INF, INF };
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &s[i]);
    }
    int l = 1, h = n;
    while (h > l) {
        while (h > l && s[h] + s[l] >= 0) {
            if (abs(s[h] + s[l]) < abs(r[0] + r[1])) {
                r[0] = s[l];
                r[1] = s[h];
            }
            h--;
        }
        if (h > l && abs(s[h] + s[l]) < abs(r[0] + r[1])) {
            r[0] = s[l];
            r[1] = s[h];
        }
        l++;
    }
    printf("%d %d", r[0], r[1]);
    return 0;
}
