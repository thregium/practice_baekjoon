#include <stdio.h>

/*
문제 : N(N <= 10^6) 개의 불들이 켜진 상태로 있다. K(K <= 100)번 자연수 i가 주어지면
i의 배수 번째 불들의 상태를 반전시키는 행동을 반복할 때,
중간 과정에서 가장 많이 불들이 꺼졌을 때의 꺼진 불 개수를 구한다.

해결 방법 : 각 불의 상태를 배열에 저장한 다음, 각 i가 주어질 때 마다 i의 배수번째 불들의 상태를
반전시키며 꺼진 불의 개수를 다시 확인한다. 이를 반복하며 가장 많이 꺼졌을 때 꺼진 불의 개수를 구하면 된다.

주요 알고리즘 : 구현, 시뮬레이션

출처 : SWERC 2018 A번
*/

char light[1048576];

int main(void) {
    int n, k, x, l = 0, r = 0;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < k; i++) {
        scanf("%d", &x);
        for (int j = x; j <= n; j += x) {
            light[j] = !light[j];
            l += light[j] * 2 - 1;
        }
        if (l > r) r = l;
    }
    printf("%d", r);
    return 0;
}