#include <stdio.h>

/*
문제 : N * M(N, M <= 20) 크기의 좌석에서 (1, 1)에 가까울 수록 큰 번호를 갖도록 좌석을 배정한다.
거리는 맨해튼 거리를 사용하고, 거리가 같은 지점끼리는 어떤 순서로 지정해도 된다. 테스트 케이스의 수 T는 400 이하다.

해결 방법 : 모든 좌석을 반복해서 확인하며 거리가 현재 확인중인 거리와 같은 경우 좌석을 배정하는 방법을 사용할 수 있다.

주요 알고리즘 : 구현, 구성적

출처 : RCC 2017Q2 A번
*/

int res[32][32];

int main(void) {
    int t, n, m, c;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d %d", &n, &m);
        c = n * m;
        for (int i = 0; i < n + m; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < m; k++) {
                    if (j + k == i) res[j][k] = c--;
                }
            }
        }
        if (c != 0) return 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                printf("%d ", res[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}