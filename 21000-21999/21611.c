#include <stdio.h>
#include <assert.h>

/*
문제 : N * N(3 <= N < 50, N은 홀수) 크기의 격자에 소용돌이 모양으로 구슬들이 놓여 있다.
구슬들에 문제에 주어진 연산(생략)들을 하여 나온 폭발한 구슬의 개수의 수에 각 구슬의 번호를 곱하여
더한 값을 출력한다.

해결 방법 : 각 소용돌이의 번째 수를 미리 전처리를 통해 구해둔다.
그 값을 이용하여 소용돌이가 떨어지는 것을 간단히 처리 가능하며, 폭발과 변환도 쉽게 할 수 있다.
단, 이 과정에서 실수하지 않도록 주의한다.

주요 알고리즘 : 구현, 시뮬레이션

출처 : 삼성 SW 역량 테스트
*/

int marb[64][64], ord[64][64], rord[2560][2], tmpmarb[2560];
int dxy1[4][2] = { {0, -1}, {1, 0}, {0, 1}, {-1, 0} };
int dxy2[5][2] = { {0, 0}, {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

void makeord(int n) {
    int x = n >> 1;
    int y = n >> 1;
    int d = 0, cnt = 0;
    for (int i = 0; i < n * n; i++) {
        ord[x][y] = i;
        rord[i][0] = x;
        rord[i][1] = y;
        x += dxy1[d & 3][0];
        y += dxy1[d & 3][1];
        cnt++;
        if (cnt > (d >> 1)) {
            cnt = 0;
            d++;
        }
    }
}

void blizz(int n, int d, int s) {
    int x = n >> 1;
    int y = n >> 1;
    for (int i = 1; i <= s; i++) {
        marb[x + dxy2[d][0] * i][y + dxy2[d][1] * i] = 0;
    }
}

void fallmarb(int n) {
    int lst = 1;
    for (int i = 1; i < n * n; i++) {
        if (marb[rord[i][0]][rord[i][1]]) {
            marb[rord[lst][0]][rord[lst][1]] = marb[rord[i][0]][rord[i][1]];
            lst++;
        }
    }
    for (int i = lst; i < n * n; i++) {
        marb[rord[i][0]][rord[i][1]] = 0;
    }
}

int explode(int n) {
    int res = 0, cnt = 0;
    for (int i = 1; i < n * n; i++) {
        if (marb[rord[i][0]][rord[i][1]] == marb[rord[i - 1][0]][rord[i - 1][1]]) cnt++;
        else {
            if (cnt >= 4) {
                res += marb[rord[i - 1][0]][rord[i - 1][1]] * cnt;
                for (int j = i - 1; j >= i - cnt; j--) marb[rord[j][0]][rord[j][1]] = 0;
            }
            cnt = 1;
        }
    }
    if (cnt >= 4) {
        res += marb[rord[n * n - 1][0]][rord[n * n - 1][1]] * cnt;
        for (int j = n * n - 1; j >= n * n - cnt; j--) marb[rord[j][0]][rord[j][1]] = 0;
    }
    return res;
}

void tfmarb(int n) {
    int tmplen = 1, concnt = 1;
    for (int i = 2; i < n * n; i++) {
        if (marb[rord[i][0]][rord[i][1]] == marb[rord[i - 1][0]][rord[i - 1][1]]) concnt++;
        else {
            assert(concnt <= 3);
            tmpmarb[tmplen++] = concnt;
            tmpmarb[tmplen++] = marb[rord[i - 1][0]][rord[i - 1][1]];
            concnt = 1;
        }
        if (tmplen >= n * n) break;
    }
    for (int i = 1; i < tmplen && i < n * n; i++) {
        marb[rord[i][0]][rord[i][1]] = tmpmarb[i];
    }
    for(int i = tmplen; i < n * n; i++) marb[rord[i][0]][rord[i][1]] = 0;
}

int main(void) {
    int n, m, d, s, score = 0, tscore = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &marb[i][j]);
        }
    }
    makeord(n);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &d, &s);
        blizz(n, d, s);
        tscore = 1;
        while (tscore) {
            fallmarb(n);
            tscore = explode(n);
            score += tscore;
        }
        tfmarb(n);
    }
    printf("%d", score);
    return 0;
}