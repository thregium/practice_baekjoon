#include <stdio.h>

/*
문제 : N * N(N <= 1000) 행렬이 있다. 이 행렬은 N개의 음이 아닌 정수(<= 10^9)의 각 값끼리 AND한 결과라 할 때,
단, A_ii = 0, 원래의 값으로 될 수 있는 것을 구한다.

해결 방법 : 각 행마다 모든 값에 OR 연산을 한 것이 원래의 값이 될 수 있다.

주요 알고리즘 : 수학

출처 : COCI 15/16#4 3번
*/

int a[1024][1024], r[1024];

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            r[i] |= a[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", r[i]);
    }
    return 0;
}