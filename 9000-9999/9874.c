#include <stdio.h>
#define INF 1023456789
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

int wh[16][2], nxt[16], pr[16], chk[16];
int cnt = 0;

void icycle(int n) {
    int chk2[16] = { 0, };
    for (int i = 0; i < n; i++) {
        chk2[i] = 1;
        for (int x = nxt[pr[i]]; x >= 0; x = nxt[pr[x]]) {
            chk2[x] = 1;
            if (x == i) {
                cnt++;
                return;
            }
        }
    }
}

void track(int n, int p, int x) {
    if (p * 2 == n) {
        icycle(n);
        return;
    }

    while (chk[x]) x++;
    for (int i = x + 1; i < n; i++) {
        if (chk[i]) continue;
        chk[i] = 1;
        pr[i] = x;
        pr[x] = i;
        track(n, p + 1, x + 1);
        chk[i] = 0;
    }
}

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("wormhole.in", "r");
        fo = fopen("wormhole.out", "w");
    }
    int n, t, p;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &wh[i][0], &wh[i][1]);
    }
    for (int i = 0; i < 16; i++) {
        t = INF;
        p = -1;
        for (int j = 0; j < 16; j++) {
            if (wh[i][1] == wh[j][1] && wh[j][0] > wh[i][0] && wh[j][0] < t) {
                t = wh[j][0];
                p = j;
            }
        }
        nxt[i] = p;
    }
    track(n, 0, 0);
    printf("%d", cnt);
    return 0;
}