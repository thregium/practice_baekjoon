#include <stdio.h>

/*
문제 : H * W(H, W <= 100) 크기의 땅의 각 칸에 대해 지형의 높이(<= 10000)가 각각 주어진다. 각 칸에서
주변 4칸 가운데 현재 위치보다 낮은 곳 중 가장 낮은 곳, 여러 곳인 경우 북->서->동->남쪽 우선순위로
물이 흐른다. 또한, 물이 흐를 수 없는 곳은 물이 고이는 곳이 된다. 물이 고이는 곳이 26곳 이하라면
물이 고이는 서로 다른 위치들을 알파벳으로 출력한다. 가능한 방법 가운데 사전순으로 가장 빠른 것을 구한다.

해결 방법 : 그래프로 상하좌우를 살펴보며 조건에 맞게 물이 흐르는 곳을 찾는다.
그곳을 찾았으면 양방향 간선을 연결한다. 그 후 전체 땅을 살펴보면서 아직 방문하지 않은 땅마다
플러드필을 해준다. 최종적으로 플러드필을 한 번째수가 각 칸의 물이 고이는 위치 번호가 된다.

주요 알고리즘 : 그래프 이론, 플러드필

출처 : GCJ 2009Q B2번
*/

int ht[128][128], ed[128][128][16], edc[128][128], vis[128][128];
int dxy[4][2] = { {-1, 0}, {0, -1}, {0, 1}, {1, 0} };

int isvalid(int h, int w, int x, int y) {
    if (x < 0 || y < 0 || x >= h || y >= w) return 0;
    else if (vis[x][y]) return -1;
    return 1;
}

void dfs(int h, int w, int x, int y, int s) {
    vis[x][y] = s;
    for (int i = 0; i < edc[x][y]; i++) {
        if (isvalid(h, w, ed[x][y][i] >> 7, ed[x][y][i] & 127) > 0) {
            dfs(h, w, ed[x][y][i] >> 7, ed[x][y][i] & 127, s);
        }
    }
}

int main(void) {
    int t, h, w, dir, lwst, xx, yy, sinkcnt;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        scanf("%d %d", &h, &w);
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                scanf("%d", &ht[i][j]);
                edc[i][j] = 0;
                vis[i][j] = 0;
            }
        }
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                dir = -1, lwst = ht[i][j];
                for (int k = 0; k < 4; k++) {
                    xx = i + dxy[k][0];
                    yy = j + dxy[k][1];
                    if (!isvalid(h, w, xx, yy)) continue;
                    if (ht[xx][yy] < lwst) {
                        lwst = ht[xx][yy];
                        dir = k;
                    }
                }
                if (dir < 0) continue;
                xx = i + dxy[dir][0];
                yy = j + dxy[dir][1];
                ed[i][j][edc[i][j]++] = xx * 128 + yy;
                ed[xx][yy][edc[xx][yy]++] = i * 128 + j;
            }
        }

        sinkcnt = 0;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (vis[i][j]) continue;
                else dfs(h, w, i, j, ++sinkcnt);
            }
        }
        
        printf("Case #%d:\n", tt);
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                printf("%c%c", vis[i][j] + 'a' - 1, j == w - 1 ? '\n' : ' ');
            }
        }
    }
    return 0;
}