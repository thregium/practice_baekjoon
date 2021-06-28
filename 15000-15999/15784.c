#include <stdio.h>

/*
문제 : N * N 크기의 격자에서 A행 B열의 원소와 같은 행이나 열에 해당 원소보다 큰 원소가 있는지 구한다.

해결 방법 : 2차원 배열에 모든 원소를 받은 후 같은 행과 열의 원소를 확인해 더 큰 원소의 여부를 구하면 된다.

주요 알고리즘 : 구현

출처 : 인하대 E번
*/

int x[1024][1024];

int main(void) {
    int n, a, b, r = 1;
    scanf("%d %d %d", &n, &a, &b);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &x[i][j]);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (x[a][i] > x[a][b] || x[i][b] > x[a][b]) r = 0;
    }
    printf("%s", r ? "HAPPY" : "ANGRY");
    return 0;
}