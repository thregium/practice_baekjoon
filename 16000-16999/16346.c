#include <stdio.h>

/*
문제 : N(N <= 300000)명의 경비원이 좌표평면상에 있다. 각 경비원의 위치는 0 이상 5000 이하의 정수이다.
이때, Q(Q <= 300000)개의 지점에서 경비원으로의 가장 가까운 거리를 구한다.
각 경비원은 상하좌우대각선으로 이동 가능하다.

해결 방법 : 각 경비원의 거리마다 도달 가능한 형태를 확인하면 정사각형 형태가 된다.
따라서, 각 경비원의 2차원 누적 합을 만든 다음, 각 쿼리마다 0부터 5000 사이의 값에 대해 이분 탐색으로
경비원이 있는 가장 작은 거리를 구하는 방식으로 O(Q*log(MaxX))의 시간에 답을 찾을 수 있다.
상수가 크기 때문에 주의한다.

주요 알고리즘 : 누적 합, 파라메트릭

출처 : CTU 2018 S번
*/

int psum[5120][5120];

int getsum(int x1, int y1, int x2, int y2) {
    if (x1 == 0) {
        if (y1 == 0) return psum[x2][y2];
        else return psum[x2][y2] - psum[x2][y1 - 1];
    }
    else {
        if (y1 == 0) return psum[x2][y2] - psum[x1 - 1][y2];
        else return psum[x2][y2] - psum[x1 - 1][y2] - psum[x2][y1 - 1] + psum[x1 - 1][y1 - 1];
    }
}

int main(void) {
    int n, q, x, y, xl, yl, xh, yh, lo, hi, mid;
    scanf("%d %d", &n, &q);
    for (int i = 0; i < n; i++) {
        scanf("%d  %d", &x, &y);
        psum[x][y]++;
    }
    for (int i = 0; i <= 5000; i++) {
        for (int j = 1; j <= 5000; j++) psum[i][j] += psum[i][j - 1];
    }
    for (int i = 0; i <= 5000; i++) {
        for (int j = 1; j <= 5000; j++) psum[j][i] += psum[j - 1][i];
    }
    for (int i = 0; i < q; i++) {
        scanf("%d %d", &x, &y);
        lo = 0, hi = 5000;
        while (lo < hi) {
            mid = (lo + hi) >> 1;
            xl = x - mid, yl = y - mid, xh = x + mid, yh = y + mid;
            if (xl < 0) xl = 0;
            if (yl < 0) yl = 0;
            if (xh > 5000) xh = 5000;
            if (yh > 5000) yh = 5000;
            if (getsum(xl, yl, xh, yh)) hi = mid;
            else lo = mid + 1;
        }
        printf("%d\n", lo);
    }
    return 0;
}