#include <stdio.h>
#include <stdlib.h>

/*
���� : N * N(N <= 50) ũ���� ���ڿ��� �����¿�밢������ �̵��ذ��� K�� P�� ���� ��� ���� �� �������� ������� �Ѵ�.
�� ������ ���̰� �־�����(0 < ���� <= 10^6) ������ ���̰� ���� ���� ���� ���� ���� ���̰� ���� ���� ���� ���� ���� ���Ѵ�.

�ذ� ��� : ����, ������ ������ ����ġ�� ũ�� ������ ��ǥ ������ ���� ������ ������ ���δ�. (���� <= 2500)���� �پ���.
�� �������δ� �� ������ �˰����� ���� ���̸� 1���� ���ʷ� �ø��� �ش� ���̿��� �ִ� ���̰� ���� �Ǿ��
��� K�� P�� �� ������ �Ǵ����� Ȯ���Ѵ�. ���� �ش� �������� �� �������� ����� ���� �����ϴٸ�
�ּ� ���̸� 1 �ø��� �Ұ����ϴٸ� �ִ� ���̸� 1 �ø���. �̹� �ִ� ���̶�� Ž���� �����Ѵ�.
Ž���� ������ ���� ���� ������ ������ ���� �� ���� ���̸� ���ϸ� �ȴ�.

�ֿ� �˰��� : �׷��� �̷�, �÷�����, ��������, ��ǥ����

��ó : COCI 10/11#7 4��
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