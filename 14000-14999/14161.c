#include <stdio.h>
#define MOD 1000000007

/*
���� : A���� ����ġ�� B(A, B <= 100000)���� ������ ���� ��, �� ����ġ�� ������ �ϳ��� ��������
��� ������ 1�� �̻��� ����ġ�� �����Ǵ� ����� ���� ���Ѵ�.

�ذ� ��� : B�� A���� ū ��� �׷��� �����ϴ� ����� ������ ������ �� �� �ִ�.
�� �ܿ��� A���� ����ġ�� (B���� ������ �����ϴ� ���) - (B - 1���� ����) + (B - 2���� ����) ...
�̷� ������ ���� ������ ������ ���� �����ϴ� ����� ������ ����� ���� ���س�����
��� ������ 1�� �̻��� ����ġ�� �����Ǵ� ����� ���� ���� �� �ִ�.
�� ���� ������ �����ϴ� ����� ���� ������ i�� �� ��, A^i * b_C_i�� ����.
a^i�� ���� �ŵ���������, b_C_i�� ���� ������ �̿��� ���� �ŵ��������� ����� �� �����Ƿ�
���� ���� ���� ����ϸ� ���� �ȴ�.

�ֿ� �˰��� : ����, ���շ�, ���� �ŵ�����, ���Թ��� ��

��ó : CPC 2007 G��
*/

int fact[103000];

long long powe(long long x, long long y, long long m) {
    if (y == 1) return x;
    long long h = powe(x, y >> 1, m);
    h = (h * h) % m;
    if (y & 1) return (h * x) % m;
    else return h;
}

long long comb(long long n, long long k) {
    return fact[n] * powe(fact[k] * (long long)fact[n - k] % MOD, MOD - 2, MOD) % MOD;
}

int main(void) {
    int a, b;
    long long r = 0;
    fact[0] = 1;
    for (int i = 1; i <= 100000; i++) {
        fact[i] = (long long)fact[i - 1] * i % MOD;
    }
    scanf("%d %d", &a, &b);
    if (a < b) {
        printf("0");
        return 0;
    }
    for (int i = b; i > 0; i--) {
        if ((b - i) & 1) r = (r + MOD - powe(i, a, MOD) * comb(b, i) % MOD) % MOD;
        else r = (r + powe(i, a, MOD) * comb(b, i) % MOD) % MOD;
    }
    printf("%lld", r);
    return 0;
}