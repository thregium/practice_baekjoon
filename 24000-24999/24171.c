#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <assert.h>
#define HH 1E18

/*
���� : �Ǽ��ο� ����ΰ� ���� (b + c * sqrt(d)) / a�� ���·� �̷���� X, Y��� �� ���Ҽ��� �־�����.
�̶�, X + Y, X - Y, X * Y, X / Y�� ���� ���� ���Ѵ�. ��� ����� 10 ���ϰ�, ��� a�� 0���� ũ��,
��� d�� 0 �Ǵ� 2 �̻��� �ڿ����̴�. �׸���, d�� 0�� ��� �׿� �´� c�� 0�̸�, ��� d�� ����.
���������� gcd(a, b, c)�� 2 ���ϰ� �Ǿ �� �ǰ�, d�� ���� ū �������� ����� 1�̾�� �Ѵ�.
�� ��� ������ ��°����� ����ȴ�.

�ذ� ��� : �� ���Ҽ��� ����ü�� ���� ���� ���Ҽ��� ���� �� ������ ���� ���ϴ� �Լ��� �����.
�������� ��� ������ ���ϴ� �Լ��� ����� �ذ� �����ϴ�. ������ (A + B)(A - B)�� A^2 - B^2�� ����
�̿��� ���� �� �ִ�. ������ 2�� �ϱ� ������ ����� �ſ� Ŀ�� �� ������ �����Ѵ�.
����, D�� 0�� ��� �������� ��Ȳ�� ���� ������ ������ �����ؾ� �Ѵ�.
���������� ����� ����� �ϴ� �͵� �ؾ �� �ȴ�.

�ֿ� �˰��� : ����, ����, ���̽� ��ũ
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
    //�ִ����� �Լ�, ������ ����� ��ȯ�Ͽ� ó��
    a = llabs(a), b = llabs(b);
    if (a == 0) return b;
    if (b == 0) return a;
    return a > b ? gcd(a % b, b) : gcd(a, b % a);
}

long long highestsqr(long long a) {
    //A�� ��� ��� ���� ū �������� ������ ��ȯ
    assert(a == 0 || a > 1);
    long long r = 1;
    for (long long i = 2; i * i <= a; i++) {
        if (a % (i * i) == 0) r = i;
    }
    return r;
}

int verifycomp(comp x) {
    //�־��� ���Ҽ��� ������ �����ϴ� �� Ȯ��, �����ϸ� 0, �������� ������ �ٸ� �� ��ȯ
    //�и� 0 ���ϰų� D�� 0 �̸� �Ǵ� 1�� �� 1 ��ȯ
    //����� ���� �ʾ��� �� 2 ��ȯ
    //C�� D �� �ϳ��� 0�� ��� 3 ��ȯ
    //D�� �������� ����� ���� ��� 4 ��ȯ
    //������ 10^16�� �Ѵ� ���� �ִٸ� 5 ��ȯ
    if (x.f0.a <= 0 || x.f1.a <= 0 || x.f0.d < 0 || x.f1.d < 0 || x.f0.d == 1 || x.f1.d == 1) return 1;
    if (gcd(gcd(x.f0.a, x.f0.b), x.f0.c) > 1 || gcd(gcd(x.f1.a, x.f1.b), x.f1.c) > 1) return 2;
    if (((!!x.f0.c) ^ (!!x.f0.d)) || ((!!x.f1.c) ^ (!!x.f1.d))) return 3;
    if ((x.f0.d > 0 && highestsqr(x.f0.d) > 1) || (x.f1.d > 0 && highestsqr(x.f1.d) > 1)) return 4;
    if (llabs(x.f0.a) > HH || llabs(x.f0.b) > HH || llabs(x.f0.c) > HH || llabs(x.f0.d) > HH ||
        llabs(x.f1.a) > HH || llabs(x.f1.b) > HH || llabs(x.f1.c) > HH || llabs(x.f1.d) > HH) return 5;
    return 0;
}

void printcomp(comp x) {
    //�־��� ���Ҽ��� ����Ѵ�. ������ �ִٸ� ������ �˸��� ����� �� ���α׷��� �����Ų��.
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
    //�� ���Ҽ��� ���� �� ���θ� Ȯ���Ѵ�.
    if (x.f0.a != y.f0.a || x.f0.b != y.f0.b || x.f0.c != y.f0.c || x.f0.d != y.f0.d ||
        x.f1.a != y.f1.a || x.f1.b != y.f1.b || x.f1.c != y.f1.c || x.f1.d != y.f1.d) return 1;
    return 0;
}

frac fplus(frac x, frac y) {
    //������ X�� Y�� ���� ���Ѵ�.
    long long g;
    assert(x.d == 0 || y.d == 0 || x.d == y.d); //�� D�� ��� 0���� ũ�� �� D�� ���� �޶� �� �ȴ�.
    frac r = { 1, };
    r.a = x.a * y.a;
    r.b = x.b * y.a + x.a * y.b;
    r.c = x.c * y.a + x.a * y.c;
    g = gcd(gcd(r.a, r.b), r.c); //����Ѵ�.
    if (g > 1) {
        r.a /= g;
        r.b /= g;
        r.c /= g;
    }
    r.d = x.d;
    if (r.c == 0) r.d = 0; //D�� 0�� ��츦 ó���Ѵ�.
    else if (x.d == 0) r.d = y.d;
    return r;
}

comp cplus(comp x, comp y) {
    //���Ҽ� X�� Y�� ���� ���Ѵ�.
    comp r = { 0, };
    r.f0 = fplus(x.f0, y.f0);
    r.f1 = fplus(x.f1, y.f1);
    return r;
}

frac frev(frac x) {
    //������ X�� -1�� ���� ���� ��ȯ�Ѵ�.
    x.b *= -1, x.c *= -1;
    return x;
}

comp crev(comp x) {
    //���Ҽ� X�� -1�� ���� ���� ��ȯ�Ѵ�.
    x.f0.b *= -1, x.f0.c *= -1;
    x.f1.b *= -1, x.f1.c *= -1;
    return x;
}

frac fminus(frac x, frac y) {
    //�� ������ X, Y�� ���� X - Y�� ���� ��ȯ�Ѵ�.
    return fplus(x, frev(y));
}

comp cminus(comp x, comp y) {
    //�� ���Ҽ� X, Y�� ���� X - Y�� ���� ��ȯ�Ѵ�.
    comp r = { 0, };
    r.f0 = fminus(x.f0, y.f0);
    r.f1 = fminus(x.f1, y.f1);
    return r;
}

frac fmult(frac x, frac y) {
    //�� ������ X, Y�� ���� X * Y�� ���� ��ȯ�Ѵ�.
    assert(x.d == 0 || y.d == 0 || x.d == y.d); //�� D�� ��� 0���� ũ�� �� D�� ���� �޶� �� �ȴ�.
    frac r = { 1, };
    r.a = x.a * y.a;
    r.b = x.b * y.b;
    //�� D�� 0 ���ο� ���� ��츦 ������ Ǭ��.
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

    long long g = gcd(gcd(r.a, r.b), r.c); //����Ѵ�.
    if (g > 1) {
        r.a /= g;
        r.b /= g;
        r.c /= g;
    }
    return r;
}

comp cmult(comp x, comp y) {
    //�� ���Ҽ� X, Y�� ���� X * Y�� ���� ��ȯ�Ѵ�.
    comp r = { 0, };
    r.f0 = fminus(fmult(x.f0, y.f0), fmult(x.f1, y.f1));
    r.f1 = fplus(fmult(x.f0, y.f1), fmult(x.f1, y.f0));
    return r;
}

comp cupsidedown(comp x) {
    //���Ҽ� X�� ������ ��ȯ�Ѵ�. �� ������ ���� ������ ����̴�.
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
    //�� ���Ҽ� X, Y�� ���� X / Y�� ���� ��ȯ�Ѵ�.
    return cmult(x, cupsidedown(y));
}

void randomize(comp* x, comp* y) {
    //X�� Y�� ���� ���ǿ� �´� ������ ���Ҽ��� �ٲ۴�.
    x->f0.a = rand() % 10 + 1;
    x->f1.a = rand() % 10 + 1;
    y->f0.a = rand() % 10 + 1;
    y->f1.a = rand() % 10 + 1;
    x->f0.d = rand() % 10 + 1;
    if (x->f0.d == 1) {
        //D�� 0�� ��
        x->f0.d = 0;
        x->f1.d = x->f0.d, y->f0.d = x->f0.d, y->f1.d = x->f0.d;
        x->f0.c = x->f0.d, x->f1.c = x->f0.d, y->f0.c = x->f0.d, y->f1.c = x->f0.d;
    }
    else {
        //D�� 0�� �ƴ� ��
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
    //cnt�� ������ ���Ҽ��� ���� ����� ���� �´� �� Ȯ���Ѵ�.
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