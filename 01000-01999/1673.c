#include <stdio.h>

/*
문제 : K(2 <= K <= N)개의 쿠폰으로 치킨을 교환할 수 있다면 N(N <= 10^9)개의 치킨을 시키고 먹을 수 있는 치킨의 수를 구한다.
치킨을 1개 시키면 쿠폰을 주고, 쿠폰은 치킨을 결제한 뒤 받을 수 있다.

해결 방법 : N개의 치킨을 먹은 다음, 쿠폰의 개수를 계산한다. 그 다음, 쿠폰으로 시킬 수 있는 만큼 치킨을 시키는 것을 반복해
더이상 치킨을 시킬 수 없을 때 까지 합을 더해나가면 된다.

주요 알고리즘 : 수학

출처 : Alberta 2000 D번
*/

int main(void) {
    int n, k, r, c;
    while (scanf("%d %d", &n, &k) != EOF) {
        r = 0, c = 0;
        while (n > 0) {
            r += n;
            c += n;
            n = c / k;
            c %= k;
        }
        printf("%d\n", r);
    }
    return 0;
}