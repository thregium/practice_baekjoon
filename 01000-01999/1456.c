#include <stdio.h>

/*
���� : ���� [A, B](A <= B <= 10^14)���� �Ҽ��� N(N >= 2)�������� ǥ���Ǵ� ���� ������ ���Ѵ�.

�ذ� ��� : �����佺�׳׽��� ü�� �̿��� 2���� 10^7������ �Ҽ��� ���Ѵ�.
�� �Ҽ��鸶�� �ŵ����� ��� �Ҽ��� �ŵ��������� ǥ���Ǵ� ������ ���� ���� �ȴ�. �̶� �����÷ο� �����Ѵ�.

�ֿ� �˰��� : ����, �����佺�׳׽�

��ó : TCHS 33 3��
*/

char sieve[10485760];

int main(void) {
    long long a, b, r = 0;
    scanf("%lld %lld", &a, &b);
    for (int i = 2; i <= 10000000; i++) {
        if (sieve[i]) continue;
        for (long long j = (long long)i * i;; j *= i) {
            if (j <= b && j >= a) r++;
            if (b / i < j) break;
        }
        for (int j = i * 2; j <= 10000000; j += i) sieve[j] = 1;
    }
    printf("%lld", r);
    return 0;
}