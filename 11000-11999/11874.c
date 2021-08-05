#include <stdio.h>

/*
문제 : L 이상 R(L <= R <= 10000) 이하인 수 가운데 모든 자릿수의 합이 X(X <= 36)인 가장 작은 수와 가장 큰 수를 찾는다.
단, 항상 답이 존재한다.

해결 방법 : L과 R의 범위가 작으므로 모든 수에 대해 찾아보면 된다.

주요 알고리즘 : 브루트 포스, 수학

출처 : COCI 15/16#5 1번
*/

int main(void) {
    int l, d, x, lo = 99999, hi = -1;
    scanf("%d%d%d", &l, &d, &x);
    for (int i = l; i <= d; i++) {
        if (i / 10000 + i / 1000 % 10 + i / 100 % 10 + i / 10 % 10 + i % 10 == x) {
            if (i < lo) lo = i;
            if (i > hi) hi = i;
        }
    }
    printf("%d\n%d", lo, hi);
    return 0;
}
