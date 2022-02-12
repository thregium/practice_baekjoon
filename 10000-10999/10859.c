#include <stdio.h>

/*
문제 : 자연수 N(N <= 10^16)이 주어질 때, 이 자연수가 소수이고 180도 돌려도 소수인 지 구한다.
돌려서 수가 아니라면 소수가 아니다.

해결 방법 : 자연수를 뒷자리부터 하나씩 돌린 값을 확인하면서 돌려놓은 수를 만든다.
이 과정에서 자릿수로 3, 4, 7이 있다면 수가 아니므로 이 사실을 기록해둔다.
소수 판정은 2부터 sqrt(N)까지 확인하면서 나누어 떨어지는 경우가 있는 지 확인하면 된다.

주요 알고리즘 : 수학, 소수 판정, 구현

출처 : GCPC 2015 K번
*/

int isprime(long long x) {
    if (x <= 1) return 0;
    for (long long i = 2; i * i <= x; i++) {
        if (x % i == 0) return 0;
    }
    return 1;
}

int main(void) {
    long long n, rv = 0, val = 1, rs = 1;
    scanf("%lld", &n);
    rs &= isprime(n);
    while (n) {
        rv *= 10;
        if (n % 10 == 0 || n % 10 == 1 || n % 10 == 2 || n % 10 == 5 || n % 10 == 8) rv += n % 10;
        else if (n % 10 == 6) rv += 9;
        else if (n % 10 == 9) rv += 6;
        else val = 0;
        n /= 10;
    }
    rs &= val;
    rs &= isprime(rv);
    printf("%s", rs ? "yes" : "no");
    return 0;
}