#include <stdio.h>
#include <stdlib.h>

int sharks[10240][5], ns[10240][5]; //행, 열, 속력, 방향, 크기
int sc = 0;

int cmp1(const void* a, const void* b) {
    int ax = *(int*)a;
    int bx = *(int*)b;
    int ay = *((int*)a + 1);
    int by = *((int*)b + 1);
    int as = *((int*)a + 4);
    int bs = *((int*)b + 4);
    if (ay != by) {
        if (ay > by) return 1;
        else return -1;
    }
    if (ax != bx) {
        if (ax > bx) return 1;
        else return -1;
    }
    return as < bs ? 1 : as == bs ? 0 : -1;
}

int main(void) {
    int r, c, m, p = 0, ct, ls, lp, res = 0; //r : 행, c : 열, m : 첫 상어 수, p : 임시 좌표, ct : 잡음, ls : 같은 마지막 물고기, lp : 현재 물고기 번호, res : 결과
    scanf("%d %d %d", &r, &c, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d %d %d", &sharks[i][0], &sharks[i][1], &sharks[i][2], &sharks[i][3], &sharks[i][4]);
    }
    sc = m;
    for (int t = 1; t <= c; t++) {
        qsort(sharks, sc, sizeof(int) * 5, cmp1);
        ct = 0;
        ls = -1;
        lp = 0;
        for (int i = 0; i < sc; i++) {
            if (sharks[i][1] == t && !ct) {
                ls = i;
                ct = i + 1;
                res += sharks[i][4];
                continue;
            }
            if (ls >= 0 && sharks[i][0] == sharks[ls][0] && sharks[i][1] == sharks[ls][1]) continue;
            else {
                ls = i;
                for (int j = 0; j < 5; j++) ns[lp][j] = sharks[i][j];
                lp++;
            }
        }
        for (int i = 0; i < sc; i++) {
            for (int j = 0; j < 5; j++) {
                sharks[i][j] = ns[i][j];
                ns[i][j] = 0;
            }
        }
        sc = lp;
        for (int i = 0; i < sc; i++) {
            if (sharks[i][3] <= 2) {
                if (sharks[i][3] == 1) p = r * 2 - sharks[i][0];
                if (sharks[i][3] == 2) p = sharks[i][0];
                p = (p + sharks[i][2] - 1) % (r * 2 - 2) + 1;
                if (p <= r) {
                    sharks[i][0] = p;
                    sharks[i][3] = 2;
                }
                else {
                    sharks[i][0] = r * 2 - p;
                    sharks[i][3] = 1;
                }
            }
            else {
                if (sharks[i][3] == 4) p = c * 2 - sharks[i][1];
                if (sharks[i][3] == 3) p = sharks[i][1];
                p = (p + sharks[i][2] - 1) % (c * 2 - 2) + 1;
                if (p <= c) {
                    sharks[i][1] = p;
                    sharks[i][3] = 3;
                }
                else {
                    sharks[i][1] = c * 2 - p;
                    sharks[i][3] = 4;
                }
            }
        }
    }
    printf("%d", res);
    return 0;
}