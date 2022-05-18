#include <stdio.h>

/*
���� : ����

�ذ� ��� : �� ��ϵ��� �ִ��� ���� ����, �ٵ��� Ȯ���ϰ� �׸�ŭ ������� ���� �ݺ��Ѵ�.
�� �� ���� Ƣ��� �ٸ�ŭ ������� �ϳ��� ��Ͽ� ���� ��� �ൿ�� ������.
�̸� �ݺ��Ͽ� ������ ����� ������ ���� �ȴ�.

�ֿ� �˰��� : ����, �ùķ��̼�

��ó : �Ｚ SW ���� �׽�Ʈ
*/

int board[10][10];
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

int gethorline(void) {
    int res = 0, full;
    for (int i = 6; i < 10; i++) {
        full = 1;
        for (int j = 0; j < 4; j++) {
            if (!board[i][j]) full = 0;
        }
        if (full) {
            res++;
            for (int j = 0; j < 4; j++) board[i][j] = 0;
            for (int ii = i; ii >= 4; ii--) {
                for (int j = 0; j < 4; j++) {
                    board[ii][j] = board[ii - 1][j];
                }
            }
        }
    }
    return res;
}

void pushdown(int lcnt) {
    if (lcnt < 0) {
        lcnt = 0;
        for (int i = 5; i >= 4; i--) {
            for (int j = 0; j < 4; j++) {
                if (board[i][j]) lcnt = 6 - i;
            }
        }
    }
    for (int i = 9; i >= 6; i--) {
        for (int j = 0; j < 4; j++) {
            board[i][j] = board[i - lcnt][j];
        }
    }
    for (int i = 5; i >= 4; i--) {
        for (int j = 0; j < 4; j++) board[i][j] = 0;
    }
}

int getverline(void) {
    int res = 0, full;
    for (int i = 6; i < 10; i++) {
        full = 1;
        for (int j = 0; j < 4; j++) {
            if (!board[j][i]) full = 0;
        }
        if (full) {
            res++;
            for (int j = 0; j < 4; j++) board[j][i] = 0;
            for (int ii = i; ii >= 4; ii--) {
                for (int j = 0; j < 4; j++) {
                    board[j][ii] = board[j][ii - 1];
                }
            }
        }
    }
    return res;
}

void pushright(int lcnt) {
    if (lcnt < 0) {
        lcnt = 0;
        for (int i = 5; i >= 4; i--) {
            for (int j = 0; j < 4; j++) {
                if (board[j][i]) lcnt = 6 - i;
            }
        }
    }
    for (int i = 9; i >= 6; i--) {
        for (int j = 0; j < 4; j++) {
            board[j][i] = board[j][i - lcnt];
        }
    }
    for (int i = 5; i >= 4; i--) {
        for (int j = 0; j < 4; j++) board[j][i] = 0;
    }
}

int main(void) {
    int n, t, x, y, xl, yl, score = 0, tscore;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d %d", &t, &x, &y);
        xl = x;
        for (int j = x + 1; j < 10; j++) {
            if (board[j][y]) break;
            if (t == 2 && board[j][y + 1]) break;
            xl = j;
        }
        board[xl][y] = i;
        if (t == 2) board[xl][y + 1] = i;
        if (t == 3) board[xl - 1][y] = i;
        yl = y;
        for (int j = y + 1; j < 10; j++) {
            if (board[x][j]) break;
            if (t == 3 && board[x + 1][j]) break;
            yl = j;
        }
        board[x][yl] = i;
        if (t == 2) board[x][yl - 1] = i;
        if (t == 3) board[x + 1][yl] = i;

        tscore = 1;
        while (tscore) {
            tscore = gethorline();
            score += tscore;
        }
        pushdown(-1);

        tscore = 1;
        while (tscore) {
            tscore = getverline();
            score += tscore;
        }
        pushright(-1);
    }
    printf("%d\n", score);
    tscore = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tscore += (!!board[i][j]);
        }
    }
    printf("%d", tscore);
    return 0;
}