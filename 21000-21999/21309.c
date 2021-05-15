#include <stdio.h>

/*
문제 : R * C(R, C <= 1000) 크기의 지도가 주어질 때, 이 지도에서 가로 세로로 맞닿은 곳과 대각선으로 맞닿은 곳의 수를 각각 구한다.

해결 방법 : 각 개수들을 각각 세면 된다.

주요 알고리즘 : 구현

출처 : GNY 2020 J번
*/

int land[1024][1024];

int main(void) {
    int r, c, ca = 0, ic = 0;
    scanf("%d %d", &r, &c);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", &land[i][j]);
        }
    }
    for (int i = 0; i < r; i++) {
        for (int j = 1; j < c; j++) {
            if (land[i][j] && land[i][j - 1]) {
                //가로
                ca++;
                ic++;
            }
        }
    }
    for (int i = 1; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (land[i][j] && land[i - 1][j]) {
                //세로
                ca++;
                ic++;
            }
        }
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (land[i][j] && land[i + 1][j + 1]) ic++; //대각(\)
        }
    }
    for (int i = 0; i < r; i++) {
        for (int j = 1; j < c; j++) {
            if (land[i][j] && land[i + 1][j - 1]) ic++; //대각(/)
        }
    }

    printf("%d %d", ca, ic);
    return 0;
}