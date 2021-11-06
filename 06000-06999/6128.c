#include <stdio.h>

/*
문제 : 정수의 제곱수의 합으로 N(N <= 10000)을 만드는 방법의 가짓수를 구한다. 순서만 다른 경우에도 다른 것이다.

해결 방법 : 4중 for문을 사용한다. 각각 해당 수까지의 제곱수의 합이 N 이하가 될 때 까지 확인하고,
정확히 N이 되면 결괏값을 1 올린다. 전부 확인한 후 결괏값이 답이 된다.

주요 알고리즘 : 브루트 포스

출처 : USACO 2007Q S1번
*/

int main(void) {
    int n, r = 0;
    scanf("%d", &n);
    for (int i = 0; i * i <= n; i++) {
        for (int j = 0; i * i + j * j <= n; j++) {
            for (int k = 0; i * i + j * j + k * k <= n; k++) {
                for (int l = 0; i * i + j * j + k * k + l * l <= n; l++) {
                    if (i * i + j * j + k * k + l * l == n) r++;
                }
            }
        }
    }
    printf("%d", r);
    return 0;
}