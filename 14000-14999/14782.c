#include <stdio.h>

/*
문제 : 자연수 L(L <= 10^6)의 모든 약수의 합을 구한다.

해결 방법 : L 이하의 모든 자연수에 대해 L을 나누어 봐서 나머지가 0인 수를 전부 더하면 된다.

주요 알고리즘 : 브루트 포스, 정수론

출처 : USACO 2006O B1번
*/

int main(void) {
    int l, r = 0;
    scanf("%d", &l);
    for (int i = 1; i <= l; i++) {
        if (l % i == 0) r += i;
    }
    printf("%d", r);
    return 0;
}