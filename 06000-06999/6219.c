#include <stdio.h>

/*
문제 : 구간 [A, B](A, B <= 4 * 10^6)에서 숫자 D가 포함된 소수의 개수를 구한다.

해결 방법 : 에라토스테네스의 체를 이용해 A에서 B 사이의 소수들을 구할 수 있다. 이제 이 수들 가운데 숫자 D가 포함된
수들을 찾은 다음, 그 수들의 개수를 구하면 된다.

주요 알고리즘 : 수학, 에라토스테네스

출처 : USACO 2007J B1번
*/

char sieve[4194304];

int main(void) {
    int a, b, d, r = 0, t;
    scanf("%d %d %d", &a, &b, &d);
    for (int i = 2; i <= b; i++) {
        if (sieve[i]) continue;
        if (i >= a) {
            t = 0;
            for (int j = i; j; j /= 10) {
                if (j % 10 == d) t = 1;
            }
            r += t;
        }
        for (int j = i * 2; j <= b; j += i) {
            sieve[j] = 1;
        }
    }
    printf("%d", r);
    return 0;
}