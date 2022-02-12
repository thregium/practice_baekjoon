#include <stdio.h>

/*
���� : R * C(R, C <= 2000) ũ���� �濡�� �κ� û�ұ��� �̵� ����� �־��� ��,
�κ� û�ұⰡ �̵��� �� �ִ� ĭ�� ������ ���Ѵ�. �̵� ����� 2000�� ������ '^', 'v', '<', '>'�� �̷����
���ڿ��� �־�����, ���ʺ��� ������� �ش� �������� ��('#')�� ���� �� ���� �̵��Ѵ�.

�ذ� ��� : �κ� û�ұ��� ��ġ�� ã�� ���� �� �������� ���� ���� �� ���� �ݺ��� ������
�κ� û�ұ⸦ �̵����� ������. �κ� û�ұⰡ �̵��� �� �ִ� ĭ���� ���� ����� ����,
�� ĭ���� ������ ���� ���� ���ϸ� �ȴ�.

�ֿ� �˰��� : ����, �ùķ��̼�

��ó : SwOI 2021O B��
*/

char room[2048][2048], inst[2048];

int main(void) {
    int r, c, n, x = -1, y = -1, res = 0;
    scanf("%d %d %d", &r, &c, &n);
    scanf("%s", inst);
    for (int i = 0; i < r; i++) {
        scanf("%s", room[i]);
        for (int j = 0; j < c; j++) {
            if (room[i][j] == 'O') {
                room[i][j] = '*';
                x = i, y = j;
            }
        }
    }
    if (x < 0) return 1;
    for (int i = 0; i < n; i++) {
        if (inst[i] == '^') {
            while (room[x - 1][y] != '#') room[--x][y] = '*';
        }
        else if (inst[i] == 'v') {
            while (room[x + 1][y] != '#') room[++x][y] = '*';
        }
        else if (inst[i] == '<') {
            while (room[x][y - 1] != '#') room[x][--y] = '*';
        }
        else if (inst[i] == '>') {
            while (room[x][y + 1] != '#') room[x][++y] = '*';
        }
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            res += (room[i][j] == '*');
        }
    }
    printf("%d", res);
    return 0;
}