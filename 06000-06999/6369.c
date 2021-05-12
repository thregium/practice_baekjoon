#include <stdio.h>

/*
문제 : N * N * N(N <= 20) 크기의 블록들이 있다. 이 블록을 각각 위, 앞, 옆에서 본 모습들이 주어질 때,
이 블록들을 연속되게 쌓아서 이러한 모습을 만들 수 있는지 구한다.

해결 방법 : 먼저, 각 모습들이 어떤 방향을 향하고 있는지 알 수 없기 때문에 4가지 방향에 대해 각각 돌린 모습들을 미리 만들어 놓는다.
그 다음, 각 방향마다 4가지씩 64가지 방향 조합에 따라 블록을 쌓는다. 이때, 위, 앞, 옆에서 모두 블록을 쌓을 수 있는 경우에만 블록을 놓고,
하나라도 없는 경우에는 블록을 놓지 않는다. 그 다음으로 블록이 제대로 놓였는지 다시 위, 앞, 옆에서 본 모습을 주어진 모습과 비교해본다.
만약 다르다면 다시 다음 방향을 살펴보고, 같다면 이제 연속되게 쌓였는지 확인하기 위해 플러드필을 통해 블록의 연결 요소의 개수를 구하면 된다.
만약 1개인 경우 연속되게 쌓아서 만들 수 있는 경우이고, 1개가 아니라면 연속되게 쌓아서 만들 수 없는 경우가 된다.

주요 알고리즘 : 구현, 브루트 포스, 플러드필, 그리디 알고리즘

출처 : GNY 2001 C번
*/

char top[4][32][32], front[4][32][32], side[4][32][32], blocks[32][32][32], vis[32][32][32];
int dxyz[6][3] = { {0,0,1}, {0,0,-1}, {0,1,0}, {0,-1,0}, {1,0,0}, {-1,0,0} };
int n;

void build_blocks(int dir) {
    //주어진 방향의 투영에 맞게 블록을 쌓는다.
    int td = dir / 16;
    int fd = dir / 4 % 4;
    int sd = dir % 4;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (top[td][j][k] == 'X' && front[fd][i][j] == 'X' && side[sd][i][k] == 'X') blocks[i][j][k] = 'X';
                else blocks[i][j][k] = '-';
            }
        }
    }
}

void rotate(void) {
    //주어진 모습들을 4가지 방향으로 돌린다.
    for (int d = 0; d < 3; d++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                top[d + 1][i][j] = top[d][n - j - 1][i];
                front[d + 1][i][j] = front[d][n - j - 1][i];
                side[d + 1][i][j] = side[d][n - j - 1][i];
            }
        }
    }
}

int matches(int dir) {
    //현재 쌓은 블록의 투영을 주어진 방향과 맞는지 확인해본다.
    int td = dir / 16;
    int fd = dir / 4 % 4;
    int sd = dir % 4;

    char topt[32][32], frontt[32][32], sidet[32][32];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            topt[i][j] = '-';
            frontt[i][j] = '-';
            sidet[i][j] = '-';
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (blocks[i][j][k] == 'X') {
                    topt[j][k] = 'X';
                    frontt[i][j] = 'X';
                    sidet[i][k] = 'X';
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (topt[i][j] != top[td][i][j] || frontt[i][j] != front[fd][i][j] || sidet[i][j] != side[sd][i][j]) return 0;
        }
    }
    return 1;
}

int isvalid(int x, int y, int z) {
    //현재 위치가 갈 수 있는 위치인지 확인한다.
    if (x < 0 || y < 0 || z < 0 || x >= n || y >= n || z >= n) return 0;
    if (vis[x][y][z] || blocks[x][y][z] == '-') return 0;
    return 1;
}

void dfs(int x, int y, int z) {
    //DFS를 통해 해당 위치에서 갈 수 있는 모든 블록들을 확인한다.
    vis[x][y][z] = 1;
    for (int i = 0; i < 6; i++) {
        if (isvalid(x + dxyz[i][0], y + dxyz[i][1], z + dxyz[i][2])) {
            dfs(x + dxyz[i][0], y + dxyz[i][1], z + dxyz[i][2]);
        }
    }
}

int main(void) {
    int cnt, r;
    for (int tt = 1;; tt++) {
        scanf("%d", &n);
        if (n == 0) break;
        for (int i = 0; i < n; i++) scanf("%s", top[0][i]);
        for (int i = 0; i < n; i++) scanf("%s", front[0][i]);
        for (int i = 0; i < n; i++) scanf("%s", side[0][i]);

        rotate();
        r = 0;
        for (int i = 0; i < 64; i++) {
            build_blocks(i);
            if (!matches(i)) continue;
            cnt = 0;
            for (int x = 0; x < n; x++) {
                for (int y = 0; y < n; y++) {
                    for (int z = 0; z < n; z++) {
                        if (blocks[x][y][z] == 'X' && !vis[x][y][z]) {
                            dfs(x, y, z);
                            cnt++;
                        }
                    }
                }
            }
            for (int x = 0; x < n; x++) {
                for (int y = 0; y < n; y++) {
                    for (int z = 0; z < n; z++) vis[x][y][z] = 0;
                }
            }
            if (cnt == 1) {
                r = 1;
                break;
            }
        }
        if (r) printf("Data set %d: Valid set of patterns\n", tt);
        else printf("Data set %d: Impossible combination\n", tt);
    }
    return 0;
}