#include <stdio.h>

/*
문제 : N(N <= 100)면체 주사위를 최대 K(K <= 100)회 던질 수 있다고 할 때, 마지막에 던진 주사위의 기댓값을 구한다.
단, 주사위는 최적의 전략(최댓값 얻기)으로 던진다.

해결 방법 : N면체 주사위를 각 횟수만큼 던질 때 마다 그때의 기댓값을 저장해둔다. 만약 현재 던진 주사위의 값이 한번 더 던졌을 때의
기댓값보다 낮다면 다시 주사위를 던진다. 이상인 경우 주사위를 종료하고 현재 값을 고정한다. 이를 반복해 K번째의 값을 찾으면 된다.

주요 알고리즘 : DP, 확률론, 게임 이론

출처 : BAPC 2019P D번
*/

double mem[128];

int main(void) {
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) {
        mem[1] += (double)i / n;
    }
    for (int i = 2; i <= k; i++) {
        for (int j = 1; j <= n; j++) {
            if (j > mem[i - 1]) mem[i] += (double)j / n;
            else mem[i] += mem[i - 1] / n;
        }
    }
    printf("%.15lf", mem[k]);
    return 0;
}