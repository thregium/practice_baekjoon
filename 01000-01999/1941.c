#include <stdio.h>

/*
���� : 5 * 5 ũ���� ���ڿ��� �����¿�� ������ 7���� ĭ�� ������ 4�� �̻��� S�� �ǵ��� �ϴ� ������ ���� ���Ѵ�.

�ذ� ��� : 25�� �� 7���� ĭ�� ������ ���� ������ �� �÷������� ���� ��� �������� Ȯ���� ��, 4�� �̻��� S���� Ȯ���ϸ� �ȴ�.

�ֿ� �˰��� : ���Ʈ ����, �÷�����
*/

int sel[8][8], vis[5][5];
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
char sy[8][8];
int res = 0;

int isvalid(int x, int y) {
    if (x < 0 || y < 0 || x >= 5 || y >= 5) return 0;
    if (vis[x][y] || !sel[x][y]) return 0;
    return 1;
}

void dfs(int x, int y) {
    vis[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        if (isvalid(x + dxy[i][0], y + dxy[i][1])) dfs(x + dxy[i][0], y + dxy[i][1]);
    }
}

int check(void) {
    int cnt = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            vis[i][j] = 0;
            if (sel[i][j] && sy[i][j] == 'S') cnt++;
        }
    }
    if (cnt < 4) return 0;
    cnt = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (!vis[i][j] && sel[i][j]) {
                dfs(i, j);
                cnt++;
                if (cnt > 1) return 0;
            }
        }
    }
    return 1;
}

void track(int c, int x, int y) {
    if (c == 7) {
        if (check()) res++;
        return;
    }

    for (int i = y + 1; i < 5; i++) {
        if (sel[x][i]) continue;
        sel[x][i] = 1;
        track(c + 1, x, i);
        sel[x][i] = 0;
    }
    for (int i = x + 1; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (sel[i][j]) continue;
            sel[i][j] = 1;
            track(c + 1, i, j);
            sel[i][j] = 0;
        }
    }
}

int main(void) {
    for (int i = 0; i < 5; i++) {
        scanf("%s", sy[i]);
    }
    track(0, 0, -1);
    printf("%d", res);
    return 0;
}