#include <stdio.h>
#include <vector>
using namespace std;

/*
문제 : 두 사람이 H * W(H * W <= 250000) 크기의 보드에서 connect-k(k <= small(H, W)) 게임을 한다.
두 사람이 핀을 놓은 위치 H * W개가 주어질 때, 먼저 이긴 사람이 있는지 확인하고 있다면 그 사람과 몇 번째 턴인지 구한다.

해결 방법 : 한 사람이 이겼다면 그 이후로도 계속 K개 이상의 핀이 연속된 상태로 남아있을 것이다.
따라서, 이분 탐색을 통해 처음으로 K개 이상의 핀이 연속된 때를 찾으면 그 때의 턴과 그 턴인 사람이 답이다.
단, 이 전에 모든 핀이 채워진 상태에서 핀이 연속되었는지 확인해서 연속되지 않았다면 비긴 상태이므로 미리 경우에서 제외해야 한다.

주요 알고리즘 : 구현, 이분탐색, 시뮬레이션

출처 : GCPC 2020 G번
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
    scanf("%d %d %d", &h, &w, &k);
    for (int i = 0; i < h * w; i++) {
        scanf("%d", &a[i]);
        //a[i] = i / h + 1;
    }
    if (connect_check(h, w, k, h * w) == 0) {
        printf("D");
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
    printf("%c %d", (lo & 1) ? 'A' : 'B', lo);
    return 0;
}