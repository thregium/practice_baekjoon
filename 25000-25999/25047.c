#include <stdio.h>
#define INF 1234567890987654321

/*
문제 : N * N(N <= 18) 크기 행렬에 절댓값 10^9 이하 정수들이 쓰여있다.
한 명이 먼저 행들을 선택하고 다른 한 명이 열들을 선택한다. 한 명만 선택한 칸들은
행을 선택한 사람의 점수가 되고, 그 외 칸은 열을 선택한 사람의 점수가 된다고 할 때,
행을 선택하는 사람의 최대 점수를 구한다. 두명은 최적이 되도록 행과 열을 선택한다.

해결 방법 : 가능한 각 행의 모든 경우의 수를 선택한 다음, 열을 선택하는 점수가 최소한이 되는 경우
(각 줄에 대해 선택한 값과 선택하지 않은 값 가운데 최솟값의 합)의 점수를 구한다.
그 점수들 가운데 최댓값을 구하면 답이 된다. 시작점을 음수로 해야 함에 유의한다.

주요 알고리즘 : 브루트 포스, 그리디 알고리즘

출처 : DGIST 2022 D번
*/

long long a[32][32];

int main(void) {
    int n;
    long long sum, ssum, usum, res = -INF;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%lld", &a[i][j]);
        }
    }
    for (int i = 0; i < (1 << n); i++) {
        sum = 0;
        for (int j = 0; j < n; j++) {
            ssum = 0, usum = 0;
            for (int k = 0; k < n; k++) {
                if ((i >> k) & 1) ssum += a[k][j];
                else usum += a[k][j];
            }
            if (ssum < usum) sum += ssum;
            else sum += usum;
        }
        if (sum > res) res = sum;
    }
    printf("%lld", res);
    return 0;
}