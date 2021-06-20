#include <stdio.h>

/*
���� : M * N(M, N <= 50) ũ���� ������ �� ���� �� ���°� �־��� ��, ���� ������ ���� ū ���� ũ��, ���� �ϳ� �㹰���� ���� ���� ū ���� ũ�⸦ ���Ѵ�.
��, ���� �ּ� 2�� �̻� �ִ�.

�ذ� ��� : ��� ����� ���ʷ� Ȯ���ϸ� ���� Ž������ ���� ���� �ִ� ��� �ش� �濡�� �÷������� �����Ѵ�.
�÷������� �����ϸ� ���� ���� ��� �ش� ���� ��ȣ�� ����ϰ�, �ش� ���� ũ�⸦ 1 �ø���. �̸� �ݺ��� ��� �濡 ���� ó���ϸ�
���� ������ ���� ū ���� ũ�⸦ ���� �� �ְ�, ��� ������ �� �濡 ���� ���� �ٸ� �濡 ���ϴ� ��� �� ���� ũ���� ���� ���� Ȯ���ϸ�
���� �ϳ� �㹰���� ���� ���� ū ���� ũ�⵵ ���� �� �ִ�.

�ֿ� �˰��� : �׷��� �̷�, �÷�����, ���Ʈ ����

��ó : IOI 1994 2��
*/

int castle[64][64], rooms[64][64], size[4096];
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
int m, n, rc = 0, biggest = 0, bigroom = 0;

int isvalid(int x, int y, int d) {
    if (x < 0 || y < 0 || x >= m || y >= n) return 0;
    if (rooms[x][y] || (castle[x][y] & (1 << d))) return 0; //���� �� ���°� ��Ʈ����ŷ ���·� �־����Ƿ� �̵��� ĭ�� �������� ��Ʈ ���·� Ȯ�� �����ϴ�.
    return 1;
}

void fillroom(int x, int y) {
    size[rc]++;
    rooms[x][y] = rc;
    for (int i = 0; i < 4; i++) {
        if (!isvalid(x + dxy[i][0], y + dxy[i][1], i)) continue;
        fillroom(x + dxy[i][0], y + dxy[i][1]);
    }
}

int main(void) {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &castle[i][j]);
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (rooms[i][j] == 0) {
                rc++;
                fillroom(i, j);
                if (size[rc] > biggest) biggest = size[rc];
            }
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (rooms[i][j] != rooms[i][j - 1]) {
                if (size[rooms[i][j]] + size[rooms[i][j - 1]] > bigroom) bigroom = size[rooms[i][j]] + size[rooms[i][j - 1]];
            }
        }
    }
    for (int i = 1; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (rooms[i][j] != rooms[i - 1][j]) {
                if (size[rooms[i][j]] + size[rooms[i - 1][j]] > bigroom) bigroom = size[rooms[i - 1][j]] + size[rooms[i][j]];
            }
        }
    }
    printf("%d\n%d\n%d", rc, biggest, bigroom);
    return 0;
}