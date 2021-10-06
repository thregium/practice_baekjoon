#include <stdio.h>
#define FOUT 0
#define INF 1012345678
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
문제 : 12명을 4개의 팀으로 나누려고 한다. 네 팀의 능력치 합을 가장 균등하게(가장 능력치 합이 높은 팀과 가장 낮은 팀 사이
차이가 가장 적도록) 나눌 때, 가장 능력치 합이 높은 팀과 낮은 팀의 차이의 최솟값을 구한다.

해결 방법 : 가능한 모든 경우에 대해 팀을 나누어 보고, 각각의 능력치 합의 차이 가운데 가장 작은 것을 고르면 된다.

주요 알고리즘 : 브루트 포스, 백트래킹

출처 : USACO 2014J B3번
*/

int skill[16], chk[16], team[4];
int res = INF;

void track(int x, int y) {
    if (x == y) {
        int l = INF, h = 0;
        for (int i = 0; i < x; i++) {
            if (team[i] < l) l = team[i];
            if (team[i] > h) h = team[i];
        }
        if (h - l < res) res = h - l;
        return;
    }

    for (int i = 0; i < 12; i++) {
        if (chk[i]) continue;
        chk[i] = 1;
        for (int j = i + 1; j < 12; j++) {
            if (chk[j]) continue;
            chk[j] = 1;
            for (int k = j + 1; k < 12; k++) {
                if (chk[k]) continue;
                chk[k] = 1;
                team[y] = skill[i] + skill[j] + skill[k];
                track(x, y + 1);
                chk[k] = 0;
            }
            chk[j] = 0;
        }
        chk[i] = 0;
    }
}

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("bteams.in", "r");
        fo = fopen("bteams.out", "w");
    }
    for (int i = 0; i < 12; i++) {
        scanf("%d", &skill[i]);
    }
    track(4, 0);
    printf("%d", res);
    return 0;
}