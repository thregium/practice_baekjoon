#include <stdio.h>

/*
���� : �� ���� ���м��� �־��� ��, �� ���м��� ���� ���, �� ���, ���� ���, ���� ����� ���� ����Ѵ�.

�ذ� ��� : �켱 �������� �� ���м��� �� �м��� ������ش�. �� ���� �� �м��� ��Ģ������ ����� ���ϰ�,
�� ����� �̿��Ͽ� �ٽ� ���м��� ����� ����ϸ� �ȴ�.
������ ������ �ִ� ��� ó���� �����Ѵ�.

�ֿ� �˰��� : ����, ����

��ó : ECNA 2014 A�� // Rocky 2014 K�� // NCNA 2014 H��
*/

typedef struct frac {
    long long up;
    long long dn;
} frac;

long long cf1[16], cf2[16];

long long gcd(long long a, long long b) {
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    if (a == 0) return b;
    if (b == 0) return a;
    return a > b ? gcd(a % b, b) : gcd(a, b % a);
}

frac fracplus(frac a, frac b) {
    frac res = { a.up * b.dn + b.up * a.dn, a.dn * b.dn };
    long long g = gcd(res.dn, res.up);
    res.dn /= g;
    res.up /= g;
    return res;
}

frac fracminus(frac a, frac b) {
    frac res = { a.up * b.dn - b.up * a.dn, a.dn * b.dn };
    long long g = gcd(res.dn, res.up);
    res.dn /= g;
    res.up /= g;
    return res;
}

frac fracmult(frac a, frac b) {
    frac res = { a.up * b.up, a.dn * b.dn };
    long long g = gcd(res.dn, res.up);
    res.dn /= g;
    res.up /= g;
    if (res.dn < 0) {
        res.dn *= -1;
        res.up *= -1;
    }
    return res;
}

frac fracdiv(frac a, frac b) {
    frac res = { a.up * b.dn, a.dn * b.up };
    long long g = gcd(res.dn, res.up);
    res.dn /= g;
    res.up /= g;
    if (res.dn < 0) {
        res.dn *= -1;
        res.up *= -1;
    }
    return res;
}

frac fracrev(frac a) {
    long long tdn = a.dn;
    a.dn = a.up;
    a.up = tdn;
    return a;
}

frac makefrac(long long* cf, int n) {
    if (n == 1) return (frac) { cf[0], 1 };
    frac res = { 1, cf[n - 1]};
    for (int i = n - 2; i >= 0; i--) {
        res = fracplus(res, (frac) { cf[i], 1 });
        if (i > 0) res = fracrev(res);
    }
    return res;
}

void printconf(frac f) {
    if (f.up < 0) {
        printf("%lld ", -((-f.up + f.dn - 1) / f.dn));
        f = fracminus(f, (frac) { -((-f.up + f.dn - 1) / f.dn), 1 });
    }
    else {
        printf("%lld ", f.up / f.dn);
        f = fracminus(f, (frac) { f.up / f.dn, 1 });
    }
    while (f.up > 1) {
        f = fracrev(f);
        printf("%lld ", f.up / f.dn);
        f = fracminus(f, (frac) { f.up / f.dn, 1 });
    }
    if (f.up != 0) printf("%lld ", f.dn);
    printf("\n");
}

int main(void) {
    int n, m;
    frac f1, f2;
    for (int tt = 1;; tt++) {
        scanf("%d %d", &n, &m);
        if (n == 0 && m == 0) break;
        for (int i = 0; i < n; i++) {
            scanf("%lld", &cf1[i]);
        }
        for (int i = 0; i < m; i++) {
            scanf("%lld", &cf2[i]);
        }
        f1 = makefrac(cf1, n);
        f2 = makefrac(cf2, m);

        printf("Case %d:\n", tt);
        printconf(fracplus(f1, f2));
        printconf(fracminus(f1, f2));
        printconf(fracmult(f1, f2));
        printconf(fracdiv(f1, f2));
    }
    return 0;
}