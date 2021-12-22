#include <stdio.h>

/*
���� : N * M(N, M <= 50) ũ���� ���ڿ� ���ڿ� ���۵��� �ִ�. �� ĭ���� ���ۿ� ��ų� ���� ������ ���������
�ش� ĭ�� ���� ĭ�� ���ڸ�ŭ �����¿�� �̵� �����ϴ�.(�߰��� �ִ� ������ �����Ѵ�.)
�̶�, �� ���� ������ �����ؼ� ���� ���� ������ ���� ������ �� �ִ� �ִ� Ƚ���� ���Ѵ�.
���� ���� �� �̵��� �����ϴٸ� -1�� ����Ѵ�.

�ذ� ��� : ���� �� ĭ�鿡�� �̵� ������ ĭ���� �̸� ���Ѵ�. �� ����, �� ���� �� ĭ���� ���� ȸ �̵��� ���� �̵� ������
ĭ���� ���ϰ�, �ش� ĭ���� ���� ���� �����鸸���� �׷����� �����.
�� �׷����� �������� ���� �� ĭ���� �����ϴ� DP�� �Ѵ�. �� ĭ�鿡�� �ش��ϴ� ���� ���� ĭ���� �� �� �ִ� + 1�̴�.
�׷��� DP�� ������ ���� ���� ������ �����ִ� ������ �ִٸ� �ش� ������ ���� ����Ŭ�� ��������ٴ� �ǹ��̹Ƿ�
���� �� �̵��� �����ϴ�. �׷��� �ʴٸ� ��ü ĭ���� �� ��� ���� ū ���� ���� �ȴ�.

�ֿ� �˰����� : �׷��� �̷�, ���� ����, DP
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