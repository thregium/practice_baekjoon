#include <stdio.h>
#define MOD 1000000007

/*
문제 : N(N <= 10^7) 이하의 서로 다른 자연수의 곱으로 이루어진 수 가운데 가장 큰 제곱수를 10^9+7로 나눈 나머지를 구한다.

해결 방법 : 먼저 N!을 소인수분해 해본다. 각 소인수들이 홀수번 또는 짝수번 나올 것이다.
짝수번 나오는 소인수는 신경 쓸 필요가 없다.(이미 제곱수의 조건을 만족하므로) 홀수번 나오는 소인수는 해당 소인수와
같은 수로 나누면 해당 소인수의 등장 횟수가 1회 줄어드므로 짝수번으로 줄고, 따라서 제곱수의 조건을 만족할 수 있게 된다.

그런데, 10^9+7로 나눈 나머지를 취한 이후로는 나눗셈 연산으로 복원시키는 것이 불가능해진다.
따라서, 각 소인수를 먼저 에라토스테네스의 체를 이용해 찾은 다음, 각 소인수마다 등장 횟수를 구하고,
소인수에 대해 해당하는 등장 횟수 만큼 거듭제곱한 수를 분할 정복을 이용한 거듭제곱으로 구해서 결괏값에 곱하는 것을
반복하면 된다.

주요 알고리즘 : 수학, 정수론, 에라토스테네스, 분할 거듭제곱

출처 : SWERC 2011 J번
*/

char sieve[10485760];
int prime[1048576];
int pp = 0;

int sqrm(int a) {
    return (long long)a * a % MOD;
}

int mul(int n, int m) {
    //거듭제곱 구하기
    if (m == 0) return 1;
    else if (m & 1) return (long long)sqrm(mul(n, m >> 1)) * n % MOD;
    else return sqrm(mul(n, m >> 1));
}

int main(void) {
    int n, m, cnt, r;
    //freopen("E:\\PS\\ICPC\\Europe\\SWERC\\2011\\TestCasesAndSolutions-1\\J\\J.in", "r", stdin);
    //freopen("E:\\PS\\ICPC\\Europe\\SWERC\\2011\\TestCasesAndSolutions-1\\J\\J_t.out", "w", stdout);
    for (int i = 2; i <= 10000000; i++) {
        if (sieve[i]) continue;
        prime[pp++] = i; //소수 구하기
        for (int j = i * 2; j <= 10000000; j += i) {
            sieve[j] = 1;
        }
    }
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        r = 1;
        for (int i = 0; i < pp; i++) {
            if (n < prime[i]) break;
            cnt = 0;
            m = n;
            while (m) {
                cnt += m / prime[i]; //각 소인수의 등장 횟수 구하기
                m /= prime[i];
            }
            if (cnt & 1) cnt--;
            r = (long long)r * mul(prime[i], cnt) % MOD; //결과에 곱셈
        }
        printf("%d\n", r);
    }
    return 0;
}