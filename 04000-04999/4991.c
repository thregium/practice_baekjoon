#include <stdio.h>
#define INF 103000

/*
���� : H * W(H, W <= 20) ũ���� �濡 �����¿�� �̵� ������ �κ� û�ұ�� 10�� ������ ������ ĭ�� �ִ�.
��� ������ ĭ�� ġ��� ���� �κ� û�ұⰡ �̵��ϱ� ���� �ʿ��� �ּ� �̵� Ƚ���� ���Ѵ�. ���� ġ�� �� ���ٸ� -1�� ����Ѵ�.

�ذ� ��� : ���� ũ�Ⱑ ũ�� �ʱ� ������ �÷��̵�-���� �˰����� ���� ���� ��� ���� ������ �Ÿ��� ���� �� �ְ�,
�׸� �̿��� ���Ʈ ������ �ϸ� �ּ� �̵� ȸ���� ���´�.
���� ������ ���� �ƴ� ��� �̵� �����ϹǷ� �Ÿ��� 1�� �������� �̾��� ���� �÷��̵�-������ �ϸ� �Ÿ��� ���´�.
���Ʈ ������ ��͸� ���� ��� ������ �˻����ָ� �ȴ�.

�ֿ� �˰��� : �׷��� �̷�, �÷��̵�-����, ���Ʈ ����

��ó : JDC 2005 F��
*/

char room[32][32];
int dist[512][512], dust[16][2], chk[16];
int dc, best;

void track(int c, int w, int x, int y, int r) {
    if (c == dc) {
        if (r < best) best = r;
        return;
    }

    for (int i = 0; i < dc; i++) {
        if (chk[i]) continue;
        chk[i] = 1;
        track(c + 1, w, dust[i][0], dust[i][1], r + dist[x * w + y][dust[i][0] * w + dust[i][1]]);
        chk[i] = 0;
    }
}

int main(void) {
    int w, h, x, y;
    //freopen("E:\\PS\\ICPC\\Asia Pacific\\Japan Domestic\\2005\\INPUT\\F1.txt", "r", stdin);
    while (1) {
        scanf("%d %d", &w, &h);
        x = -1, y = -1, dc = 0;
        for (int i = 0; i < h; i++) {
            scanf("%s", room[i]);
            for (int j = 0; j < w; j++) {
                if (room[i][j] == '*') {
                    dust[dc][0] = i;
                    dust[dc][1] = j;
                    dc++;
                }
                else if (room[i][j] == 'o') {
                    x = i;
                    y = j;
                }
            }
        }
        if (x < 0) return 1;

        for (int i = 0; i < h * w; i++) {
            for (int j = 0; j < h * w; j++) dist[i][j] = INF;
            dist[i][i] = 0;
        }
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w - 1; j++) {
                if (room[i][j] != 'x' && room[i][j + 1] != 'x') {
                    dist[i * w + j][i * w + j + 1] = 1;
                    dist[i * w + j + 1][i * w + j] = 1;
                }
            }
        }
        for (int i = 0; i < h - 1; i++) {
            for (int j = 0; j < w; j++) {
                if (room[i][j] != 'x' && room[i + 1][j] != 'x') {
                    dist[i * w + j][(i + 1) * w + j] = 1;
                    dist[(i + 1) * w + j][i * w + j] = 1;
                }
            }
        }
        for (int k = 0; k < h * w; k++) {
            for (int i = 0; i < h * w; i++) {
                if (dist[i][k] == INF) continue;
                for (int j = 0; j < h * w; j++) {
                    if (dist[i][k] + dist[k][j] < dist[i][j]) dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }

        best = INF;
        track(0, w, x, y, 0);
        printf("%d\n", best == INF ? -1 : best);
    }
    return 0;
}