#include <stdio.h>

/*
문제 : 6 * 6 크기의 스도쿠가 제대로 되었는 지 구한다.

해결 방법 : 각 묶음마다 1에서 6 사이 수가 1번씩만 들어가는 지 확인하면 된다.
다른 수가 들어오는 경우는 미리 처리한다. 대각선도 확인하는 것을 잊지 않는다.

주요 알고리즘 : 구현

출처 : Khwarizmi 2010 E번
*/

int sdk[6][6], chk[6];

int valid(void) {
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            if (sdk[i][j] < 1 || sdk[i][j] > 6) return 0;
        }
    }
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) chk[j] = 0;
        for (int j = 0; j < 6; j++) chk[sdk[i][j] - 1]++;
        for (int j = 0; j < 6; j++) {
            if (chk[j] != 1) return 0;
        }
    }
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) chk[j] = 0;
        for (int j = 0; j < 6; j++) chk[sdk[j][i] - 1]++;
        for (int j = 0; j < 6; j++) {
            if (chk[j] != 1) return 0;
        }
    }
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) chk[j] = 0;
        for (int j = 0; j < 6; j++) chk[sdk[i / 2 * 2 + j / 3][i % 2 * 3 + j % 3] - 1]++;
        for (int j = 0; j < 6; j++) {
            if (chk[j] != 1) return 0;
        }
    }
    for (int j = 0; j < 6; j++) chk[j] = 0;
    for (int j = 0; j < 6; j++) chk[sdk[j][j] - 1]++;
    for (int j = 0; j < 6; j++) {
        if (chk[j] != 1) return 0;
    }
    for (int j = 0; j < 6; j++) chk[j] = 0;
    for (int j = 0; j < 6; j++) chk[sdk[j][5 - j] - 1]++;
    for (int j = 0; j < 6; j++) {
        if (chk[j] != 1) return 0;
    }

    return 1;
}

int main(void) {
    int t;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 6; j++) {
                scanf("%d", &sdk[i][j]);
            }
        }
        printf("Case#%d: %d\n", tt, valid());
    }
    return 0;
}