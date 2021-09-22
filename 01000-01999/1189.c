#include <stdio.h>

/*
���� : R * C(R, C <= 5) ũ���� ���ڿ��� ���� �Ʒ����� ������ ������ 'T'�� �κ��� ������ �ʰ�
���� ĭ�� 2�� �̻� ������ �ʴ� ���� K(K <= 25)�� ��� ������ ���Ѵ�.

�ذ� ��� : R�� C�� �۱� ������ ��Ʈ��ŷ�� �̿��� ��� ��츦 �غ� �� �ִ�. �� �������� �̵��ϸ� ������ ���� ǥ���ϰ�,
�̵��� ���� ���ٸ� ������ ĭ�� ����� ���� ĭ���� ���� Ž���ϴ� ����̴�.

�ֿ� �˰��� : ���Ʈ ����, ��Ʈ��ŷ

��ó : USACO 2009J B2��
*/

char map[8][8], chk[8][8];
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
int r, c, k, res = 0;

int isvalid(int x, int y) {
    if (x < 0 || y < 0 || x >= r || y >= c) return 0;
    if (chk[x][y] || map[x][y] == 'T') return 0;
    return 1;
}

void track(int x, int y, int d) {
    if (x == 0 && y == c - 1) {
        if (d == k) res++;
        return;
    }
    chk[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        if (isvalid(x + dxy[i][0], y + dxy[i][1])) track(x + dxy[i][0], y + dxy[i][1], d + 1);
    }
    chk[x][y] = 0;
}

int main(void) {
    scanf("%d %d %d", &r, &c, &k);
    for (int i = 0; i < r; i++) {
        scanf("%s", map[i]);
    }
    track(r - 1, 0, 1);
    printf("%d", res);
    return 0;
}