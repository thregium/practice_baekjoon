#include <stdio.h>
#include <stdlib.h>
#define INF 1012345678

/*
문제 : N(N <= 10)개의 자연수 쌍이 주어질 때, 선택한 쌍들의 첫번째 수의 곱과 두번째 수의 합이 가장 적은 경우의 차이를 구한다.
단, 최소 한 쌍은 선택해야 한다.

해결 방법 : 선택할 수 있는 모든 쌍에 대해 선택해보고 가장 차이가 적은 경우를 구한다. 비트마스킹을 통해 구하는 것이 좋다.

주요 알고리즘 : 브루트 포스, 비트마스킹

출처 : COCI 08/09#2 3번
*/

int taste[16][2];

int main(void) {
    int n, s, b, r = INF;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &taste[i][0], &taste[i][1]);
    }
    for (int i = 1; i < (1 << n); i++) {
        s = 1, b = 0;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                s *= taste[j][0];
                b += taste[j][1];
            }
        }
        if (abs(s - b) < r) r = abs(s - b);
    }
    printf("%d", r);
    return 0;
}