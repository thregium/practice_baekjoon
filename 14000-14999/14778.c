#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int milk[25600][2], milk2[25600][2], seq[16], vis[16], bseq[16];
int best = 1012345678, bcnt = 1;

int big(int a, int b) {
    return a > b ? a : b;
}

int small(int a, int b) {
    return a < b ? a : b;
}

int cmp1(const void* a, const void* b) {
    int ax = *(int*)a;
    int ay = *((int*)a + 1);
    int bx = *(int*)b;
    int by = *((int*)b + 1);
    return small(ax, by) - small(ay, bx);
}

void track(int n, int x) {
    if (n == x) {
        int r1 = 0, r2 = 0;
        for (int i = 0; i < n; i++) {
            r1 += milk[seq[i]][0];
            r2 = big(r1, r2) + milk[seq[i]][1];
        }
        if (r2 < best) {
            best = r2;
            for (int i = 0; i < n; i++) bseq[i] = seq[i];
            bcnt = 1;
        }
        else if (r2 == best) bcnt++;
        return;
    }
    for (int i = 0; i < n; i++) {
        if (vis[i]) continue;
        vis[i] = 1;
        seq[x] = i;
        track(n, x + 1);
        vis[i] = 0;
    }
}

int main(void) {
    int n, d, r1 = 0, r2 = 0;
    //freopen("E:\\PS\\Olympiad\\USA\\3_Gold\\2006_04\\usopen06\\testdata\\allopen06\\mqueue.1.in", "r", stdin);
    //srand(time(NULL));
    scanf("%d %d", &n, &d);
    while (1) {
        //if (n == 6000) return 1;
        milk[0][0]++;
        r1 = 1;
        for (int i = 0; i < n; i++) {
            //scanf("%d %d", &milk[i][0], &milk[i][1]);
            if (milk[i][0] == 0) milk[i][0] = 1;
            if (milk[i][1] == 0) milk[i][1] = 1;
            if (milk[i][0] > d) {
                milk[i][0] = 1;
                milk[i][1]++;
            }
            if (milk[i][1] > d) {
                milk[i][1] = 1;
                milk[i + 1][0]++;
            }
            if (milk[i][0] != d || milk[i][1] != d) r1 = 0;
            //milk[i][0] = rand() % 10 + 1;
            //milk[i][1] = rand() % 10 + 1;
        }
        if (r1) break;

        best = 1012345678;
        track(n, 0);
        //printf("%d %d\n", best, bcnt);
        for (int i = 0; i < n; i++) {
            //printf("%d %d\n", milk[bseq[i]][0], milk[bseq[i]][1]);
        }

        for (int i = 0; i < n; i++) {
            milk2[i][0] = milk[i][0];
            milk2[i][1] = milk[i][1];
        }
        qsort(milk2, n, sizeof(int) * 2, cmp1);
        r1 = 0, r2 = 0;
        for (int i = 0; i < n; i++) {
            r1 += milk2[i][0];
            r2 = big(r1, r2) + milk2[i][1];
            if (r2 > 1000000000) return 1;
        }
        //printf("%d", r2);
        if (best != r2) {
            printf("ERROR!");
            return 0;
        }
    }
    printf("OK");
    return 0;
}