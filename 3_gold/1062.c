#include <stdio.h>

int al[64][32], sel[32];
int best = 0;

void track(int n, int k, int p, int l) {
    if (k < p) return;
    int r, t;
    if (k == p) {
        r = 0;
        for (int i = 0; i < n; i++) {
            t = 1;
            for (int j = 0; j < 26; j++) {
                if (al[i][j] && !sel[j]) {
                    t = 0;
                    break;
                }
            }
            r += t;
        }
        if (r > best) best = r;
        return;
    }
    for (int i = l + 1; i < 26; i++) {
        if (sel[i]) continue;
        sel[i] = 1;
        track(n, k, p + 1, i);
        sel[i] = 0;
    }
}

int main(void) {
    int n, k;
    char b[32] = { 0, };
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%s", b);
        for (int j = 0; b[j]; j++) {
            al[i][b[j] - 'a'] = 1;
        }
    }
    sel[0] = 1;
    sel[2] = 1;
    sel[8] = 1;
    sel[13] = 1;
    sel[19] = 1;
    track(n, k - 5, 0, -1);
    printf("%d", best);
    return 0;
}