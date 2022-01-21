#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <assert.h>
#define HH 1E18

/*
문제 : 실수부와 허수부가 각각 (b + c * sqrt(d)) / a의 형태로 이루어진 X, Y라는 두 복소수가 주어진다.
이때, X + Y, X - Y, X * Y, X / Y의 값을 각각 구한다. 모든 계수는 10 이하고, 모든 a는 0보다 크며,
모든 d는 0 또는 2 이상의 자연수이다. 그리고, d가 0인 경우 그에 맞는 c도 0이며, 모든 d는 같다.
마지막으로 gcd(a, b, c)는 2 이하가 되어선 안 되고, d의 가장 큰 제곱수인 약수는 1이어야 한다.
이 모든 조건은 출력값에도 적용된다.

해결 방법 : 각 복소수를 구조체로 만든 다음 복소수에 대해 각 연산의 값을 구하는 함수를 만든다.
나눗셈의 경우 역수를 구하는 함수를 만들어 해결 가능하다. 역수는 (A + B)(A - B)가 A^2 - B^2이 됨을
이용해 구할 수 있다. 제곱을 2번 하기 때문에 계수가 매우 커질 수 있음에 유의한다.
또한, D가 0인 경우 예외적인 상황이 많이 나오기 때문에 주의해야 한다.
마지막으로 약분을 해줘야 하는 것도 잊어선 안 된다.

주요 알고리즘 : 수학, 구현, 케이스 워크
*/

typedef struct frac {
    long long a, b, c, d;
} frac;

typedef struct comp {
    frac f0;
    frac f1;
} comp;

const comp comp_zero = { {1, 0, 0, 0}, {1, 0, 0, 0} }; //0
const comp comp_one = { {1, 1, 0, 0}, {1, 0, 0, 0} }; //1
const comp comp_two = { {1, 2, 0, 0}, {1, 0, 0, 0} }; //2
const comp comp_mone = { {1, -1, 0, 0}, {1, 0, 0, 0} }; //-1
const comp comp_sqrt2 = { {1, 1, 1, 2}, {1, 0, 0, 0} }; //sqrt(2)
const comp comp_imag1 = { {1, 0, 0, 0}, {1, 1, 0, 0} }; //i

long long gcd(long long a, long long b) {
    //최대공약수 함수, 음수는 양수로 변환하여 처리
    a = llabs(a), b = llabs(b);
    if (a == 0) return b;
    if (b == 0) return a;
    return a > b ? gcd(a % b, b) : gcd(a, b % a);
}

long long highestsqr(long long a) {
    //A의 약수 가운데 가장 큰 제곱수의 제곱을 반환
    assert(a == 0 || a > 1);
    long long r = 1;
    for (long long i = 2; i * i <= a; i++) {
        if (a % (i * i) == 0) r = i;
    }
    return r;
}

int verifycomp(comp x) {
    //주어진 복소수가 조건을 만족하는 지 확인, 만족하면 0, 만족하지 않으면 다른 수 반환
    //분모가 0 이하거나 D가 0 미만 또는 1일 시 1 반환
    //약분이 되지 않았을 시 2 반환
    //C와 D 중 하나만 0인 경우 3 반환
    //D에 제곱수인 약수가 있을 경우 4 반환
    //절댓값이 10^16을 넘는 수가 있다면 5 반환
    if (x.f0.a <= 0 || x.f1.a <= 0 || x.f0.d < 0 || x.f1.d < 0 || x.f0.d == 1 || x.f1.d == 1) return 1;
    if (gcd(gcd(x.f0.a, x.f0.b), x.f0.c) > 1 || gcd(gcd(x.f1.a, x.f1.b), x.f1.c) > 1) return 2;
    if (((!!x.f0.c) ^ (!!x.f0.d)) || ((!!x.f1.c) ^ (!!x.f1.d))) return 3;
    if ((x.f0.d > 0 && highestsqr(x.f0.d) > 1) || (x.f1.d > 0 && highestsqr(x.f1.d) > 1)) return 4;
    if (llabs(x.f0.a) > HH || llabs(x.f0.b) > HH || llabs(x.f0.c) > HH || llabs(x.f0.d) > HH ||
        llabs(x.f1.a) > HH || llabs(x.f1.b) > HH || llabs(x.f1.c) > HH || llabs(x.f1.d) > HH) return 5;
    return 0;
}

void printcomp(comp x) {
    //주어진 복소수를 출력한다. 오류가 있다면 오류를 알리고 출력한 후 프로그램을 종료시킨다.
    if (verifycomp(x)) {
        printf("errorcode: %d\n", verifycomp(x));
        printf("%lld %lld %lld %lld ", x.f0.a, x.f0.b, x.f0.c, x.f0.d);
        printf("%lld %lld %lld %lld\n", x.f1.a, x.f1.b, x.f1.c, x.f1.d);
        exit(verifycomp(x));
    }

    printf("%lld %lld %lld %lld ", x.f0.a, x.f0.b, x.f0.c, x.f0.d);
    printf("%lld %lld %lld %lld\n", x.f1.a, x.f1.b, x.f1.c, x.f1.d);
}

int ccmp(comp x, comp y) {
    //두 복소수가 같은 지 여부를 확인한다.
    if (x.f0.a != y.f0.a || x.f0.b != y.f0.b || x.f0.c != y.f0.c || x.f0.d != y.f0.d ||
        x.f1.a != y.f1.a || x.f1.b != y.f1.b || x.f1.c != y.f1.c || x.f1.d != y.f1.d) return 1;
    return 0;
}

frac fplus(frac x, frac y) {
    //무리수 X와 Y의 합을 구한다.
    long long g;
    assert(x.d == 0 || y.d == 0 || x.d == y.d); //두 D가 모두 0보다 크고 두 D가 서로 달라선 안 된다.
    frac r = { 1, };
    r.a = x.a * y.a;
    r.b = x.b * y.a + x.a * y.b;
    r.c = x.c * y.a + x.a * y.c;
    g = gcd(gcd(r.a, r.b), r.c); //약분한다.
    if (g > 1) {
        r.a /= g;
        r.b /= g;
        r.c /= g;
    }
    r.d = x.d;
    if (r.c == 0) r.d = 0; //D가 0인 경우를 처리한다.
    else if (x.d == 0) r.d = y.d;
    return r;
}

comp cplus(comp x, comp y) {
    //복소수 X와 Y의 합을 구한다.
    comp r = { 0, };
    r.f0 = fplus(x.f0, y.f0);
    r.f1 = fplus(x.f1, y.f1);
    return r;
}

frac frev(frac x) {
    //무리수 X에 -1을 곱한 값을 반환한다.
    x.b *= -1, x.c *= -1;
    return x;
}

comp crev(comp x) {
    //복소수 X에 -1을 곱한 값을 반환한다.
    x.f0.b *= -1, x.f0.c *= -1;
    x.f1.b *= -1, x.f1.c *= -1;
    return x;
}

frac fminus(frac x, frac y) {
    //두 무리수 X, Y에 대해 X - Y의 값을 반환한다.
    return fplus(x, frev(y));
}

comp cminus(comp x, comp y) {
    //두 복소수 X, Y에 대해 X - Y의 값을 반환한다.
    comp r = { 0, };
    r.f0 = fminus(x.f0, y.f0);
    r.f1 = fminus(x.f1, y.f1);
    return r;
}

frac fmult(frac x, frac y) {
    //두 무리수 X, Y에 대해 X * Y의 값을 반환한다.
    assert(x.d == 0 || y.d == 0 || x.d == y.d); //두 D가 모두 0보다 크고 두 D가 서로 달라선 안 된다.
    frac r = { 1, };
    r.a = x.a * y.a;
    r.b = x.b * y.b;
    //두 D의 0 여부에 따라 경우를 나누어 푼다.
    if (x.d == 0 && y.d == 0) {
        r.c = 0;
        r.d = 0;
    }
    else if (x.d == 0) {
        r.d = y.d;
        r.c = x.b * y.c;
    }
    else if (y.d == 0) {
        r.d = x.d;
        r.c = x.c * y.b;
    }
    else {
        r.d = x.d;
        r.c = x.c * y.b + x.b * y.c;
        r.b += x.c * y.c * r.d;
    }
    if (r.c == 0) r.d = 0;

    long long g = gcd(gcd(r.a, r.b), r.c); //약분한다.
    if (g > 1) {
        r.a /= g;
        r.b /= g;
        r.c /= g;
    }
    return r;
}

comp cmult(comp x, comp y) {
    //두 복소수 X, Y에 대해 X * Y의 값을 반환한다.
    comp r = { 0, };
    r.f0 = fminus(fmult(x.f0, y.f0), fmult(x.f1, y.f1));
    r.f1 = fplus(fmult(x.f0, y.f1), fmult(x.f1, y.f0));
    return r;
}

comp cupsidedown(comp x) {
    //복소수 X의 역수를 반환한다. 식 전개를 통해 정리한 결과이다.
    long long d = x.f0.d;
    if (d == 0) d = x.f1.d;
    long long p = (x.f1.a * x.f1.a * x.f0.b * x.f0.b) + (x.f0.a * x.f0.a * x.f1.b * x.f1.b);
    p += d * ((x.f1.a * x.f1.a * x.f0.c * x.f0.c) + (x.f0.a * x.f0.a * x.f1.c * x.f1.c));
    long long q = 2 * (x.f1.a * x.f1.a * x.f0.b * x.f0.c + x.f0.a * x.f0.a * x.f1.b * x.f1.c);
    comp r = { {p * p - d * q * q, x.f0.a * x.f1.a, 0, 0}, {1, 0, 0, 0} };
    comp t = { {1, p, -q, d}, {1, 0, 0, 0} };
    r = cmult(r, t);
    comp t2 = { {1, x.f1.a * x.f0.b, x.f1.a * x.f0.c, d}, {1, -x.f0.a * x.f1.b, -x.f0.a * x.f1.c, d} };
    r = cmult(r, t2);

    long long g = gcd(gcd(r.f0.a, r.f0.b), r.f0.c);
    if (g > 1) {
        r.f0.a /= g;
        r.f0.b /= g;
        r.f0.c /= g;
    }
    g = gcd(gcd(r.f1.a, r.f1.b), r.f1.c);
    if (g > 1) {
        r.f1.a /= g;
        r.f1.b /= g;
        r.f1.c /= g;
    }
    return r;
}

comp cdiv(comp x, comp y) {
    //두 복소수 X, Y에 대해 X / Y의 값을 반환한다.
    return cmult(x, cupsidedown(y));
}

void randomize(comp* x, comp* y) {
    //X와 Y의 값을 조건에 맞는 임의의 복소수로 바꾼다.
    x->f0.a = rand() % 10 + 1;
    x->f1.a = rand() % 10 + 1;
    y->f0.a = rand() % 10 + 1;
    y->f1.a = rand() % 10 + 1;
    x->f0.d = rand() % 10 + 1;
    if (x->f0.d == 1) {
        //D가 0일 때
        x->f0.d = 0;
        x->f1.d = x->f0.d, y->f0.d = x->f0.d, y->f1.d = x->f0.d;
        x->f0.c = x->f0.d, x->f1.c = x->f0.d, y->f0.c = x->f0.d, y->f1.c = x->f0.d;
    }
    else {
        //D가 0이 아닐 때
        x->f1.d = x->f0.d, y->f0.d = x->f0.d, y->f1.d = x->f0.d;
        x->f0.c = rand() % 20 + 1;
        x->f1.c = rand() % 20 + 1;
        y->f0.c = rand() % 20 + 1;
        y->f1.c = rand() % 20 + 1;
        if (x->f0.c > 10) x->f0.c -= 21;
        if (x->f1.c > 10) x->f1.c -= 21;
        if (y->f0.c > 10) y->f0.c -= 21;
        if (y->f1.c > 10) y->f1.c -= 21;
    }
    x->f0.b = rand() % 21 - 10;
    x->f1.b = rand() % 21 - 10;
    y->f0.b = rand() % 21 - 10;
    y->f1.b = rand() % 21 - 10;


    x->f0.a /= 2, x->f0.b /= 2, x->f0.c /= 2, x->f0.d /= 2;
    x->f1.a /= 2, x->f1.b /= 2, x->f1.c /= 2, x->f1.d /= 2;
    y->f0.a /= 2, y->f0.b /= 2, y->f0.c /= 2, y->f0.d /= 2;
    y->f1.a /= 2, y->f1.b /= 2, y->f1.c /= 2, y->f1.d /= 2;
}

void randomcheck(long long cnt) {
    //cnt번 임의의 복소수를 통해 계산한 답이 맞는 지 확인한다.
    comp x = { 0, }, y = { 0, };
    srand((unsigned)time(NULL));
    for (long long i = 0; i < cnt; i++) {
        randomize(&x, &y);

        if (verifycomp(x) || verifycomp(y) || ccmp(y, comp_zero) == 0) {
            i--;
            continue;
        }

        if (ccmp(cplus(comp_zero, x), x)) {
            printf("X + 0 != X\n");
            printcomp(x);
            exit(-1);
        }
        if (ccmp(cminus(cplus(x, y), y), x)) {
            printf("(X + Y) - Y != X\n");
            printcomp(x);
            printcomp(y);
            printcomp(cplus(x, y));
            printcomp(cminus(cplus(x, y), y));
            exit(-2);
        }
        if (ccmp(cplus(cplus(x, y), cminus(x, y)), cplus(x, x))) {
            printf("(X + Y) + (X - Y) != (X + X)\n");
            printcomp(x);
            printcomp(y);
            printcomp(cplus(x, y));
            printcomp(cminus(x, y));
            printcomp(cplus(cplus(x, y), cminus(x, y)));
            exit(-3);
        }
        if (ccmp(cmult(x, comp_one), x)) {
            printf("X * 1 != X\n");
            printcomp(x);
            printcomp(cmult(x, comp_one));
            exit(-4);
        }
        if (ccmp(cmult(x, comp_two), cplus(x, x))) {
            printf("X * 2 != X + X\n");
            printcomp(x);
            printcomp(cmult(x, comp_two));
            printcomp(cplus(x, x));
            exit(-5);
        }
        if (ccmp(cmult(cmult(x, comp_imag1), comp_imag1), crev(x))) {
            printf("(X * i) * i != -X\n");
            printcomp(x);
            printcomp(cmult(x, comp_imag1));
            printcomp(cmult(cmult(x, comp_imag1), comp_imag1));
            printcomp(crev(x));
            exit(-6);
        }
        if (ccmp(cmult(cdiv(x, y), y), x)) {
            printf("((X / Y) * Y) != X\n");
            printcomp(x);
            printcomp(y);
            printcomp(cdiv(x, y));
            printcomp(cmult(cdiv(x, y), y));
            exit(-7);
        }
        if (ccmp(cdiv(cmult(x, y), y), x)) {
            printf("((X * Y) / Y) != X\n");
            printcomp(x);
            printcomp(y);
            printcomp(cmult(x, y));
            printcomp(cdiv(cmult(x, y), y));
            exit(-8);
        }
    }
}

int main(void) {
    comp x = { 0, }, y = { 0, };
    //randomcheck(103000);
    //return 1;
    scanf("%lld %lld %lld %lld", &x.f0.a, &x.f0.b, &x.f0.c, &x.f0.d);
    scanf("%lld %lld %lld %lld", &x.f1.a, &x.f1.b, &x.f1.c, &x.f1.d);
    scanf("%lld %lld %lld %lld", &y.f0.a, &y.f0.b, &y.f0.c, &y.f0.d);
    scanf("%lld %lld %lld %lld", &y.f1.a, &y.f1.b, &y.f1.c, &y.f1.d);
    assert(verifycomp(x) == 0 && verifycomp(y) == 0);
    assert(x.f0.d == x.f1.d && y.f0.d == y.f1.d && x.f0.d == y.f1.d);

    printcomp(cplus(x, y));
    printcomp(cplus(x, crev(y)));
    printcomp(cmult(x, y));
    printcomp(cdiv(x, y));
    return 0;
}