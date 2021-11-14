#include <stdio.h>

/*
문제 : 문제에 주어진 방법대로 N * N(N <= 300) 크기의 두 부울행렬에 대해 행렬곱을 구한다.

해결 방법 : 문제에 주어진대로 구현하면 된다. 비트 연산을 사용한다.

주요 알고리즘 : 구현

출처 : 선린 2017 F번
*/

int mata[384][384], matb[384][384], matc[384][384];

int main(void) {
    int n, r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &mata[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matb[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                matc[i][j] |= (mata[i][k] & matb[k][j]);
            }
            r += matc[i][j];
        }
    }
    printf("%d", r);
    return 0;
}