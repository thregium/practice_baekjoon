#include <stdio.h>

/*
문제 : 자연수 D와 N(D <= 5, N <= 2 * 10^9)이 주어진다. N 이상의 가장 작은 원더프라임을 구한다.
원더프라임은 N을 D자리 이상의 두 수로 잘랐을 때, 두 수가 모두 0으로 시작하지 않는 소수인 수이다.

해결 방법 : 처음으로 할 일은 충분히 넓은 범위의 수들에 대해 소수 여부를 미리 구해놓고 소수의 목록들을 구하는 것이다.
이는 에라토스테네스의 체를 이용해 해결 가능하다.

먼저 N 또는 (D * 2자리인 가장 작은 자연수) 중 더 큰 수부터 시작한다. 문제의 정의상 해당 수 이하에서는
답이 나올 수 없기 때문이다. 해당 수에서 시작해서 해당 수의 자릿수를 확인한 다음, 자를 위치를 지정한다.
자를 위치로 가능한 곳은 D번째 자리부터 해당 수의 자릿수를 DS라 했을 때 DS - D번째 자리까지이다.
해당 자리를 자르는 방법은 간단히 (10^i)로 나눈 몫과 나머지를 구하면 된다.

자른 다음에는 (10^(i - 1))보다 큰지 확인하여 0으로 시작하는지 확인한다. 그 다음으로는 앞에서 구한 소수 여부와
소수 목록들을 통해 앞쪽과 뒤쪽 수들을 소수인지 판정한다. 해당하는 수가 작은 경우(이 코드에서는 1000만 이하)에는
에라토스테네스의 체로 얻은 소수 여부로 즉시 판정하고, 큰 경우에는 해당 수의 제곱근 이하인 소수들의 배수인지를 통해
합성수인지를 판정한 다음, 합성수가 아니라면 소수로 판정한다.
양쪽 모두에서 소수인 경우에는 해당하는 수를 출력하고 종료하면 된다.

주요 알고리즘 : 수학, 에라토스테네스, 브루트 포스, 구현

출처 : USACO 2006D B1번
*/

char sieve[10485760];
int primes[103000];
int b10[] = { 1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000 };
int pp = 0;

int main(void) {
    for (int i = 2; i <= 10000000; i++) {
        if (sieve[i]) continue;
        if (pp < 100000) primes[pp++] = i; //앞쪽 10만개의 소수들을 미리 구해놓는다.
        for (int j = i * 2; j <= 10000000; j += i) {
            sieve[j] = 1;
        }
    }
    sieve[0] = 1; //0과 1을 합성수로 조정한다.
    sieve[1] = 1;

    int d, n, s, ds = 0, upper, lower; //S : 시작 위치 후보, DS: 현재 수의 자릿수
    scanf("%d %d", &d, &n);
    s = b10[d - 1] * (b10[d] + 1);
    ds = d * 2;
    if (s > n) n = s;
    else {
        ds = 0;
        while (ds < 10 && n >= b10[ds]) ds++;
    }
    while (1) {
        if (ds < 10 && n >= b10[ds]) ds++;
        for (int i = d; i <= ds - d; i++) {
            //i : 자를 위치
            upper = n / b10[i]; //앞쪽 수
            if (upper < b10[ds - i - 1]) continue;
            lower = n % b10[i]; //뒤쪽 수
            if (lower < b10[i - 1]) continue;
            if (upper < 10000000) {
                if (!sieve[upper]) upper = 1; //1000만 미만은 체를 이용해 해결
                else upper = 0;
            }
            else {
                //8자리 이상의 수는 소수들을 확인하여 해결
                for (int i = 0; primes[i] * primes[i] <= upper; i++) {
                    if (upper % primes[i] == 0) {
                        upper = 0; //만약 합성수임이 확인되면 종료
                        break;
                    }
                }
                if (upper) upper = 1;
            }

            //뒤쪽 수도 앞쪽 수와 동일한 방식으로 소수 여부 판정
            if (lower < 10000000) {
                if (!sieve[lower]) lower = 1;
                else lower = 0;
            }
            else {
                for (int i = 0; primes[i] * primes[i] <= lower; i++) {
                    if (lower % primes[i] == 0) {
                        lower = 0;
                        break;
                    }
                }
                if (lower) lower = 1;
            }

            if (upper && lower) {
                //양쪽이 소수인 경우에는 출력 후 종료
                printf("%d", n);
                return 0;
            }
        }
        n++;
    }
    return 0;
}