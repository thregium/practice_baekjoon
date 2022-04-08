#include <stdio.h>

/*
���� : �ڿ��� N(2 <= N <= 10^18)�� �־��� ��, N ������ �ڿ��� ��� �� �ڿ����� ����
p / q�� �� �ڿ��� ������ �ڿ��� ��� �� �ڿ����� ���μҰ� �ƴ� �ڿ����� ������ �������� ��,
p / q�� �ִ��� ���� p / q�� ���м� ���·� ����Ѵ�.

�ذ� ��� : ���� p / q�� ���غ��� �� N�� ���� N�� ������ ���� �ٸ� ���μ� ����(p_i)�� ����
(p_i - 1) / p_i�� ���� ���� 1���� �� �Ͱ� ������ �� �� �ִ�.
����, �� ���� �ִ��� �����ϴ� ���� N�� 2���� ���� �ٸ� �Ҽ����� ������ ���� �� ���̰�,
�̷��� ���� �ִ� 15�����̹Ƿ� 15���� ��츸 ����ؼ� ������ ���� ����ϸ� �ȴ�.

�ֿ� �˰��� : ����, ������

��ó : NAQ 2021 C��
*/

long long primes[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 10 };

long long gcd(long long a, long long b) {
    if (a == 0) return b;
    if (b == 0) return a;
    return a > b ? gcd(a % b, b) : gcd(a, b % a);
}

int main(void) {
    long long n, mt = 1, cnt = -1, up = 1, down = 1, g;
    scanf("%lld", &n);
    for (int i = 0; i < 16; i++) {
        mt *= primes[i];
        if (mt > n) {
            mt /= primes[i];
            cnt = i;
            break;
        }
    }
    if (cnt < 0) return 1;
    for (int i = 0; i < cnt; i++) {
        up *= primes[i] - 1;
        down *= primes[i];
    }
    up = down - up;
    g = gcd(up, down);
    printf("%lld/%lld", up / g, down / g);
    return 0;
}