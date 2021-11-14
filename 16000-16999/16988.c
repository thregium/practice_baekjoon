#include <stdio.h>

/*
문제 : N * M(N, M <= 20) 크기의 바둑판에 흰 돌 2개를 추가해서 잡을 수 있는 검은 돌의 최대 개수를 구한다.
빈 칸이면 어디든 돌을 놓을 수 있고, 검은 돌 무리에서 상하좌우로 이동하여 흰 돌을 지나지 않고 갈 수 있는
빈 칸이 없다면 잡힌 돌이다.

해결 방법 : 흰 돌 2개를 놓을 수 있는 모든 조합으로 놓아본다. 그 다음, 방문하지 않은 검은 돌이 나올 때 마다
그 돌에서 플러드필을 돌리며 잡힌 돌인 경우 그 개수를 잡힌 돌 수에 추가한다. 이 값이 가장 큰 것을 찾으면 된다.
잡힌 돌이 아닌 경우에는 값을 추가하지 않고 방문 처리만 한다.

주요 알고리즘 : 그래프 이론, 플러드필, 브루트 포스
*/

int baduk[32][32], vis[32][32];
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
int n, m;

int isvalid(int x, int y) {
    if (x < 0 || y < 0 || x >= n || y >= m) return 0;
    if (vis[x][y] || baduk[x][y] == 1) return 0;
    if (baduk[x][y] == 0) return -1;
    return 1;
}

int dfs1(int x, int y) {
    //잡힌 돌 무더기인 경우 돌 개수 반환, 잡히지 않은 돌 무더기인 경우 0 반환
    int r = 1, t = 0, rb = 1;
    vis[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        t = isvalid(x + dxy[i][0], y + dxy[i][1]);
        if (t == 0) continue; //관계 없는 경우
        else if (t < 0) rb = 0; //빈 칸이 주변에 나온 경우
        else {
            //검은 돌이 주변에 나온 경우
            t = dfs1(x + dxy[i][0], y + dxy[i][1]);
            if (t == 0) rb = 0; //그 돌 이후에서 빈 칸을 찾은 경우
            else r += t; //빈 칸이 없는 경우 개수 추가
        }
    }
    if (rb == 0) return 0; //빈 칸이 있는 경우
    else return r; //빈 칸이 없는 경우
}

int main(void) {
    int r = -1, rt = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &baduk[i][j]);
        }
    }

    for (int i1 = 0; i1 < n; i1++) {
        for (int j1 = 0; j1 < m; j1++) {
            if (baduk[i1][j1] != 0) continue;
            baduk[i1][j1] = 1;
            for (int i2 = 0; i2 < n; i2++) {
                for (int j2 = 0; j2 < m; j2++) {
                    if (baduk[i2][j2] != 0) continue;
                    baduk[i2][j2] = 1;
                    //가능한 모든 조합 확인
                    rt = 0;
                    for (int ii = 0; ii < n; ii++) {
                        for (int jj = 0; jj < m; jj++) {
                            if (!vis[ii][jj] && baduk[ii][jj] == 2) {
                                rt += dfs1(ii, jj); //방문하지 않은 모든 검은 돌에서 잡힌 돌 여부 확인
                            }
                        }
                    }
                    for (int ii = 0; ii < n; ii++) {
                        for (int jj = 0; jj < m; jj++) {
                            vis[ii][jj] = 0; //방문 배열 초기화
                        }
                    }
                    if (rt > r) r = rt;
                    baduk[i2][j2] = 0;
                }
            }
            baduk[i1][j1] = 0;
        }
    }
    printf("%d", r);
    return 0;
}