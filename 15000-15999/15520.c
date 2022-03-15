#include <stdio.h>

/*
문제 : [L, R](1 <= L <= R <= 10^9)(R - L <= 10^6) 범위의 자연수들 가운데 소인수의 개수가 소수개인
수의 개수를 구한다. 같은 소인수가 여러번 곱해지는 경우 각각을 개수에 더한다.

해결 방법 : 에라토스테네스의 체를 응용한다. 우선 i * i 이내의 소수들을 에라토스테네스의 체로 구한 후,
각 소수들의 곱이 되는 수들을 [L, R] 범위에서 찾아서 각각의 해당 소인수 개수를 찾아낸 후 합에 더한다.
그리고 아직 1이 되지 않은 수들의 소인수 개수를 1씩 늘려주고 각 수의 소인수 개수가 소수개인 지 확인한다.
위에서 소수를 찾을 때 32(2^32는 10^9보다 크므로) 이하의 소수들을 미리 구해두면
체에서 바로 소수 여부를 확인 가능하므로 좋다.

주요 알고리즘 : 수학, 정수론, 에라토스테네스

출처 : JAG 2017P C번
*/

char sieve[1048576];
int pcnt[1048576], rem[1048576], prime[103000];
int pp = 0;

int main(void) {
    int st, ed;
    long long res = 0;
    scanf("%d %d", &st, &ed);
    for (int i = st; i <= ed; i++) rem[i - st] = i;
    sieve[0] = 1, sieve[1] = 1;
    for (long long i = 2; i * i <= ed || i <= 100; i++) {
        if (sieve[i]) continue;
        prime[pp++] = i;
        for (long long j = i * 2; j * j <= ed || j <= 100; j += i) sieve[j] = 1;
    }
    for (int i = 0; i < pp; i++) {
        for (int j = st / prime[i] * prime[i]; j <= ed; j += prime[i]) {
            if (j < st) continue;
            while (rem[j - st] % prime[i] == 0) {
                pcnt[j - st]++;
                rem[j - st] /= prime[i];
            }
        }
    }
    for (int i = st; i <= ed; i++) {
        if (rem[i - st] > 1) pcnt[i - st]++;
        res += (!sieve[pcnt[i - st]]);
    }
    printf("%lld\n", res);
    return 0;
}