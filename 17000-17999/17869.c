#include <stdio.h>

/*
문제 : 자연수 N(N < 2^31)이 주어질 때, N이 짝수면 2로 나누고 홀수면 1을 더하는 것을 몇 회 반복해야 1이 되는지 구한다.

해결 방법 : N이 1이 될 때 까지 주어진 행동을 반복하고 반복한 횟수를 구하면 된다. 어떤 수가 홀수더라도,
1을 더하고 2로 나누면 거의 절반으로 줄어들기 때문에 답은 매우 작은 수에서 나오게 된다.

주요 알고리즘 : 수학, 구현

출처 : GNY 2019 G번
*/

int main(void) {
    long long n, r = 0;
    scanf("%lld", &n);
    while (n > 1) {
        if (n & 1) n = n + 1;
        else n >>= 1;
        r++;
    }
    printf("%lld", r);
    return 0;
}