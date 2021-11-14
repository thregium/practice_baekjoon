#include <stdio.h>
#define MOD 1000000007

/*
���� : M(M <= 10000)���� �ֻ����� �� �ֻ����� �� ��, ��� ���� ���� �־��� ��, ��� �ֻ����� ������ ������
���� �տ� ���� ����� Mod 10^9 + 7 �� ���� ���Ѵ�.

�ذ� ��� : ��ⷯ ������ �̿��Ѵ�. A / B�� Mod X�� ���� A * B^(X - 2) % X��� ���� �̿��Ѵ�.
����, �ܼ��� �̷��� ���� ���ϰ� ��ⷯ �ϴ� �͸����ε� ���� ���ٴ� �� ���п� ���� ������ Ǯ �� �ִ�.

�ֿ� �˰��� : ����, ������, ���� ����, ���� �ŵ�����

��ó : kriiicon P2��
*/

long long powe(long long x, long long y, long long m) {
    if (y == 1) return x;
    long long h = powe(x, y >> 1, m);
    h = (h * h) % m;
    if (y & 1) return (h * x) % m;
    else return h;
}

int main(void) {
    int m;
    long long n, s, r = 0;
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%lld %lld", &n, &s);
        r = (r + s * powe(n, MOD - 2, MOD)) % MOD;
    }
    printf("%lld", r);
    return 0;
}