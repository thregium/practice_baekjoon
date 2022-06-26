#include <stdio.h>

/*
문제 : 자연수 N(N <= 10^12)이 주어질 때, 약수의 합이 짝수인 N 이하의 자연수 개수를 구한다.

해결 방법 : 2의 배수인 약수는 홀짝성에 영향을 주지 않으므로 배제할 수 있다.
그러면 각 홀수 약수의 개수가 홀수 개인 수를 구하는 것이 되고, 이는 홀수의 제곱수에 2의 거듭제곱(1 포함)을
곱한 것과 같다. 따라서, N 이하에 대해 그러한 수를 O(sqrt(N)logN)에 세 주면 된다.

주요 알고리즘 : 수학, 정수론
*/

int main(void) {
    long long n, r;
    scanf("%lld", &n);
    r = n;
    for (long long i = 1; i * i <= n; i += 2) {
        for (long long j = i * i; j <= n; j *= 2) r--;
    }
    printf("%lld", r);
    return 0;
}