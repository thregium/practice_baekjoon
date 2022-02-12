#include <stdio.h>

/*
���� : R * C(R, C <= 20) ũ���� �ǿ��� ���� �̵���Ų��. ���� �����¿�� �̵� �����ϸ�,
���� �ε��� �� ���� �̵��ϰ�, �ε��� ���� ������. �̶�, ���� ���� �ʰ� ���������� ���� �ʴ� ���
���� �Ҿ���� �����ϰ� �ȴ�. �������� ��´ٸ� ���� ���� �ʴ��� �����̴�.
�̶�, �־��� �ǿ��� ���� 10ȸ ���� ���ϴ� ��� �̵���Ű�� ���� ������ �� ���ϰ�,
������ ��� �ּ� �̵� Ƚ���� ���Ѵ�.

�ذ� ��� : 10ȸ���� �̵���Ű�� ����� 4^10������ ��� ��츦 ���캼 �� �ִ�.
����, ��� ��츦 ���캸���� �ϸ� ���� ������ �̵� ������ ���� ���� �ȴ�.
�� �������� �ʱ�ȭ�� �����Ѵ�.

�ֿ� �˰��� : ����, ���Ʈ ����, �ùķ��̼�

��ó : JDC 2006 D��
*/

int bd[32][32];
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
int r, c, res;

void track(int x, int y, int cnt) {
    int xn, yn;
    if (bd[x][y] == 3) {
        if (cnt < res) res = cnt;
        return;
    }
    if (cnt == 10) return;
    for (int d = 0; d < 4; d++) {
        xn = x, yn = y;
        while (xn >= 0 && yn >= 0 && xn < r && yn < c && bd[xn][yn] != 1) {
            xn += dxy[d][0];
            yn += dxy[d][1];
            if (bd[xn][yn] == 3 && cnt + 1 < res) res = cnt + 1;
        }
        if (xn >= 0 && yn >= 0 && xn < r && yn < c) {
            if (xn - dxy[d][0] != x || yn - dxy[d][1] != y) {
                bd[xn][yn] = 0;
                track(xn - dxy[d][0], yn - dxy[d][1], cnt + 1);
                bd[xn][yn] = 1;
            }
        }
    }
}

int main(void) {
    int xs = -1, ys = -1;
    while (1) {
        scanf("%d %d", &c, &r);
        if (r == 0) break;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                scanf("%d", &bd[i][j]);
                if (bd[i][j] == 2) {
                    xs = i;
                    ys = j;
                }
            }
        }
        res = 103000;
        track(xs, ys, 0);
        printf("%d\n", res == 103000 ? -1 : res);
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) bd[i][j] = 0;
        }
    }
    return 0;
}