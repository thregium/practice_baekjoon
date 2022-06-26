#include <stdio.h>
#define MOD 10000LL

/*
���� : N(N <= 10^9)�� �־��� ��, (x+a1)(x+a2)...(x+an)�� Ǯ����� ���� ���̸� ���Ѵ�.

�ذ� ��� : �� ��ҵ��� �и��ؼ� ���� �� �ش�. ��� ����� ���̸� ��Ȯ�� ���ϵ��� �Ѵ�.
�ڼ��� ���� �ڵ带 �����Ѵ�.

�ֿ� �˰��� : ����, ���շ�, ���� �ŵ�����
*/

long long powe(long long x, long long y, long long m) {
    if (y == 0) return 1;
    if (y == 1) return x;
    long long h = powe(x, y >> 1, m);
    h = (h * h) % m;
    if (y & 1) return (h * x) % m;
    else return h;
}

int main(void) {
    long long n, coefs = 0, res = 0;
    scanf("%lld", &n);
    for (long long i = 1; i <= n; i *= 10) coefs += n - i + 1; //��� ��� ������ ��
    coefs %= 10000;
    res = (res + (n - 1) * 2) % MOD; //��ȣ
    res = (res + n) % MOD; //�ܺ� +
    res = (res + n) % MOD; //x
    res = ((res + powe(2, n, MOD) - (n + 1)) % MOD + MOD) % MOD; //���� +
    res = (res + powe(2, n - 1, MOD) * n) % MOD; //a
    res = (res + coefs + MOD - 1) % MOD; //x�� ���
    res = (res + coefs * powe(2, n - 1, MOD)) % MOD; //a�� ���
    printf("%lld", res);
    return 0;
}