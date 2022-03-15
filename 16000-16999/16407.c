#include <stdio.h>
#include <ctype.h>
#define INF 1012345678

/*
���� : N * M(N, M <= 30) ũ���� ���ڿ� �ҹ��� ���ĺ��� '.', �빮�� 'B'�� ���� �ִ�.
�� �ҹ��� ���ĺ��� ĭ�� ���� ���� ���(<= 100000)�� �־�����, 'B'���� �����¿�� ������ ���� ������
���� �� ������ �ϴ� ����� �ִ� �� ���ϰ�, �ִٸ� �� �� �ּ� ����� ���Ѵ�.

�ذ� ��� : �� ���ڸ� 2���� �������� ������ ���� ������ �����ϴ� ������ �뷮���� �ҹ����� ��� �����,
�� �ܿ��� ���Ѵ븦 �����Ѵ�. ����, �����¿�� ������ ������ ���� ������ �뷮 ���Ѵ��� ��������
�����ϸ鼭 ������ ������ ��� �ٱ� �������� ������.
�̷��� �׷����� ����� 'B'�� ���� �������� �ٱ� ���������� �ִ� ������ �ּ� ����� �ȴ�.

�ֿ� �˰��� : �׷��� �̷�, �÷ο�

��ó : MidC 2018 C�� // PacNW 2018 E��
*/

char cal[32][32];
int cost[32], cap[2048][2048],  used[2048][2048], q[4096], f[2048], back[2048], vis[2048];
short ed[2048][2048];
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

int flow(int st, int ee) {
    int r = 0, x, qf, qr;
    while (1) {
        qf = 0, qr = 0;
        q[qr++] = st;
        f[st] = INF;
        while (qf < qr) {
            x = q[qf++];
            for (int i = 1; i <= ed[x][0]; i++) {
                if (vis[ed[x][i]] || cap[x][ed[x][i]] == used[x][ed[x][i]]) continue;
                back[ed[x][i]] = x;
                f[ed[x][i]] = cap[x][ed[x][i]] - used[x][ed[x][i]];
                if (f[x] < f[ed[x][i]]) f[ed[x][i]] = f[x];
                q[qr++] = ed[x][i];
                vis[ed[x][i]] = 1;
            }
        }
        //printf("%d\n", back[2047]);
        if (f[ee] == 0) break;

        for (int i = ee; i != st; i = back[i]) {
            used[back[i]][i] += f[ee];
            used[i][back[i]] -= f[ee];
        }
        r += f[ee];
        for (int i = 0; i < 2048; i++) {
            f[i] = 0;
            vis[i] = 0;
        }
    }
    return r;
}

int main(void) {
    int n, m, c, x, y, st = -1, r = 0;
    scanf("%d %d %d", &m, &n, &c);
    for (int i = 0; i < n; i++) {
        scanf("%s", cal[i]);
    }
    for (int i = 0; i < c; i++) {
        scanf("%d", &cost[i]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (cal[i][j] == 'B') {
                st = (i << 6) + (j << 1);
            }

            if (islower(cal[i][j])) {
                cap[(i << 6) + (j << 1)][(i << 6) + (j << 1) + 1] = cost[cal[i][j] - 'a'];
            }
            else cap[(i << 6) + (j << 1)][(i << 6) + (j << 1) + 1] = INF;
            ed[(i << 6) + (j << 1)][++ed[(i << 6) + (j << 1)][0]] = (i << 6) + (j << 1) + 1;
            ed[(i << 6) + (j << 1) + 1][++ed[(i << 6) + (j << 1) + 1][0]] = (i << 6) + (j << 1);

            for (int d = 0; d < 4; d++) {
                x = i + dxy[d][0];
                y = j + dxy[d][1];
                if (x < 0 || x >= n || y < 0 || y >= m) {
                    cap[(i << 6) + (j << 1) + 1][2047] = INF;
                    ed[(i << 6) + (j << 1) + 1][++ed[(i << 6) + (j << 1) + 1][0]] = 2047;
                    ed[2047][++ed[2047][0]] = (i << 6) + (j << 1) + 1;
                }
                else {
                    cap[(i << 6) + (j << 1) + 1][(x << 6) + (y << 1)] = INF;
                    ed[(i << 6) + (j << 1) + 1][++ed[(i << 6) + (j << 1) + 1][0]] = (x << 6) + (y << 1);
                    ed[(x << 6) + (y << 1)][++ed[(x << 6) + (y << 1)][0]] = (i << 6) + (j << 1) + 1;
                }
            }
        }
    }
    if (st < 0) return -1;
    r = flow(st, 2047);

    printf("%d", r == INF ? -1 : r);
    return 0;
}