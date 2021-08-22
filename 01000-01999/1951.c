#include <stdio.h>
#define MOD 1234567

/*
���� : �ڿ��� N(N <= 2 * 10^9)�� �־��� ��, 1���� N���� �ڸ��� ������ ���� ���Ѵ�.

�ذ� ��� : N�� �ڸ��� �������� ���� (N - N���� �ڸ����� 1 ���� �� �� ���� ū ��) * N�� �ڸ���
+ ((N���� �ڸ����� 1 ���� �� �� ���� ū ��)������ ��)�� ����. ���� �� ���� ���ϸ� �ȴ�.

�ֿ� �˰��� : ����, ���̽� ��ũ
*/

int main(void) {
    long long n;
    scanf("%lld", &n);
    if (n < 10) printf("%lld", n % MOD);
    else if (n < 100) printf("%lld", (9 + (n - 9) * 2) % MOD);
    else if (n < 1000) printf("%lld", (189 + (n - 99) * 3) % MOD);
    else if (n < 10000) printf("%lld", (2889 + (n - 999) * 4) % MOD);
    else if (n < 100000) printf("%lld", (38889 + (n - 9999) * 5) % MOD);
    else if (n < 1000000) printf("%lld", (488889 + (n - 99999) * 6) % MOD);
    else if (n < 10000000) printf("%lld", (5888889 + (n - 999999) * 7) % MOD);
    else if (n < 100000000) printf("%lld", (68888889 + (n - 9999999) * 8) % MOD);
    else if (n < 1000000000) printf("%lld", (788888889 + (n - 99999999) * 9) % MOD);
    else if (n < 10000000000) printf("%lld", (8888888889 + (n - 999999999) * 10) % MOD);
    return 0;
}