#include <stdio.h>

/*
문제 : 자연수 N(N <= 1000000)이 주어질 때, 이 수를 네 소수의 합으로 만들 수 있는지 구하고 있다면 그 방법 중 하나를 출력한다.

해결 방법 : 4 이상의 모든 짝수는 두 소수의 합으로 만들 수 있다는 골드바흐의 추측을 이용한다. 증명되지는 않았지만,
최소한 long long 범위 내에서는 항상 참임이 알려져 있다. N이 홀수인 경우 2, 3을 하여 짝수로 만들고, 짝수인 경우
2, 2를 하여 짝수를 유지하면 된다. 그 다음에는 반드시 N - 4 또는 5인 모든 소수에 대해 조사하다 보면 반드시 소수인 두 쌍이 나올 것이다.

주요 알고리즘 : 수학, 정수론, 골드바흐의 추측
*/

char sieve[1048576];

int main(void) {
    int n;
    scanf("%d", &n);
    if (n < 10) {
        if (n < 8) printf("-1");
        else if (n == 8) printf("2 2 2 2");
        else printf("2 2 2 3");
        return 0;
    }

    if (n & 1) {
        printf("2 3 ");
        n -= 5;
    }
    else {
        printf("2 2 ");
        n -= 4;
    }
    for (int i = 2; i <= 1000000; i++) {
        if (sieve[i]) continue;
        for (int j = i * 2; j <= 1000000; j += i) sieve[j] = 1;
    }
    for (int i = 3; i * 2 <= n; i += 2) {
        if (sieve[i] == 0 && sieve[n - i] == 0) {
            printf("%d %d", i, n - i);
            break;
        }
    }
    return 0;
}