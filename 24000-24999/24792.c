#include <stdio.h>
#define INF 1012345678

/*
문제 : R * C(R, C <= 15) 크기의 절벽이 주어진다. 각 절벽의 칸에 들어올 때 잃는 체력의 양(|| <= 9)이
정수로 주어진다. 이때, 절벽의 맨 위에 도달하는 데 필요한 체력의 최소 량을 구한다.
같은 칸은 얼마든지 다시 갈 수 있다.

해결 방법 : 같은 칸을 반복해서 갈 수 있기 때문에 음수 사이클이 생기는 경우 그 곳에 도달하면
그 사이클을 무한히 돌면서 체력을 무한히 보충할 수 있어 사실상 도착한 것이나 마찬가지가 된다.
따라서, 음수 사이클에 있는 모든 음수 지점들의 체력값을 0으로 바꾼 다음, 플로이드-워셜 알고리즘으로
음수 지점들 사이 거리가 음수가 되는 지 확인한다. 음수가 된다면 그곳에 포함되는 양 끝 점들의 값을
0으로 바꾸고, 해당 지점을 도착점으로 체크한다. 되지 않는 칸들은 다시 음수로 바꿔준다.

이 과정이 끝나면 이대로 다시 플로이드-워셜 알고리즘을 통해 절벽의 모든 칸에서 모든 칸에 도달하는
거리를 구한 다음, 모든 출발 칸에서 모든 도착 칸으로 이동하는 방법 가운데 가장 작은 체력을 사용하는
칸을 구해 나가면 된다. 음수 사이클을 모두 제거했으므로 답은 음수가 되지 않는다.

주요 알고리즘 : 그래프 이론, 플로이드-워셜

출처 : VTH 2016 J번
*/

char dir[256];
int cliff[32][16], vis[32][16], dist[384][384], neg[384], fin[384];
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

int small(int a, int b) {
    return a < b ? a : b;
}

int isvalid(int r, int c, int x, int y) {
    if (x < 0 || y < 1 || x > r + 1 || y > c) return 0;
    return 1;
}

void floyd(int r, int c) {
    for (int i = 0; i < 384; i++) {
        for (int j = 0; j < 384; j++) dist[i][j] = INF;
    }
    for (int i = 0; i <= r + 1; i++) {
        for (int j = 1; j <= c; j++) {
            for (int k = 0; k < 4; k++) {
                if (isvalid(r, c, i + dxy[k][0], j + dxy[k][1])) {
                    dist[(i + dxy[k][0]) * 16 + (j + dxy[k][1])][i * 16 + j] = cliff[i][j];
                }
            }
        }
    }
    for (int k = 0; k < 384; k++) {
        for (int i = 0; i < 384; i++) {
            for (int j = 0; j < 384; j++) dist[i][j] = small(dist[i][j], dist[i][k] + dist[k][j]);
        }
    }
}

int main(void) {
    int r, c, t, res = INF, ans;
    char trash;
    for (int tt = 1; tt <= 1; tt++) {
        sprintf(dir, "E:\\PS\\High School\\VTH\\2016\\rockclimbing\\data\\secret\\%d.in", tt);
        //freopen(dir, "r", stdin);
        res = INF;
        scanf("%d %d", &r, &c);
        for (int i = 1; i <= c; i++) {
            scanf(" %c", &trash);
            fin[i + 16] = 1;
        }
        for (int i = 1; i <= r; i++) {
            for (int j = 1; j <= c; j++) {
                scanf("%d", &cliff[i][j]);
                if (cliff[i][j] < 0) {
                    neg[i * 16 + j] = -cliff[i][j];
                    cliff[i][j] = 0;
                }
            }
        }
        floyd(r, c);

        for (int i = 0; i < 384; i++) {
            if (neg[i]) cliff[i >> 4][i & 15] = -neg[i];
        }
        for (int i = 0; i < 384; i++) {
            if (!neg[i]) continue;
            for (int j = 0; j < 384; j++) {
                if (!neg[j]) continue;
                if (dist[i][j] - neg[i] < 0) {
                    fin[i] = 1, fin[j] = 1;
                    cliff[i >> 4][i & 15] = 0;
                    cliff[j >> 4][j & 15] = 0;
                }
            }
        }

        floyd(r, c);
        for (int i = 1; i <= c; i++) {
            for (int j = 0; j < 384; j++) {
                if (!fin[j]) continue;
                if (dist[16 * (r + 1) + i][j] < res) res = dist[16 * (r + 1) + i][j];
            }
        }
        if (res == INF) return 1;
        sprintf(dir, "E:\\PS\\High School\\VTH\\2016\\rockclimbing\\data\\secret\\%d.ans", tt);
        //freopen(dir, "r", stdin);
        printf("%d", res);
        //scanf("%d", &ans);
        //if (res == ans) printf(" == %d\n", ans);
        //else printf(" != %d\n", ans);

        for (int i = 0; i < 32; i++) {
            for (int j = 0; j < 16; j++) {
                cliff[i][j] = 0;
                vis[i][j] = 0;
            }
        }
        for (int i = 0; i < 384; i++) {
            fin[i] = 0;
            neg[i] = 0;
        }
    }
    return 0;
}