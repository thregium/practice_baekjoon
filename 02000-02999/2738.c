#include <stdio.h>

/*
문제 : N * M(N, M <= 100) 크기의 두 행렬의 합을 출력한다.

해결 방법 : 행렬의 원소들을 각각 받은 뒤 더해서 출력하면 된다.

주요 알고리즘 : 구현, 사칙연산
*/

int a[128][128], b[128][128];

int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &b[i][j]);
            printf("%d ", a[i][j] + b[i][j]);
        }
        printf("\n");
    }
    return 0;
}