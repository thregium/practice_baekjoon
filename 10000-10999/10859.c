#include <stdio.h>

/*
���� : �ڿ��� N(N <= 10^16)�� �־��� ��, �� �ڿ����� �Ҽ��̰� 180�� ������ �Ҽ��� �� ���Ѵ�.
������ ���� �ƴ϶�� �Ҽ��� �ƴϴ�.

�ذ� ��� : �ڿ����� ���ڸ����� �ϳ��� ���� ���� Ȯ���ϸ鼭 �������� ���� �����.
�� �������� �ڸ����� 3, 4, 7�� �ִٸ� ���� �ƴϹǷ� �� ����� ����صд�.
�Ҽ� ������ 2���� sqrt(N)���� Ȯ���ϸ鼭 ������ �������� ��찡 �ִ� �� Ȯ���ϸ� �ȴ�.

�ֿ� �˰��� : ����, �Ҽ� ����, ����

��ó : GCPC 2015 K��
*/

int isprime(long long x) {
    if (x <= 1) return 0;
    for (long long i = 2; i * i <= x; i++) {
        if (x % i == 0) return 0;
    }
    return 1;
}

int main(void) {
    long long n, rv = 0, val = 1, rs = 1;
    scanf("%lld", &n);
    rs &= isprime(n);
    while (n) {
        rv *= 10;
        if (n % 10 == 0 || n % 10 == 1 || n % 10 == 2 || n % 10 == 5 || n % 10 == 8) rv += n % 10;
        else if (n % 10 == 6) rv += 9;
        else if (n % 10 == 9) rv += 6;
        else val = 0;
        n /= 10;
    }
    rs &= val;
    rs &= isprime(rv);
    printf("%s", rs ? "yes" : "no");
    return 0;
}