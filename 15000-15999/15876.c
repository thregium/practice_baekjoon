#include <stdio.h>

/*
문제 : 0부터 정수를 1씩 올리며 이진수들을 적었다. N(N <= 100)명이 차례로 돌아가며 이 이진수를 하나씩 말한다면
K(K <= N)번째 사람이 말해야 하는 비트를 순서대로 5개 구한다.

해결 방법 : 앞쪽 500개의 이진수를 시뮬레이션 한 다음, K - 1, N + K - 1, N * 2 + K - 1, N * 3 + K - 1, N * 4 + K - 1번째
비트를 출력하면 된다.

주요 알고리즘 : 구현, 수학

출처 : POSTECH 2018 C번
*/

int a[10240], tmp[32];

int main(void) {
    int n, k, p = 0, p2 = 0, cnt = 0;
    scanf("%d %d", &n, &k);
    k--;
    for (int i = 0; p <= 10000; i++) {
        if (i == 0) {
            p++;
            continue;
        }

        p2 = 0;
        for (int j = i; j; j >>= 1) {
            tmp[p2] = (j & 1);
            p2++;
            p++;
        }
        for (int j = 0; j < p2; j++) a[p - p2 + j] = tmp[p2 - j - 1];
    }
    printf("%d %d %d %d %d", a[k], a[n + k], a[n * 2 + k], a[n * 3 + k], a[n * 4 + k]);
    return 0;
}