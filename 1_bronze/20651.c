#include <stdio.h>

int p[128];

int main(void) {
    int n, s, f, w = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &p[i]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            s = 0;
            for (int k = i; k <= j; k++) s += p[k];
            if (s % (j - i + 1)) continue;
            s /= (j - i + 1);
            f = 0;
            for (int k = i; k <= j; k++) {
                if (p[k] == s) f = 1;
            }
            w += f;
        }
    }
    printf("%d", w);
    return 0;
}