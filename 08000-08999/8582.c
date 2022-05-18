#include <stdio.h>

/*
문제 : N(N <= 10^6)개의 자연수(<= 10^9)로 이루어진 수열에서 각 지점에 대해 그 지점을 포함해 왼쪽과 오른쪽의
수 가운데 가장 큰 값을 각각 구한다.

해결 방법 : 왼쪽과 오른쪽부터의 누적 최댓값을 각각 구하면 각 지점의 누적 최댓값이 답이 된다.

주요 알고리즘 : DP?

출처 : JPOI 2011 1-1번
*/

int hilo[1048576][2];

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &hilo[i][1]);
        hilo[i][0] = hilo[i - 1][0];
        if (hilo[i][1] > hilo[i][0]) hilo[i][0] = hilo[i][1];
    }
    for (int i = n; i >= 1; i--) {
        if (hilo[i + 1][1] > hilo[i][1]) hilo[i][1] = hilo[i + 1][1];
    }
    for (int i = 1; i <= n; i++) {
        printf("%d %d\n", hilo[i][0], hilo[i][1]);
    }
    return 0;
}