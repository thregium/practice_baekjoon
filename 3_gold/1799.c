#include <stdio.h>

/*
���� : �ִ� 10 * 10 ũ���� ü���ǰ� ����� ���� �� �ִ� ĭ���� �־��� ��, ���ΰ��� ���ݹ��� �ʰ� ����� �ִ��� ���� �� �ִ� ������ ����Ѵ�.

�ذ� ��� : ����� ���� ������ ĭ�鸸 ������ �� �ֱ� ������ ü������ �ΰ��� ������ �����Ѵ�. ���� ���� �� ĭ���� ����� ���� �� �ִ� ĭ���� ������ ����,
����� ���� ���� ���� �ʴ� ��츦 ������ ��Ʈ��ŷ�� �����Ѵ�. ���� ��ġ�� �ٸ� ���鿡�� ���ݹ޴� ��ġ�� ��� ���� ĭ������ ����� ���� �ʰ�,
���ݹ��� �ʴ� ��ġ�� ��� �� ������ ���� �����Ѵ�. ü������ ���� �����ϸ� �ִ��� �����Ѵ�. ���� ��ġ���� ������ ��� ĭ�� ����� ���Ƶ� �ִ񰪿� ������ �� ���ٸ� ���⿡ ������ �ð��� ������ �� �ִ�.

�ֿ� �˰��� : ��Ʈ��ŷ
*/

int board[16][16], odds[128], evens[128], chkln[2][16];
int oddi = 0, eveni = 0, maxo = 0, maxe = 0;
int n;

int big(int a, int b) {
    return a > b ? a : b;
}

void tracko(int p, int m) {
    if (p == oddi) {
        maxo = big(maxo, m);
        return;
    }
    if (oddi - p < maxo - m) return;
    int x = odds[p] / n, y = odds[p] % n;
    if (!chkln[0][(x + y - 1) / 2] && !chkln[1][(n - (x - y)) / 2]) {
        chkln[0][(x + y - 1) / 2]++;
        chkln[1][(n - (x - y)) / 2]++;
        tracko(p + 1, m + 1);
        chkln[0][(x + y - 1) / 2]--;
        chkln[1][(n - (x - y)) / 2]--;
    }
    tracko(p + 1, m);
}

void tracke(int p, int m) {
    if (p == eveni) {
        maxe = big(maxe, m);
        return;
    }
    if (eveni - p < maxe - m) return;
    int x = evens[p] / n, y = evens[p] % n;
    if (!chkln[0][(x + y) / 2] && !chkln[1][(n - 1 - (x - y)) / 2]) {
        chkln[0][(x + y) / 2]++;
        chkln[1][(n - 1 - (x - y)) / 2]++;
        tracke(p + 1, m + 1);
        chkln[0][(x + y) / 2]--;
        chkln[1][(n - 1 - (x - y)) / 2]--;
    }
    tracke(p + 1, m);
}

int main(void) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &board[i][j]);
            if (board[i][j]) {
                if ((i + j) % 2) odds[oddi++] = i * n + j;
                else evens[eveni++] = i * n + j;
            }
        }
    }
    tracko(0, 0);
    tracke(0, 0);
    printf("%d", maxo + maxe);
    return 0;
}