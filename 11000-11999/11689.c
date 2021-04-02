#include <stdio.h>

/*
���� : �ڿ��� n�� �־����� �� n �����̸� n�� ���μ��� �ڿ����� ������ ���Ѵ�.

�ذ� ��� : ���Ϸ� �� �Լ��� �������� �̿��ϸ� �� �ڿ����� ���μ������� ���� ���μ����� ���μ�^(���μ��� ��)*(���μ� - 1)�� ���ָ� �ذ� ���´�.

�ֿ� �˰��� : ����, ������, ���Ϸ� �� �Լ�
*/

int sieve[1048576], primes[102400];
int pp = 0;

int main(void) {
    int a, b, rt = 0;
    for (int i = 2; i <= 1000; i++) {
        rt = 1;
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                rt = 0;
                break;
            }
        }
        if (rt) primes[pp++] = i;
    }
    for (int i = 2; i <= 1000000; i++) sieve[i] = 1;
    for (int i = 0; i < pp; i++) {
        for (int j = primes[i] * primes[i]; j <= 1000000; j++) {
            if (j % primes[i] == 0) sieve[j] = 0;
        }
    }
    pp = 0;
    for (int i = 1; i <= 1000000; i++) {
        if (sieve[i]) primes[pp++] = i;
    }


    long long n, f = 1;
    int k;
    scanf("%lld", &n);
    for (int i = 0; (long long)primes[i] * primes[i] <= n; i++) {
        if (n % primes[i] == 0) {
            k = 0;
            for (;; n /= primes[i]) {
                if (n % primes[i]) {
                    for (int j = 0; j < k - 1; j++) {
                        f *= primes[i];
                    }
                    f *= (long long)primes[i] - 1;
                    break;
                }
                k++;
            }
        }
    }
    if (n > 1) f *= n - 1;
    printf("%d", f);
    return 0;
}
