#include <stdio.h>

/*
문제 : M * N(M, N <= 1000) 크기의 'J', 'O', 'I'로 이루어진 지도가 주어질 때, 이 지도에서 K(K <= 100000)개의 범위가 주어지면,
해당 범위의 'J', 'O', 'I'의 개수를 각각 구한다.

해결 방법 : 'J', 'O', 'I'의 2차원 누적 합을 각각 구한 다음, 2차원 누적 합을 이용해 각 범위들에 대한
'J', 'O', 'I'의 개수를 각각 구하면 된다.

주요 알고리즘 : 누적 합

출처 : JOI 2011 1번
*/

char s[1024][1024];
int sum[3][1024][1024];

int main(void) {
    int m, n, k, a, b, c, d;
    scanf("%d %d%d", &m, &n, &k);
    for (int i = 1; i <= m; i++) {
        scanf("%s", s[i] + 1);
        for (int j = 1; j <= n; j++) {
            if (s[i][j] == 'J') sum[0][i][j] = 1;
            else if (s[i][j] == 'O') sum[1][i][j] = 1;
            else if (s[i][j] == 'I') sum[2][i][j] = 1;
            else return 1;
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 1; j <= m; j++) {
            for (int k = 1; k <= n; k++) {
                sum[i][j][k] += sum[i][j][k - 1];
            }
        }
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= m; k++) {
                sum[i][k][j] += sum[i][k - 1][j];
            }
        }
    }
    for (int i = 0; i < k; i++) {
        scanf("%d %d %d %d", &a, &b, &c, &d);
        for (int j = 0; j < 3; j++) {
            printf("%d ", sum[j][c][d] - sum[j][a - 1][d] - sum[j][c][b - 1] + sum[j][a - 1][b - 1]);
        }
        printf("\n");
    }
    return 0;
}