#include <stdio.h>

/*
문제 : N(N <= 10^6)에서 시작하는 콜라츠 수열의 길이를 구한다.

해결 방법 : 1이 될 때 까지 반복하며 반복 횟수를 세면 된다.

주요 알고리즘 : 수학, 구현

출처 : USACO 2006X G1번
*/

int main(void) {
    long long n, score = 0;
    scanf("%lld", &n);
    while (n > 1) {
        if (n & 1) n = n * 3 + 1;
        else n >>= 1;
        score++;
    }
    printf("%lld", score);
    return 0;
}