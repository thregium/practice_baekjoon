#include <stdio.h>

/*
문제 : R * C(R, C <= 1000) 크기의 격자에서 각 칸마다 밝기(<= 1000, 자연수)가 주어진다.
Q(Q <= 100000)개의 직사각형 범위에 대해 밝기 평균을 각각 구한다. 소숫점 아래는 버림한다.

해결 방법 : 2차원 누적 합을 통해 밝기 합을 구한 다음 넓이로 나누어 평균을 구하면 된다.

주요 알고리즘 : 누적 합

출처 : 충남대 2회 E번
*/

int psum[1024][1024];

int getsum(int x1, int y1, int x2, int y2) {
    return psum[x2][y2] - psum[x1 - 1][y2] - psum[x2][y1 - 1] + psum[x1 - 1][y1 - 1];
}

int main(void) {
    int r, c, q, x1, y1, x2, y2;
    scanf("%d %d %d", &r, &c, &q);
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            scanf("%d", &psum[i][j]);
            psum[i][j] += psum[i][j - 1];
        }
    }
    for (int i = 1; i <= c; i++) {
        for (int j = 1; j <= r; j++) psum[j][i] += psum[j - 1][i];
    }
    for (int i = 0; i < q; i++) {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        printf("%d\n", getsum(x1, y1, x2, y2) / ((x2 - x1 + 1) * (y2 - y1 + 1)));
    }
    return 0;
}