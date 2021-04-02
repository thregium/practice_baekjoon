#include <stdio.h>

int sel[16][3];
char s[32];
int ns, best = -2147483648;

int compute(int n) {
    int m = 0, o = 1;
    for (int i = sel[n][0] * 2; i <= sel[n][1] * 2; i++) {
        if (i & 1) {
            if (s[i] == '+') o = 1;
            else if (s[i] == '-') o = 2;
            else if (s[i] == '*') o = 3;
        }
        else {
            if (o == 1) m += s[i] - '0';
            else if (o == 2) m -= s[i] - '0';
            else if (o == 3) m *= s[i] - '0';
        }
    }
    return m;
}

void track(int n, int l) {
    int m, o;
    if (l == ns - 1) {
        m = sel[0][2]; o = 1;
        for (int i = 1; i < n; i++) {
            if (s[sel[i][0] * 2 - 1] == '+') m += sel[i][2];
            else if (s[sel[i][0] * 2 - 1] == '-') m -= sel[i][2];
            else if (s[sel[i][0] * 2 - 1] == '*') m *= sel[i][2];
        }
        if (m > best) best = m;
        return;
    }

    sel[n][0] = l + 1;
    for (int j = l + 1; j <= l + 2; j++) {
        if (j >= ns) break;
        sel[n][1] = j;
        sel[n][2] = compute(n);
        track(n + 1, j);
    }
}

int main(void) {
    int n;
    scanf("%d", &n);
    scanf("%s", s);
    ns = ((n + 1) >> 1);
    track(0, -1);
    printf("%d", best);
    return 0;
}