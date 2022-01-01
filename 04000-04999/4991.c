#include <stdio.h>
#define INF 103000

/*
문제 : H * W(H, W <= 20) 크기의 방에 상하좌우로 이동 가능한 로봇 청소기와 10개 이하의 더러운 칸이 있다.
모든 더러운 칸을 치우기 위해 로봇 청소기가 이동하기 위해 필요한 최소 이동 횟수를 구한다. 전부 치울 수 없다면 -1을 출력한다.

해결 방법 : 방의 크기가 크지 않기 때문에 플로이드-워셜 알고리즘을 통해 방의 모든 지점 사이의 거리를 구할 수 있고,
그를 이용해 브루트 포스를 하면 최소 이동 회수가 나온다.
방의 양쪽이 벽이 아닌 경우 이동 가능하므로 거리가 1인 간선으로 이어준 다음 플로이드-워셜을 하면 거리가 나온다.
브루트 포스는 재귀를 통해 모든 순열을 검사해주면 된다.

주요 알고리즘 : 그래프 이론, 플로이드-워셜, 브루트 포스

출처 : JDC 2005 F번
*/

char room[32][32];
int dist[512][512], dust[16][2], chk[16];
int dc, best;

void track(int c, int w, int x, int y, int r) {
    if (c == dc) {
        if (r < best) best = r;
        return;
    }

    for (int i = 0; i < dc; i++) {
        if (chk[i]) continue;
        chk[i] = 1;
        track(c + 1, w, dust[i][0], dust[i][1], r + dist[x * w + y][dust[i][0] * w + dust[i][1]]);
        chk[i] = 0;
    }
}

int main(void) {
    int w, h, x, y;
    //freopen("E:\\PS\\ICPC\\Asia Pacific\\Japan Domestic\\2005\\INPUT\\F1.txt", "r", stdin);
    while (1) {
        scanf("%d %d", &w, &h);
        x = -1, y = -1, dc = 0;
        for (int i = 0; i < h; i++) {
            scanf("%s", room[i]);
            for (int j = 0; j < w; j++) {
                if (room[i][j] == '*') {
                    dust[dc][0] = i;
                    dust[dc][1] = j;
                    dc++;
                }
                else if (room[i][j] == 'o') {
                    x = i;
                    y = j;
                }
            }
        }
        if (x < 0) return 1;

        for (int i = 0; i < h * w; i++) {
            for (int j = 0; j < h * w; j++) dist[i][j] = INF;
            dist[i][i] = 0;
        }
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w - 1; j++) {
                if (room[i][j] != 'x' && room[i][j + 1] != 'x') {
                    dist[i * w + j][i * w + j + 1] = 1;
                    dist[i * w + j + 1][i * w + j] = 1;
                }
            }
        }
        for (int i = 0; i < h - 1; i++) {
            for (int j = 0; j < w; j++) {
                if (room[i][j] != 'x' && room[i + 1][j] != 'x') {
                    dist[i * w + j][(i + 1) * w + j] = 1;
                    dist[(i + 1) * w + j][i * w + j] = 1;
                }
            }
        }
        for (int k = 0; k < h * w; k++) {
            for (int i = 0; i < h * w; i++) {
                if (dist[i][k] == INF) continue;
                for (int j = 0; j < h * w; j++) {
                    if (dist[i][k] + dist[k][j] < dist[i][j]) dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }

        best = INF;
        track(0, w, x, y, 0);
        printf("%d\n", best == INF ? -1 : best);
    }
    return 0;
}