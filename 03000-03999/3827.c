#include <stdio.h>

/*
문제 : N(N <= 50)개의 세포로 이루어진 일차원 세포 자동자가 있다. 각 세대마다 각 세포의 값은
이전 세대의 (왼쪽 값 * A + 해당 값 * B + 오른쪽 값 * C) % M(A, B, C < M <= 1000)으로 정의된다.
해당하는 세포가 없다면 0으로 생각한다. 이때, T(T <= 10^9)세대 후 모든 세포의 값을 구한다.

해결 방법 : 각 2^X 세대마다 각 세포에 대해 더해야 하는 값들의 계수를 미리 저장해둔다.
이는 2(X - 1)세대의 값에서 2번 이동하여 나오는 계수들을 더하여 알 수 있다.
그 다음 T에 해당하는 비트마다 세포의 상태를 2^X 턴씩 이동시키면서 세포의 값을 구하면 된다.
이는 위에서 저장해둔 값을 각 세포마다 적용시키는 방식으로 하면 된다.

주요 알고리즘 : 수학, 희소 배열

출처 : Tokyo 2012 C번
*/

int mvm[32][64][64], s[2][64];

int big(int a, int b) {
    return a > b ? a : b;
}

int main(void) {
    int n, m, a, b, c, t;
    while (1) {
        scanf("%d %d %d %d %d %d", &n, &m, &a, &b, &c, &t);
        if (m == 0) break;
        for (int i = 0; i < n; i++) {
            if (i > 0) mvm[0][i][i - 1] = a;
            mvm[0][i][i] = b;
            if (i < n - 1) mvm[0][i][i + 1] = c;
        }
        for (int i = 0; i < 31; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    for (int l = 0; l < n; l++) {
                        mvm[i + 1][j][k] = (mvm[i + 1][j][k] + mvm[i][j][l] * mvm[i][l][k]) % m;
                    }
                }
            }
        }
        for (int i = 0; i < n; i++) {
            scanf("%d", &s[0][i]);
        }
        for (int i = 0; i < 31; i++) {
            if (~t & (1 << i)) continue;
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    s[1][j] = (s[1][j] + s[0][k] * mvm[i][j][k]) % m;
                }
            }
            for (int j = 0; j < n; j++) {
                s[0][j] = s[1][j];
                s[1][j] = 0;
            }
        }
        for (int i = 0; i < n; i++) {
            printf("%d", s[0][i]);
            if (i < n - 1) printf(" ");
        }
        printf("\n");

        for (int i = 0; i < 32; i++) {
            for (int j = 0; j < 64; j++) {
                for (int k = 0; k < 64; k++) {
                    mvm[i][j][k] = 0;
                }
            }
        }
    }
    return 0;
}