#include <stdio.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
문제 : 가위바위보를 N(N <= 100)회 시행한 기록이 주어진다. 두 명이 각각 낸 것이 1, 2, 3으로 표시되고, 이는 가위, 바위, 보
중 하나라고 할 때, 첫 번째 사람이 가장 많이 이기도록 배정하였을 때의 이긴 횟수를 구한다.

해결 방법 : 가위, 바위, 보를 배정하는 모든 경우를 시도해보며 첫 번째 사람이 가장 많이 이긴 것을 찾으면 된다.

주요 알고리즘 : 브루트 포스

출처 : USACO 2017J B2번
*/

int hps[128][2];

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("hps.in", "r");
        fo = fopen("hps.out", "w");
    }
    int n, r = 0, x, h, p, s;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &hps[i][0], &hps[i][1]);
    }
    for (h = 1; h <= 3; h++) {
        for (p = 1; p <= 3; p++) {
            if (h == p) continue;
            for (s = 1; s <= 3; s++) {
                if (s != h && s != p) break;
            }
            x = 0;
            for (int k = 0; k < n; k++) {
                if ((hps[k][0] == p && hps[k][1] == h) || (hps[k][0] == s && hps[k][1] == p) || (hps[k][0] == h && hps[k][1] == s)) x++;
            }
            if (x > r) r = x;
        }
    }
    printf("%d", r);
    return 0;
}