#include <stdio.h>

/*
문제 : N * N(N <= 10) 크기의 비트맵을 가로세로로 K(K <= 10)배씩 늘린 결과를 출력한다.

해결 방법 : 다중 반복문을 이용한다.

주요 알고리즘 : 구현

출처 : 중앙대 2020 A번
*/

int btm[16][16];

int main(void) {
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &btm[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int ii = 0; ii < k; ii++) {
            for (int j = 0; j < n; j++) {
                for (int jj = 0; jj < k; jj++) {
                    printf("%d ", btm[i][j]);
                }
            }
            printf("\n");
        }
    }
    return 0;
}