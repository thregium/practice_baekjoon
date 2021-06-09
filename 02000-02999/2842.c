#include <stdio.h>
#include <stdlib.h>

/*
문제 : N * N(N <= 50) 크기의 격자에서 상하좌우대각선으로 이동해가며 K와 P가 쓰인 모든 곳을 한 영역으로 만들려고 한다.
각 지역의 높이가 주어지면(0 < 높이 <= 10^6) 영역의 높이가 가장 높은 곳과 낮은 곳의 차이가 가장 적을 때의 높이 차를 구한다.

해결 방법 : 먼저, 높이의 범위가 지나치게 크기 때문에 좌표 압축을 통해 높이의 범위를 줄인다. (높이 <= 2500)으로 줄어든다.
그 다음으로는 투 포인터 알고리즘을 통해 높이를 1부터 차례로 올리며 해당 높이에서 최대 높이가 몇이 되어야
모든 K와 P가 한 영역이 되는지를 확인한다. 만약 해당 범위에서 한 영역으로 만드는 것이 가능하다면
최소 높이를 1 올리고 불가능하다면 최대 높이를 1 올린다. 이미 최대 높이라면 탐색을 종료한다.
탐색을 종료한 다음 가장 범위가 좁았을 때의 두 값의 차이를 구하면 된다.

주요 알고리즘 : 그래프 이론, 플러드필, 투포인터, 좌표압축

출처 : COCI 10/11#7 4번
*/

char vil[64][64], vis[64][64];
int ht[64][64], cps[4096][4], ci[4096], ks[4096][2];
int dxy[8][2] = { {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1} };
int n, kp = 0, cp = 0;

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int isvalid(int x, int y, int l, int h) {
    if (x < 0 || y < 0 || x >= n || y >= n) return 0;
    if (vis[x][y] || ht[x][y] < l || ht[x][y] > h) return 0;
    return 1;
}

void dfs(int x, int y, int l, int h) {
    vis[x][y] = 1;
    for (int i = 0; i < 8; i++) {
        if (!isvalid(x + dxy[i][0], y + dxy[i][1], l, h)) continue;
        dfs(x + dxy[i][0], y + dxy[i][1], l, h);
    }
}

int possible(int sx, int sy, int l, int h) {
    if (ht[sx][sy] < l || ht[sx][sy] > h) return 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) vis[i][j] = 0;
    }
    dfs(sx, sy, l, h);
    for (int i = 0; i < kp; i++) {
        if (!vis[ks[i][0]][ks[i][1]]) return 0;
    }
    return 1;
}

int main(void) {
    int sx = 0, sy = 0, hh, l = 1, h = 1, best = 1234567;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", vil[i]);
        for (int j = 0; j < n; j++) {
            if (vil[i][j] == 'K') {
                ks[kp][0] = i;
                ks[kp++][1] = j;
            }
            else if (vil[i][j] == 'P') {
                sx = i;
                sy = j;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &ht[i][j]);
            cps[cp][0] = ht[i][j];
            cps[cp][1] = ht[i][j];
            cps[cp][2] = i;
            cps[cp++][3] = j;
        }
    }
    qsort(cps, cp, sizeof(int) * 4, cmp1);
    cps[0][0] = 1;
    for (int i = 1; i < cp; i++) {
        if (cps[i][1] == cps[i - 1][1]) cps[i][0] = cps[i - 1][0];
        else cps[i][0] = cps[i - 1][0] + 1;
    }
    hh = cps[cp - 1][0];
    for (int i = 0; i < cp; i++) {
        ht[cps[i][2]][cps[i][3]] = cps[i][0];
        ci[cps[i][0]] = cps[i][1];
    }
    while (1) {
        if (possible(sx, sy, l, h)) {
            if (ci[h] - ci[l] < best) best = ci[h] - ci[l];
            l++;
        }
        else {
            if (h >= hh) break;
            h++;
        }
    }
    printf("%d", best);
    return 0;
}