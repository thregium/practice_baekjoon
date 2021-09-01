#include <stdio.h>

/*
문제 : N(N <= 1000)명에게 1부터 10까지의 수가 적힌 카드들 중 5장이 주어진다. (같은 카드도 주어질 수 있다.)
이때, 카드 3장을 뽑아 3장의 합의 마지막 숫자가 가장 큰 사람 가운데 번호가 가장 큰 사람의 번호를 구한다.

해결 방법 : 각 사람이 뽑을 수 있는 모든 카드의 조합에 대해 합의 마지막 숫자를 확인하고 가장 큰 것을 고른다.
이것이 가장 큰 사람을 고르면 된다.

주요 알고리즘 : 구현, 브루트 포스

출처 : 정올 2005 초1번
*/

int cards[8];

int main(void) {
    int n, rt, rn = -1, rp = -1;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 5; j++) {
            scanf("%d", &cards[j]);
        }
        rt = 0;
        for (int x1 = 0; x1 < 5; x1++) {
            for (int x2 = x1 + 1; x2 < 5; x2++) {
                for (int x3 = x2 + 1; x3 < 5; x3++) {
                    if ((cards[x1] + cards[x2] + cards[x3]) % 10 > rt) rt = (cards[x1] + cards[x2] + cards[x3]) % 10;
                }
            }
        }
        if (rt >= rn) {
            rn = rt;
            rp = i;
        }
    }
    printf("%d", rp);
    return 0;
}