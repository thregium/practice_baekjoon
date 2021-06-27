#include <stdio.h>
#include <stdlib.h>

/*
문제 : 네 자연수 A, B, C, D(A <= B)(C <= D)(A, B, C, D <= 10^7)가 주어질 때,
구간 [A, B]와 [C, D]를 각자 짝지어서 만들 수 있는 서로소 쌍의 개수를 구한다.

해결 방법 : 두 자연수가 서로소인 경우는 두 자연수 사이 공유하는 소인수가 존재하지 않는 경우이다. 따라서, 이를 구하기 위해
10^7 이하의 모든 소수들을 에라토스테네스의 체를 이용해 전처리한다. 여기서 공유하는 소인수가 존재하지 않는 경우보다는
공유하는 소인수가 존재하는 경우를 전체에서 빼주는 것이 더 쉽다. 먼저 전체 구간의 쌍의 개수를 확인한 후,
양쪽 다 같은 소수로 나누어지는 경우를 빼줘야 한다. 그런데, 그러면서 소수 2개의 곱으로 구성되는 수들은 2번 빼지게 되므로
다시 더해주어야 하고, 다시 3개의 곱으로 구성되는 수들은 2번 더히지므로 빼줘야 하고... 를 반복하면
홀수개의 서로 다른 소수의 곱으로 구성되는 수들은 빼고, 짝수개의 곱으로 구성되는 수들은 더해주어야 함을 알 수 있다.
따라서, 이러한 수들을 전처리로 분류해준 후, 양쪽에서 그러한 수들로 나누어 떨어지는 수들의 개수의 곱을 구해 더하거나 빼주는 것을
모든 수에 대해 반복해주면 된다.

주요 알고리즘 : 수학, 포함배제, 에라토스테네스의 체

출처 : PacNW 2018 B번 // MidC 2018 E번
*/

char sieve[10485760];
int primes[786432], odds[4194304], evens[4194304];
int pp = 0, oddi = 0, eveni = 0;

void track(int cnt, int start, long long n) {
    if (cnt & 1) odds[oddi++] = n;
    else evens[eveni++] = n;
    for (int i = start; i < pp; i++) {
        if (n * primes[i] > 10000000) break;
        track(cnt + 1, i + 1, n * primes[i]);
    }
}

int main(void) {
    long long a, b, c, d, r = 0;
    for (int i = 2; i <= 10000000; i++) {
        if (sieve[i]) continue;
        primes[pp++] = i;
        for (int j = i * 2; j <= 10000000; j += i) {
            sieve[j] = 1;
        }
    }
    track(0, 0, 1);
    scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
    for (int i = 0; i < eveni; i++) {
        r += (b / evens[i] - (a - 1) / evens[i]) * (d / evens[i] - (c - 1) / evens[i]);
    }
    for (int i = 0; i < oddi; i++) {
        r -= (b / odds[i] - (a - 1) / odds[i]) * (d / odds[i] - (c - 1) / odds[i]);
    }
    printf("%lld", r);
    return 0;
}