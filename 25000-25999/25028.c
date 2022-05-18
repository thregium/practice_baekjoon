#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MOD 1000000007

/*
���� : ��� ������ 1��°���� N(N <= 10^12)��°���� ���� ���� ���Ѵ�.

�ذ� ��� : 1000����° �ױ��� ���� ����, �� ������ �̿��ؼ� ���� ����� ������ �ȴ�.
���� ���� ������ ���� ������ ������ ���� �� ���� �ŵ������� ����ϴ� ������� �����Ѵ�.

�ֿ� �˰��� : ����, ���� �ŵ�����

��ó : Kriii 5ȸ FG��
*/

int a[32768];

long long powe(long long x, long long y, long long m) {
    if (y == 1) return x;
    long long h = powe(x, y >> 1, m);
    h = (h * h) % m;
    if (y & 1) return (h * x) % m;
    else return h;
}

int main(void) {
    long long n, p = 4, r = 1, c = 1, cc;
    scanf("%lld", &n);
    a[1] = 1;
    a[2] = 2;
    a[3] = 2;
    for (int i = 3; p < 30000; i++) {
        for (int j = 0; j < a[i]; j++) a[p++] = i;
    }
    p = 1;
    for (long long i0 = 1;; i0++) {
        for (long long i = 1; i <= a[i0]; i++) {
            if (n <= i0 * p) {
                for (long long j = 0; j < i0; j++) {
                    if (n <= p) {
                        for (int k = 0; k < n; k++) r = (r * c) % MOD;
                        printf("%lld", r);
                        return 0;
                    }
                    else {
                        n -= p;
                        r = (r * powe(c++, p, MOD)) % MOD;
                    }
                }
                break;
            }
            else {
                n -= i0 * p;
                cc = 1;
                for (int j = 0; j < i0; j++) cc = (cc * c++) % MOD;
                r = (r * powe(cc, p, MOD)) % MOD;
            }
            p++;
        }
    }
    return 0;
}