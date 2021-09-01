#include <stdio.h>

/*
문제 : 100 이하의 자연수로 된 3차원 좌표에 블록들이 있다. 이때, 블록 사이의 빈 공간의 개수를 구한다.
빈 공간은 상하좌우전후 6개 방향이 전부 블록으로 막힌 공간을 말한다.

해결 방법 : 각 좌표별로 블록의 여부를 저장한 다음, 바깥쪽에서 먼저 플러드필을 돌리고, 전체 칸들에서 아직 방문하지 않은 빈 칸이
있다면 플러드필을 돌리는 동시에 결괏값을 1 증가시킨다. 이를 모든 칸에서 반복한 결괏값이 답이 된다.

주요 알고리즘 : 그래프 이론, 플러드필

출처 : Tehran 2004 E번
*/

char cubes[128][128][128], vis[128][128][128];
int dxyz[6][3] = { {0, 0, 1}, {0, 1, 0}, {1, 0, 0}, {0, 0, -1}, {0, -1, 0}, {-1, 0, 0} };

char isvalid(char x, char y, char z) {
    if (x < 0 || y < 0 || z < 0 || x > 103 || y > 103 || z > 103) return 0;
    if (vis[x][y][z] || cubes[x][y][z]) return 0;
    return 1;
}

int dfs(char x, char y, char z) {
    int r = 1;
    vis[x][y][z] = 1;
    for (int i = 0; i < 6; i++) {
        if (isvalid(x + dxyz[i][0], y + dxyz[i][1], z + dxyz[i][2])) {
            r += dfs(x + dxyz[i][0], y + dxyz[i][1], z + dxyz[i][2]);
        }
    }
    return r;
}

int main(void) {
    int m, t, x, y, z, r;
    //freopen("E:\\PS\\ICPC\\Asia West Continent\\Tehran Site\\2004\\tc04\\E.in", "r", stdin);
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &m);
        for (int i = 0; i < m; i++) {
            scanf("%d %d %d", &x, &y, &z);
            cubes[x + 1][y + 1][z + 1] = 1;
        }
        dfs(0, 0, 0);
        r = 0;
        for (int i = 0; i <= 103; i++) {
            for (int j = 0; j <= 103; j++) {
                for (int k = 0; k <= 103; k++) {
                    if (!cubes[i][j][k] && !vis[i][j][k]) {
                        dfs(i, j, k);
                        r++;
                    }
                }
            }
        }
        printf("%d\n", r);

        for (int i = 0; i <= 103; i++) {
            for (int j = 0; j <= 103; j++) {
                for (int k = 0; k <= 103; k++) {
                    cubes[i][j][k] = 0;
                    vis[i][j][k] = 0;
                }
            }
        }
    }
    return 0;
}