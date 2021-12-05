#include <stdio.h>

/*
���� : N * N(N <= 4) ũ���� �ǿ��� ��ֹ��� ��ġ�� �־��� ��, ���� ���� ���ݹް� ���� ������ �ִ� �� ������
��ġ �������� ���Ѵ�. ��ֹ��� �ִ� ĭ���� ���� ���� �� ����, �� ����� ��ֹ��� ���� �� ����.

�ذ� ��� : ��Ʈ��ŷ�� ���� ����� ���� ����. ���� �� ĭ���� ���ʷ� ����� ������ ���ݹ��� �ʴ� ��� ��ġ ���
���� ���� ���� ��ġ�ϴ� ��츦 ���ϸ� �ȴ�.

�ֿ� �˰��� : ���Ʈ ����, ��Ʈ��ŷ

��ó : MidC 1998 C�� // CTUF 2003 G��
*/

char board[8][8];
int best = 0;

void track(int n, int x, int y, int c) {
    if (x == n) {
        if (c > best) best = c;
        return;
    }
    int v = 1;
    if (board[x][y] == 'X') v = 0;
    for (int i = x + 1; i < n; i++) {
        if (board[i][y] == 'X') break;
        if (board[i][y] == '#') v = 0;
    }
    for (int i = x - 1; i >= 0; i--) {
        if (board[i][y] == 'X') break;
        if (board[i][y] == '#') v = 0;
    }
    for (int i = y + 1; i < n; i++) {
        if (board[x][i] == 'X') break;
        if (board[x][i] == '#') v = 0;
    }
    for (int i = y - 1; i >= 0; i--) {
        if (board[x][i] == 'X') break;
        if (board[x][i] == '#') v = 0;
    }
    if (v) {
        board[x][y] = '#';
        track(n, y == n - 1 ? x + 1 : x, y == n - 1 ? 0 : y + 1, c + 1);
        board[x][y] = '.';
    }
    track(n, y == n - 1 ? x + 1 : x, y == n - 1 ? 0 : y + 1, c);
}

int main(void) {
    int n;
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        for (int i = 0; i < n; i++) {
            scanf("%s", board[i]);
        }
        best = 0;
        track(n, 0, 0, 0);
        printf("%d\n", best);
    }
    return 0;
}