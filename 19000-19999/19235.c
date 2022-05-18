#include <stdio.h>

int board[10][10];
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

void falldown(void) {
    int res = 1;
    while (res) {
        res = 0;
        for (int i = 4; i < 9; i++) {
            for (int j = 0; j < 4; j++) {
                if (!board[i][j]) continue;
                if (board[i + 1][j]) continue;
                if (board[i][j + 1] == board[i][j]) {
                    if (board[i + 1][j + 1]) continue;
                    else {
                        board[i + 1][j + 1] = board[i][j + 1];
                        board[i + 1][j] = board[i][j];
                        board[i][j] = 0;
                        board[i][j + 1] = 0;
                    }
                }
                else if (j > 0 && board[i][j - 1] == board[i][j]) {
                    if (board[i + 1][j - 1]) continue;
                    else {
                        board[i + 1][j - 1] = board[i][j - 1];
                        board[i + 1][j] = board[i][j];
                        board[i][j] = 0;
                        board[i][j - 1] = 0;
                    }
                }
                else if (board[i][j] == board[i - 1][j]) {
                    board[i + 1][j] = board[i][j];
                    board[i - 1][j] = 0;
                }
                else {
                    board[i + 1][j] = board[i][j];
                    board[i][j] = 0;
                }
                res = 1;
            }
        } 
    }
}

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
        }
    }
    return res;
}

void pushdown(void) {
    int lcnt = 0;
    for (int i = 5; i >= 4; i--) {
        for (int j = 0; j < 4; j++) {
            if (board[i][j]) lcnt = 6 - i;
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


void fallright(void) {
    int res = 1;
    while (res) {
        res = 0;
        for (int i = 4; i < 9; i++) {
            for (int j = 0; j < 4; j++) {
                if (!board[j][i]) continue;
                if (board[j][i + 1]) continue;
                if (board[j + 1][i] == board[j][i]) {
                    if (board[j + 1][i + 1]) continue;
                    else {
                        board[j + 1][i + 1] = board[j + 1][i];
                        board[j][i + 1] = board[j][i];
                        board[j][i] = 0;
                        board[j + 1][i] = 0;
                    }
                }
                else if (j > 0 && board[j - 1][i] == board[j][i]) {
                    if (board[j - 1][i + 1]) continue;
                    else {
                        board[j - 1][i + 1] = board[j - 1][i];
                        board[j][i + 1] = board[j][i];
                        board[j][i] = 0;
                        board[j - 1][i] = 0;
                    }
                }
                else if (board[j][i] == board[j][i - 1]) {
                    board[j][i + 1] = board[j][i];
                    board[j][i - 1] = 0;
                }
                else {
                    board[j][i + 1] = board[j][i];
                    board[j][i] = 0;
                }
                res = 1;
            }
        }
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
        }
    }
    return res;
}

void pushright(void) {
    int lcnt = 0;
    for (int i = 5; i >= 4; i--) {
        for (int j = 0; j < 4; j++) {
            if (board[j][i]) lcnt = 6 - i;
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
    int n, t, x, y, score = 0, tscore;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d %d", &t, &x, &y);
        board[5][y] = i;
        if (t == 2) board[5][y + 1] = i;
        if (t == 3) board[4][y] = i;
        board[x][5] = i;
        if (t == 2) board[x][4] = i;
        if (t == 3) board[x + 1][5] = i;

        tscore = 1;
        while (tscore) {
            falldown();
            tscore = gethorline();
            score += tscore;
        }
        pushdown();

        tscore = 1;
        while (tscore) {
            fallright();
            tscore = getverline();
            score += tscore;
        }
        pushright();
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