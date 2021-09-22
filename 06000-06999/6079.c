#include <stdio.h>

/*
���� : N * N(N <= 30) ũ���� üĿ �ǿ� �ڽ��� ����('K')�� ����� ����('o')�� �ִ�. ����� ������ ��� ��� �����
�����ϰ� �����Ѵٰ� �� ��, �� ����� ���Ѵ�. �� �� �ִ� ĭ�� '+', �� �� ���� ĭ�� '-'�� �־�����, ������ �밢�����θ�
������ �� �ִ�.

�ذ� ��� : ���� ����� �� ������ �� ����, ��� �ڽ��� ���鿡 ���ؼ� ��Ʈ��ŷ�� ���� ������ ��� ��� ����� ã�´�.
�밢�� �������� 2ĭ�� �����̸� ����� ���� �ִ��� Ȯ���� ����, �����ִٸ� �� ���� ����� �װ����� �̵��ϸ� �ȴ�.
�̵��ϴ� ĭ�� �翬�� �� ĭ�̾�� �Ѵ�.
����� ��� ���� �������� Ȯ�εȴٸ� �׶����� ������ ��θ� ����ϰ� ���α׷��� �����ϸ� �ȴ�.

�ֿ� �˰��� : ����, ��Ʈ��ŷ

��ó : USACO 2008D B1��
*/

char board[32][32], vis[32][32];
int mvs[1024][2];
int dxy[4][2] = { {2, 2}, {2, -2}, {-2, -2}, {-2, 2} };
int n, fin = 0;

int isvalid(int x, int y, int d) {
    if (x < 0 || y < 0 || x >= n || y >= n) return 0;
    if (board[x][y] != '+' || board[x + (dxy[d ^ 2][0] >> 1)][y + (dxy[d ^ 2][1] >> 1)] != 'o') return 0;
    if (vis[x + (dxy[d ^ 2][0] >> 1)][y + (dxy[d ^ 2][1] >> 1)]) return 0;
    return 1;
}

void track(int o, int op, int x, int y) {
    if (o == op) {
        fin = 1;
        for (int i = 0; i < o; i++) {
            printf("%d %d\n", mvs[i][0], mvs[i][1]);
        }
        printf("%d %d", x + 1, y + 1);
        return;
    }

    mvs[op][0] = x + 1;
    mvs[op][1] = y + 1;
    for (int i = 0; i < 4; i++) {
        if (isvalid(x + dxy[i][0], y + dxy[i][1], i)) {
            vis[x + (dxy[i][0] >> 1)][y + (dxy[i][1] >> 1)] = 1;
            track(o, op + 1, x + dxy[i][0], y + dxy[i][1]);
            vis[x + (dxy[i][0] >> 1)][y + (dxy[i][1] >> 1)] = 0;
        }
    }
}

int main(void) {
    int o = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", board[i]);
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 'o') o++;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 'K') {
                track(o, 0, i, j);
                if (fin) return 0;
            }
        }
    }
    if (!fin) printf("impossible");
    return 0;
}