#include <stdio.h>
#include <vector>
using namespace std;

/*
문제 : Connect4 게임을 판이 가득 찰 때 까지 했을 때, 이긴 사람이 누구인지, 언제 이겼는지 구한다.

해결 방법 : 잘 구현한다.

주요 알고리즘 : 구현, 시뮬레이션

출처 : CHCI 2002RS 1번
*/

int a[256000];
vector<int> board[256000];

int connect_check(int h, int w, int k, int c) {
    int r = 0, tmp = 0;
    for (int i = 0; i < w; i++) {
        board[i].clear();
    }
    for (int i = 0; i < c; i++) {
        if (i & 1) board[a[i] - 1].push_back(1);
        else board[a[i] - 1].push_back(2);
    }
    for (int i = 0; i < w; i++) {
        while (board[i].size() < h) board[i].push_back(0);
    }
    for (int i = 0; i < w; i++) {
        for (int j = 0; j < h; j++) {
            if (board[i][j] == 0) tmp = 0;
            else if (j && board[i][j] == board[i][j - 1]) tmp++;
            else tmp = 1;
            if (tmp > r) r = tmp;
        }
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (board[j][i] == 0) tmp = 0;
            else if (j && board[j][i] == board[j - 1][i]) tmp++;
            else tmp = 1;
            if (tmp > r) r = tmp;
        }
    }
    if (h > w) {
        for (int i = -w; i <= h + w; i++) {
            for (int j = 0; j < w; j++) {
                if (i + j < 0 || i + j >= h) continue;
                if (board[j][i + j] == 0) tmp = 0;
                else if (j && i + j && board[j][i + j] == board[j - 1][i + j - 1]) tmp++;
                else tmp = 1;
                if (tmp > r) r = tmp;
            }
            for (int j = 0; j < w; j++) {
                if (i - j < 0 || i - j >= h) continue;
                if (board[j][i - j] == 0) tmp = 0;
                else if (j && i - j < h - 1 && board[j][i - j] == board[j - 1][i - j + 1]) tmp++;
                else tmp = 1;
                if (tmp > r) r = tmp;
            }
        }
    }
    else {
        for (int i = -h; i <= w + h; i++) {
            for (int j = 0; j < h; j++) {
                if (i + j < 0 || i + j >= w) continue;
                if (board[i + j][j] == 0) tmp = 0;
                else if (j && i + j && board[i + j][j] == board[i + j - 1][j - 1]) tmp++;
                else tmp = 1;
                if (tmp > r) r = tmp;
            }
            for (int j = 0; j < h; j++) {
                if (i - j < 0 || i - j >= w) continue;
                if (board[i - j][j] == 0) tmp = 0;
                else if (j && i - j < w - 1 && board[i - j][j] == board[i - j + 1][j - 1]) tmp++;
                else tmp = 1;
                if (tmp > r) r = tmp;
            }
        }
    }
    return (r >= k);
}

int main(void) {
    int h, w, k, lo, hi, cnt = 0;
    //scanf("%d %d %d", &h, &w, &k);
    h = 6, w = 7, k = 4;
    for (int i = 0; i < h * w; i++) {
        scanf("%d", &a[i]);
        //a[i] = i / h + 1;
    }
    if (connect_check(h, w, k, h * w) == 0) {
        printf("ss");
        return 0;
    }
    lo = 0, hi = h * w;
    while (lo < hi) {
        if (connect_check(h, w, k, (lo + hi) >> 1)) {
            hi = (lo + hi) >> 1;
        }
        else {
            lo = ((lo + hi) >> 1) + 1;
        }
        cnt++;
    }
    printf("%s %d", (lo & 1) ? "sk" : "ji", (lo + 1) >> 1);
    return 0;
}