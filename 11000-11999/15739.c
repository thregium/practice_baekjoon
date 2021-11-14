#include <stdio.h>

/*
문제 : N * N(N <= 100) 크기의 행렬이 마방진의 성질을 만족하는 지 구한다. 모든 수는 N^2 이하의 자연수이다.

해결 방법 : 먼저 수가 중복하지는 않는지 확인하고 각 행, 열, 대각선의 합이 N * (N^2 + 1) / 2인지 확인한다.
둘 중 하나라도 만족하지 않으면 마방진이 아니다.

주요 알고리즘 : 구현

출처 : 한양대E 2018P 3번
*/

int chk[10240], mat[128][128];

int main(void) {
    int n, r = 1, s = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &mat[i][j]);
            if (chk[mat[i][j]]) r = 0;
            else chk[mat[i][j]] = 1;
        }
    }
    for (int i = 0; i < n; i++) {
        s = 0;
        for (int j = 0; j < n; j++) s += mat[i][j];
        if (s != n * (n * n + 1) / 2) r = 0;
        s = 0;
        for (int j = 0; j < n; j++) s += mat[j][i];
        if (s != n * (n * n + 1) / 2) r = 0;
    }
    s = 0;
    for (int i = 0; i < n; i++) s += mat[i][i];
    if (s != n * (n * n + 1) / 2) r = 0;
    s = 0;
    for (int i = 0; i < n; i++) s += mat[i][n - i - 1];
    if (s != n * (n * n + 1) / 2) r = 0;
    printf("%s", r ? "TRUE" : "FALSE");
    return 0;
}