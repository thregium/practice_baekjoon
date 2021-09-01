#include <stdio.h>

/*
문제 : N * M(N, M <= 50) 크기의 격자에 숫자와 구멍들이 있다. 각 칸에서 구멍에 닿거나 격자 밖으로 나가기까지
해당 칸에 쓰인 칸의 숫자만큼 상하좌우로 이동 가능하다.(중간에 있는 구멍은 무시한다.)
이때, 맨 왼쪽 위에서 시작해서 가장 많이 움직일 때의 움직일 수 있는 최대 횟수를 구한다.
만약 무한 번 이동이 가능하다면 -1을 출력한다.

해결 방법 : 먼저 각 칸들에서 이동 가능한 칸들을 미리 구한다. 그 다음, 맨 왼쪽 위 칸에서 여러 회 이동을 통해 이동 가능한
칸들을 구하고, 해당 칸으로 들어가는 진입 간선들만으로 그래프를 만든다.
그 그래프를 바탕으로 왼쪽 위 칸에서 시작하는 DP를 한다. 각 칸들에서 해당하는 값은 이전 칸들의 값 중 최댓값 + 1이다.
그런데 DP가 끝나고 아직 진입 차수가 남아있는 간선이 있다면 해당 간선을 통해 사이클이 만들어진다는 의미이므로
무한 번 이동이 가능하다. 그렇지 않다면 전체 칸들의 값 가운데 가장 큰 것이 답이 된다.

주요 알고리즘 : 그래프 이론, 위상 정렬, DP
*/

char board[64][64];
int ed[4096][8], ins[4096], mv[4096], vis[4096], ava[4096];
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

void dfs(int p) {
    ava[p] = 1;
    for (int i = 1; i <= ed[p][0]; i++) {
        if (!ava[ed[p][i]]) dfs(ed[p][i]);
    }
}

void dp(int x, int y) {
    int n = x * 64 + y;
    if (vis[n] || ins[n]) return;
    vis[n] = 1;
    for (int i = 1; i <= ed[n][0]; i++) {
        ins[ed[n][i]]--;
        if (mv[n] + 1 > mv[ed[n][i]]) mv[ed[n][i]] = mv[n] + 1;
        dp(ed[n][i] >> 6, ed[n][i] & 63);
    }
}

int main(void) {
    int n, m, x, y, t, a = 1, s = 1, r = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s", &board[i]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 'H') continue;
            for (int d = 0; d < 4; d++) {
                x = i + dxy[d][0] * (board[i][j] - '0');
                y = j + dxy[d][1] * (board[i][j] - '0');
                if (x < 0 || y < 0 || x >= n || y >= m) continue;
                if (board[x][y] == 'H') continue;
                ed[i * 64 + j][++ed[i * 64 + j][0]] = x * 64 + y;
            }
        }
    }
    dfs(0);
    for (int i = 0; i < 64 * n; i++) {
        if (!ava[i]) continue;
        for (int j = 1; j <= ed[i][0]; j++) {
            ins[ed[i][j]]++;
        }
    }
    mv[0] = 1;
    dp(0, 0);
    for (int i = 0; i < 64 * n; i++) {
        if (mv[i] > r) r = mv[i];
        if (ins[i]) {
            printf("-1");
            return 0;
        }
    }
    printf("%d", r);
    return 0;
}