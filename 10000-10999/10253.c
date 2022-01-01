#include <stdio.h>

/*
���� : �м� a / b(1 <= a < b <= 10000, a, b�� �ڿ���)�� �־��� ��, �־��� �˰����� �̿��� �����м��� ������ �ٲ۴ٸ�,
���� ���� �����м��� �и� ���Ѵ�. �־��� �˰����� a / b ������ ���� ū �����м��� ���� ���� �ݺ��ϴ� ���̴�.

�ذ� ��� : ������ �־��� ��Ĵ�� a / b ������ ���� ū �����м��� �������� �����м��� �� �� ���� �ݺ��ϸ� �ȴ�.
��, �� �������� ����� ����� �Կ� �����Ѵ�. ���� ū �����м��� �и�� ceil(b / a)�� ���� ���� �� �ִ�.

�ֿ� �˰��� : ����, ������, ��Ŭ���� ȣ����, �ùķ��̼�

��ó : Daejeon 2014 D��
*/

long long gcd(long long a, long long b) {
    if (a == 0) return b;
    if (b == 0) return a;
    return a > b ? gcd(a % b, b) : gcd(a, b % a);
}

int main(void) {
    int t;
    long long a, b, g, s;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%lld %lld", &a, &b);
        g = gcd(a, b);
        a /= g, b /= g;
        while (a > 1) {
            s = (b + a - 1) / a;
            b *= s, a *= s;
            a -= b / s;
            g = gcd(a, b);
            a /= g, b /= g;
        }
        printf("%lld\n", b);
    }
    return 0;
}