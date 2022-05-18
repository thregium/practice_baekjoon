#include <stdio.h>

/*
문제 : N * N(N <= 20) 크기의 격자에 M(M <= 5) 이하의 자연수와 0, -1이 쓰여있다.
매 턴마다 더이상 진행할 수 있는 연산이 없을 때 까지 다음 연산을 반복한다.
1. 자연수가 1개 이상 포함되어있고 크기 2 이상인 그룹 가운데 가장 큰 그룹, 여러 개라면 가장 0이 많은 그룹,
그 중에서 가장 왼쪽 위 자연수가 오른쪽 아래에 있는 그룹을 선택한다.
2. 그 그룹을 지우고 그룹의 크기^2 만큼의 점수를 얻는다.
중력을 적용시킨다. -1은 중력이 적용되지 않는다.
3. 왼쪽으로 격자를 90도 회전시킨다.
4. 다시 중력을 적용시킨다.
중력은 아래쪽 방향으로 적용된다. 또한, 그룹은 상하좌우로 연결되어 있는 경우를 말한다.

이때, 최종 점수를 구한다.

해결 방법 : 문제에 주어진대로 구현한다. 실수하지 않도록 주의한다.

주요 알고리즘 : 구현, 시뮬레이션, 플러드필, 투 포인터
*/

int block[32][32], tblock[32][32], vis[32][32];
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
int h, w;

void swap(int* a, int* b) {
    int c = *a;
    *a = *b;
    *b = c;
}

void copyarray(int* a, int* b, int r, int c) {
    for (int i = 0; i < r * c; i++) {
        a[i] = b[i];
    }
}

void unvis0(void) {
    for (int i = 0; i < 32; i++) {
        for (int j = 0; j < 32; j++) {
            if (block[i][j] == 0) vis[i][j] = 0;
        }
    }
}

void unvis(void) {
    for (int i = 0; i < 32; i++) {
        for (int j = 0; j < 32; j++) {
            vis[i][j] = 0;
        }
    }
}

void rotl(int* a, int* t, int* h, int* w, int lsz) {
    for (int i = *w - 1; i >= 0; i--) {
        for (int j = *h - 1; j >= 0; j--) {
            t[i * lsz + j] = a[j * lsz + (*w - i - 1)];
        }
    }
    for (int i = *w - 1; i >= 0; i--) {
        for (int j = *h - 1; j >= 0; j--) a[i * lsz + j] = t[i * lsz + j];
    }
    swap(h, w);
}

void fall(int* a, int h, int w, int lsz) {
    int fallh;
    for (int i = 0; i < w; i++) {
        fallh = h - 1;
        for (int j = h - 1; j >= 0; j--) {
            if (a[j * lsz + i] == -1) {
                for (int k = fallh; k > j; k--) a[k * lsz + i] = -2;
                fallh = j - 1;
            }
            else if (a[j * lsz + i] >= 0) {
                a[fallh * lsz + i] = a[j * lsz + i];
                fallh--;
            }
        }
        for (int k = fallh; k >= 0; k--) a[k * lsz + i] = -2;
    }
}

int isvalid(int x, int y, int c) {
    if (x < 0 || y < 0 || x >= h || y >= w) return 0;
    else if (block[x][y] < 0 || (block[x][y] > 0 && block[x][y] != c)) return 0;
    if (vis[x][y]) return 0;
    return 1;
}

int dfs(int x, int y, int c) {
    int r = 1024;
    vis[x][y] = 1;
    if (block[x][y] == 0) r++;
    for (int i = 0; i < 4; i++) {
        if (isvalid(x + dxy[i][0], y + dxy[i][1], c)) r += dfs(x + dxy[i][0], y + dxy[i][1], c);
    }
    return r;
}

int main(void) {
    int n, m, score_dfs, bscore_dfs, bx, by, score_sum = 0;
    scanf("%d %d", &n, &m);
    h = n, w = n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &block[i][j]);
        }
    }
    while (1) {
        bscore_dfs = 0, bx = -1, by = -1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (block[i][j] > 0 && !vis[i][j]) {
                    score_dfs = dfs(i, j, block[i][j]);
                    if (score_dfs >= bscore_dfs) {
                        bx = i, by = j;
                        bscore_dfs = score_dfs;
                    }
                    unvis0();
                }
            }
        }

        if (bscore_dfs < 2048) break;
        score_sum += (bscore_dfs >> 10) * (bscore_dfs >> 10);
        unvis();
        dfs(bx, by, block[bx][by]);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (vis[i][j]) block[i][j] = -2;
            }
        }
        unvis();

        fall(block, h, w, 32);
        rotl(block, tblock, &h, &w, 32);
        fall(block, h, w, 32);
    }
    printf("%d", score_sum);
    return 0;
}