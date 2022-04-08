#include <stdio.h>
#include <stdlib.h>

/*
문제 : (-1, -1)에서 (1, 1)에 걸친 정사각형의 (-1, 0) 지점에서 a / b(a, b <= 10^6) 방향으로 광선을 쐈다.
공선이 정사각형의 변에서 계속 반사될 때, N(N <= 10^6)번의 반사 후 광선이 도달하는 지점을 정확히 구한다.

해결 방법 : 광선이 도달하는 방향과 위치에 따라 X, Y 좌표의 값을 분수 구조체를 이용해 바꿔가면 된다.
방향은 항상 2가지 중 하나임을 이용한다.

주요 알고리즘 : 수학, 기하학, 시뮬레이션

출처 : PacNW 2021D2 T번 // SCUSA 2021D2 H번
*/

typedef struct frac {
    long long up;
    long long down;
} frac;

const frac fracone = { 1, 1 };
const frac fracmone = { -1, 1 };

long long gcd(long long a, long long b) {
    a = llabs(a), b = llabs(b);
    if (a == 0) return b;
    if (b == 0) return a;
    return a > b ? gcd(a % b, b) : gcd(a, b % a);
}

frac reducefrac(frac a) {
    long long g = gcd(a.up, a.down);
    a.up /= g;
    a.down /= g;
    if (a.down < 0) {
        a.down *= -1;
        a.up *= -1;
    }
    return a;
}

int fraccmp(frac a, frac b) {
    a.up *= b.down;
    b.up *= a.down;
    if (a.up < b.up) return 1;
    else if (a.up == b.up) return 0;
    else return -1;
}

frac sumfrac(frac a, frac b) {
    frac r = { a.up * b.down + b.up * a.down, a.down * b.down };
    return reducefrac(r);
}

frac subfrac(frac a, frac b) {
    frac r = { a.up * b.down - b.up * a.down, a.down * b.down };
    return reducefrac(r);
}

frac multfrac(frac a, frac b) {
    frac r = { a.up * b.up, a.down * b.down };
    return reducefrac(r);
}

frac divfrac(frac a, frac b) {
    frac r = { a.up * b.down, a.down * b.up };
    return reducefrac(r);
}

int main(void) {
    frac slope, x = { -1, 1 }, y = { 0, 1 };
    int n, lr = 1;
    scanf("%lld %lld %d", &slope.up, &slope.down, &n);
    for (int i = 0; i <= n; i++) {
        if (lr > 0) {
            if (fraccmp(sumfrac(y, multfrac(subfrac(fracone, x), slope)), fracone) == 1 &&
                fraccmp(sumfrac(y, multfrac(subfrac(fracone, x), slope)), fracmone) == -1) {
                y = sumfrac(y, multfrac(subfrac(fracone, x), slope));
                x = fracone;
                lr = -1;
            }
            else if (fraccmp(sumfrac(y, multfrac(subfrac(fracone, x), slope)), fracone) < 1) {
                x = sumfrac(x, divfrac(subfrac(fracone, y), slope));
                y = fracone;
            }
            else if (fraccmp(sumfrac(y, multfrac(subfrac(fracone, x), slope)), fracmone) > -1) {
                x = subfrac(x, divfrac(subfrac(y, fracmone), slope));
                y = fracmone;
            }
            else return 1;
        }
        else {
            if (fraccmp(subfrac(y, multfrac(subfrac(x, fracmone), slope)), fracone) == 1 &&
                fraccmp(subfrac(y, multfrac(subfrac(x, fracmone), slope)), fracmone) == -1) {
                y = subfrac(y, multfrac(subfrac(x, fracmone), slope));
                x = fracmone;
                lr = 1;
            }
            else if (fraccmp(subfrac(y, multfrac(subfrac(x, fracmone), slope)), fracone) < 1) {
                x = sumfrac(x, divfrac(subfrac(fracone, y), slope));
                y = fracone;
            }
            else if (fraccmp(subfrac(y, multfrac(subfrac(x, fracmone), slope)), fracmone) > -1) {
                x = subfrac(x, divfrac(subfrac(y, fracmone), slope));
                y = fracmone;
            }
            else return 1;
        }
        slope.up *= -1;
    }
    printf("%lld %lld %lld %lld", x.up, x.down, y.up, y.down);
    return 0;
}