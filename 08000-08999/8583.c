#include <stdio.h>

/*
문제 : [A, B](A <= B <= 10^18) 범위에서 모든 접두사가 소수인 수의 개수를 구한다.

해결 방법 : 직접 백트래킹을 해보면 그러한 수는 모두 작은 범위에서만 나온다는 것을 알 수 있다.
따라서, 백트래킹을 한 후, 모든 조건에 맞는 수를 확인하면서 범위 안에 있는 수의 개수를 세면 된다.

주요 알고리즘 : 수학, 소수 판정, 백트래킹

출처 : JPOI 2011 1-2번
*/

long long res[128];
int rcnt = 0;

int isprime(long long x) {
    for (long long i = 2; i * i <= x; i++) {
        if (x % i == 0) return 0;
    }
    return 1;
}

void track(int n, long long p) {
    if (n == 18) return;
    if (!isprime(p)) return;
    res[rcnt++] = p;
    track(n + 1, p * 10 + 1);
    track(n + 1, p * 10 + 3);
    track(n + 1, p * 10 + 7);
    track(n + 1, p * 10 + 9);
}

int main(void) {
    track(1, 2);
    track(1, 3);
    track(1, 5);
    track(1, 7);
    long long a, b, r = 0;
    scanf("%lld %lld", &a, &b);
    for (int i = 0; i < rcnt; i++) {
        if (a <= res[i] && res[i] <= b) r++;
    }
    printf("%lld", r);
    return 0;
}