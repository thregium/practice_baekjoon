#include <stdio.h>

/*
문제 : M * N(M, N <= 2000) 크기의 격자에서 계산 로봇이 있다. 주어진 방식대로 계산을 할때 저장된 값이 가장 큰 로봇의 값을 구한다.
각 로봇의 저장값은 |i−a| ≤ j −b, b < j를 만족하는 모든 로봇들 가운데 가장 큰 출력값이고, 각 로봇의 출력값은 각 로봇의 저장값 + 
주어진 각 로봇의 가중치이다. 맨 왼쪽 열의 로봇이 가장 먼저 계산을 시작하고 그 다음으로는 그 다음 열의 로봇이 계산을 시작하는 방식이다.
가장 왼쪽 열의 로봇의 저장값은 항상 0이다.

해결 방법 : 왼쪽 위 로봇과 왼쪽 아래 로봇의 저장값을 통해 범위 내 2열 또는 그 이상 왼쪽 열의 로봇의 출력값들을 알 수 있다.
그리고, 범위 내 1열 전의 로봇은 최대 3개이므로 이 로봇들의 출력값들은 직접 처리해주면 각 로봇의 저장값들을 알 수 있고,
이들 중 가장 큰 값을 구하면 된다.

주요 알고리즘 : DP

출처 : 정올 2021_2 초2/중1번
*/

char weight[2048][2048];
int output[2048][2048], outputmem[2048][2048], outputmem2[2048][2048];

int big(int a, int b) {
    return a > b ? a : b;
}

int main(void) {
    int m, n, r = 0;
    scanf("%d %d", &m, &n);
    for (int i = 1; i <= m; i++) {
        scanf("%s", weight[i] + 1);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            outputmem[j][i] = big(big(outputmem[j - 1][i - 1], outputmem[j + 1][i - 1]), big(big(output[j - 1][i - 1], output[j + 1][i - 1]), output[j][i - 1]));
            r = big(r, outputmem[j][i]);
            output[j][i] = outputmem[j][i] + weight[j][i] - '0';
        }
    }
    printf("%d", r);
    return 0;
}