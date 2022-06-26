#include <stdio.h>

/*
문제 : 두 개의 연분수가 주어질 때, 두 연분수를 더한 결과, 뺀 결과, 곱한 결과, 나눈 결과를 각각 출력한다.

해결 방법 : 우선 역순으로 두 연분수를 두 분수로 만들어준다. 그 다음 두 분수를 사칙연산한 결과를 구하고,
그 결과를 이용하여 다시 연분수를 만들어 출력하면 된다.
음수와 정수만 있는 경우 처리에 주의한다.

주요 알고리즘 : 수학, 구현

출처 : ECNA 2014 A번 // Rocky 2014 K번 // NCNA 2014 H번
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