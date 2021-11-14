#include <stdio.h>

/*
문제 : N(N <= 100)개의 자연수(<= 10^6)가 주어진다. 두 자연수를 골라 한 자연수에서 나누어 떨어지는 임의의 소수를 나누고
그 수를 다른 자연수에 곱하는 연산을 반복하여 만들 수 있는 최대의 최대공약수와, 이 값을 만들기 위해
해야 하는 최소 연산 횟수를 구한다.

해결 방법 : 전체 자연수를 소인수분해한다. 그 후, 그 소인수분해한 소수들의 개수를 N으로 나눈 몫을 취해준다.
그 값을 다시 곱해주면 최대공약수의 답이 된다. 이 값을 만들기 위해 해야 하는 연산 횟수는 다시 각 자연수들을 소인수분해 하면서
최대공약수보다 적은 소수를 가진 것에서 차이 나는 소수의 개수 만큼을 더한 것과 같다.

주요 알고리즘 : 수학, 정수론, 소인수분해, 그리디 알고리즘

출처 : COCI 09/10#4 3번
*/

char sieve[1048576];
int prime[103000], cnt[103000], cnt2[103000], a[128];
int pp = 0;

int main(void) {
    int n, r = 1, r2 = 0;
    for (int i = 2; i <= 1000000; i++) {
        if (sieve[i]) continue;
        prime[pp++] = i;
        for (int j = i * 2; j <= 1000000; j += i) sieve[j] = 1;
    }
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        for (int x = a[i], j = 0; j < pp; j++) {
            while (x % prime[j] == 0) {
                cnt[j]++;
                x /= prime[j];
            }
            if (x == 1) break;
        }
    }

    for (int i = 0; i < pp; i++) {
        cnt[i] /= n;
        for (int j = 0; j < cnt[i]; j++) r *= prime[i];
    }
    printf("%d ", r);
    for (int i = 0; i < n; i++) {
        for (int x = a[i], j = 0; j < pp; j++) {
            while (x % prime[j] == 0) {
                cnt2[j]++;
                x /= prime[j];
            }
            if (x == 1) break;
        }
        for (int j = 0; j < pp; j++) {
            if (cnt2[j] < cnt[j]) r2 += cnt[j] - cnt2[j];
            cnt2[j] = 0;
        }
    }
    printf("%d", r2);
    return 0;
}