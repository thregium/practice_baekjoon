#include <stdio.h>

/*
���� : 10�� ������ �� �ڿ��� N, K�� �־��� ��, N!�� K�� �ִ������� ���Ѵ�.

�ذ� ��� : K�� ���μ������� ����, N!�� �ش� �Ҽ��� ���Ե� Ƚ����ŭ ���信 ���ϸ� �ȴ�. �̸� �ݺ��� ���� ���� �� �ִ�.

�ֿ� �˰��� : ����, ���μ�����

��ó : INC 2007 B��
*/

char sieve[32768];
int primes[4096];
int pp = 0;

int main(void) {
    int n, k, x, r, i, cnt, cnt2;
    for (int i = 2; i < 32768; i++) {
        if (sieve[i]) continue;
        primes[pp++] = i;
        for (int j = i * 2; j < 32768; j += i) {
            sieve[j] = 1;
        }
    }
    while (scanf("%d %d", &n, &k) != EOF) {
        x = k;
        r = 1;
        for (i = 0; primes[i] * primes[i] <= k; i++) {
            if (x % primes[i]) continue;
            cnt = 0;
            while (!(x % primes[i])) {
                x /= primes[i];
                cnt++;
            }
            cnt2 = 0;
            for (int j = n / primes[i]; j; j /= primes[i]) {
                cnt2 += j;
            }
            if (cnt > cnt2) cnt = cnt2;
            for (int j = 0; j < cnt; j++) {
                r *= primes[i];
            }
        }
        if (n >= x) r *= x;
        printf("%d\n", r);
    }
    return 0;
}