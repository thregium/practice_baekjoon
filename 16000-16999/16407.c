#include <stdio.h>
#include <ctype.h>
#define INF 1012345678

/*
문제 : N * M(N, M <= 30) 크기의 격자에 소문자 알파벳과 '.', 대문자 'B'가 쓰여 있다.
각 소문자 알파벳의 칸을 막을 때의 비용(<= 100000)이 주어지면, 'B'에서 상하좌우로 움직여 격자 밖으로
나갈 수 없도록 하는 방법이 있는 지 구하고, 있다면 그 중 최소 비용을 구한다.

해결 방법 : 각 격자를 2개의 정점으로 나누어 나눈 정점을 연결하는 간선의 용량으로 소문자인 경우 비용을,
그 외에는 무한대를 지정한다. 또한, 상하좌우로 나오는 정점과 들어가는 정점을 용량 무한대의 간선으로
지정하면서 밖으로 나오는 경우 바깥 정점으로 빼낸다.
이렇게 그래프를 만들면 'B'의 시작 정점에서 바깥 정점으로의 최대 유량이 최소 비용이 된다.

주요 알고리즘 : 그래프 이론, 플로우

출처 : MidC 2018 C번 // PacNW 2018 E번
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