#include <stdio.h>

/*
문제 : N(N <= 100)개의 카드게임 대회에 각각 출전할 때, 각각의 대회용으로 Ai(Ai <= 100)개의 덱이 있다.
덱이 없는 경우 기본 덱이 제공된다면, 대회에 출전할 수 있는 덱 조합의 가짓수를 구한다.

해결 방법 : 모든 대회의 덱 개수의 곱과 같다. 단, 0인 경우는 기본 덱이 제공되므로 1개로 생각한다.

주요 알고리즘 : 수학, 조합론

출처 : KAIST 2017 A번
*/

int main(void) {
    int n, m, a, r = 1;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        if (a == 0) continue;
        r *= a;
        r %= m;
    }
    printf("%d", r % m);
    return 0;
}