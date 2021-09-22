#include <stdio.h>

/*
문제 : N(N = 1)장의 카드의 앞뒷면에 각각 10000 이하의 자연수가 쓰여 있다. 이때, M(M <= 100)번 다음과 같은 행동을 했을 때,
현재 보이는 면에 있는 카드에 쓰인 수의 합을 구한다.
K(K <= 10000)가 주어질 때, K 이하의 수가 보이는 카드를 뒤집는다.
맨 처음에는 모든 카드가 앞면을 보고 있다.

해결 방법 : 문제에 주어진대로 구현하면 된다.

주요 알고리즘 : 구현, 시뮬레이션

출처 : 인하대 2019 K번
*/

int cards[10240][2], flips[10240];

int main(void) {
    int n, m, k, r = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &cards[i][0], &cards[i][1]);
    }
    for (int i = 0; i < m; i++) {
        scanf("%d", &k);
        for (int j = 0; j < n; j++) {
            if (cards[j][flips[j]] <= k) flips[j] = !flips[j];
        }
    }
    for (int i = 0; i < n; i++) {
        r += cards[i][flips[i]];
    }
    printf("%d", r);
    return 0;
}