#include <stdio.h>
#include <stdlib.h>
#include <queue>
using namespace std;

/*
문제 : R * C(R, C <= 100) 크기의 '.'과 'x'로 이루어진 격자판이 있다. 이때, N(N <= 100)번동안 일정한 높이로
왼쪽, 오른쪽 번갈아가며 주어진 높이들 X_i로 막대를 던졌을 때 최종적으로 나오는 모양을 출력한다.
막대를 던진 후 가장 가까이 있는 'x'는 사라지고 그 후 상하좌우로 붙어있지 않은 'x'의 묶음은 아래로 떨어지게 된다.

해결 방법 : 우선 매번 막대를 던질 때 마다 막대가 도달하는 'x'를 찾는다. 찾은 다음에는 그 'x'를 지운 후
상하좌우 각 연결에 대해 붙어있는 'x'의 묶음을 각각 구하고 격자판에서 지워준다.
각 묶음을 구한 다음에는 각 묶음들이 모두 멈출 때 까지 한칸씩 내려나가면 된다.
이 과정에서 멈추었는지 여부는 묶음의 원소들 가운데 아래 칸이 'x'이거나 바닥인 경우를 찾으면 알 수 있다.
멈추었다면 그 위치에 묶음을 'x'로 놓는다. 이때, 이 과정에서 연쇄적으로 멈추는 경우가 생길 수 있기 때문에
4번은 이를 살펴보아야 한다. 멈추지 않은 묶음들은 1칸씩 내린 다음 이 과정을 모두 멈추기 전까지 반복하면 된다.

주요 알고리즘 : 그래프 이론, 플러드필, BFS, 시뮬레이션, 큐, ...

출처 : CHCI 2009CR 5번 / 2009RJ 4번
*/

char mine[128][128], vis[128][128];
int store[4][10240][2], fin[4];
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
int r, c;
queue<pair<int, int>> q[4];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    if (ai != bi) return ai < bi ? 1 : -1;
    ai = *((int*)a + 1);
    bi = *((int*)b + 1);
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int isvalid(int x, int y) {
    if (x < 0 || y < 0 || x >= r || y >= c) return 0;
    if (mine[x][y] == '.' || vis[x][y]) return 0;
    return 1;
}

void dfs(int x, int y, int d) {
    vis[x][y] = 1;
    mine[x][y] = '.';
    store[d][++store[d][0][0]][0] = x;
    store[d][store[d][0][0]][1] = y;
    for (int i = 0; i < 4; i++) {
        if (isvalid(x + dxy[i][0], y + dxy[i][1])) dfs(x + dxy[i][0], y + dxy[i][1], d);
    }
}

int main(void) {
    int n, x, y;
    //freopen("E:\\PS\\Olympiad\\Croatia\\2009\\regional_testdata\\official_test_data\\reljef\\reljef.in.5", "r", stdin);
    //freopen("E:\\PS\\Olympiad\\Croatia\\2009\\regional_testdata\\official_test_data\\reljef\\reljef.out_t.5", "w", stdout);
    scanf("%d %d", &r, &c);
    for (int i = 0; i < r; i++) {
        scanf("%s", mine[i]);
    }
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        x = r - x;
        y = -1;
        if (i & 1) {
            for (int j = c - 1; j >= 0; j--) {
                if (mine[x][j] == 'x') {
                    y = j;
                    break;
                }
            }
        }
        else {
            for (int j = 0; j < c; j++) {
                if (mine[x][j] == 'x') {
                    y = j;
                    break;
                }
            }
        }
        //막대가 'x'에 닿는 위치를 구한다. 닿지 않는다면 다음 막대를 던진다.
        if (y < 0) continue;

        mine[x][y] = '.';
        for (int j = 0; j < 4; j++) {
            //상하좌우 각 방향에 대해 해당 방향의 묶음들을 구해둔다. 그리고 묶음들을 지워나간다.
            if (isvalid(x + dxy[j][0], y + dxy[j][1])) dfs(x + dxy[j][0], y + dxy[j][1], j);
            qsort(&store[j][1], store[j][0][0], sizeof(int) * 2, cmp1);
            for (int k = 1; k <= store[j][0][0]; k++) {
                q[j].push(pair<int, int>(store[j][k][0], store[j][k][1]));
                if (mine[store[j][k][0] + 1][store[j][k][1]] == 'x' || store[j][k][0] + 1 == r) fin[j] = 1;
                //만약 이미 멈추어있는 상태인 경우 멈추었음을 표시해둔다.
            }
            store[j][0][0] = 0;
        }
        for (int j = 0; j < r; j++) {
            for (int k = 0; k < c; k++) vis[j][k] = 0; //방문 여부를 초기화한다.
        }
        
        while (1) {
            //각 묶음들을 내려나간다.
            if (fin[0] + fin[1] + fin[2] + fin[3] == 8) break;
            for (int k = 0; k < 5; k++) {
                for (int j = 0; j < 4; j++) {
                    //내려나가기 전에 멈추었는지 여부를 체크한다. 연쇄적인 멈춤에 대비해 여러 번 돌려야 한다.
                    if (q[j].size() == 0) fin[j] = 1;
                    for (int p = 0; p < q[j].size(); p++) {
                        x = q[j].front().first;
                        y = q[j].front().second;
                        q[j].pop();
                        if (mine[x + 1][y] == 'x' || x + 1 == r) fin[j] = 1;
                        q[j].push(pair<int, int>(x, y));
                    }
                    if (fin[j]) {
                        while (q[j].size()) {
                            //멈춘 경우 묶음을 다시 표시한다.
                            x = q[j].front().first;
                            y = q[j].front().second;
                            q[j].pop();
                            mine[x][y] = 'x';
                        }
                        fin[j] = 2;
                    }
                }
            }
            for (int j = 0; j < 4; j++) {
                //멈추지 않았다면 묶음의 각 원소를 한 칸 내린다.
                if (fin[j] == 0) {
                    for (int k = 0; k < q[j].size(); k++) {
                        x = q[j].front().first;
                        y = q[j].front().second;
                        q[j].pop();
                        q[j].push(pair<int, int>(x + 1, y));
                    }
                }
                
            }
        }
        for (int i = 0; i < 4; i++) fin[i] = 0;
    }

    for (int i = 0; i < r; i++) {
        printf("%s\n", mine[i]);
    }
    return 0;
}