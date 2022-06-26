#include <stdio.h>
#include <string.h>

/*
���� : FizzBuzz ���ڿ��� N(N <= 10^18)��°���� 20���� ���ڸ� ����Ѵ�.

�ذ� ��� : �� �� ������ ������ ������ ���� �Ű� ���� Ž���� �̿��Ͽ� ã�Ƴ� ����, �� ��ġ����
���� ���� ��°�� ���� ����ϸ� �ȴ�. �� ������ ������ ������ ������ �� ������ ������ Fizz, Buzz��
������ ���� ���ؼ� �� �� �ִ�.

�ֿ� �˰��� : ����, �Ķ��Ʈ��

��ó : JAG 2012S3B B��
*/

char s[32];

long long getdigits(long long n) {
    long long one = 0, three = 0, five = 0, fifteen = 0, fizz = 0, buzz = 0;
    for (long long i = 1; i <= n; i *= 10) one += n - i + 1;
    for (long long i = 1; i <= n; i *= 10) three += n / 3 - (i - 1) / 3;
    for (long long i = 1; i <= n; i *= 10) five += n / 5 - (i - 1) / 5;
    for (long long i = 1; i <= n; i *= 10) fifteen += n / 15 - (i - 1) / 15;
    fizz = n / 3 * 4;
    buzz = n / 5 * 4;
    return one - three - five + fifteen + fizz + buzz;
}

int main(void) {
    long long n, lo, hi, mid, pos;
    scanf("%lld", &n);
    for (int i = 0; i < 20; i++) {
        lo = 0, hi = 100000000000000000;
        while (lo < hi) {
            mid = (lo + hi + 1) >> 1;
            if (getdigits(mid) < n + i) lo = mid;
            else hi = mid - 1;
        }

        pos = n + i - getdigits(lo);
        if ((lo + 1) % 15 == 0) strcpy(s, "FizzBuzz");
        else if ((lo + 1) % 5 == 0) strcpy(s, "Buzz");
        else if ((lo + 1) % 3 == 0) strcpy(s, "Fizz");
        else sprintf(s, "%lld", lo + 1);
        printf("%c", s[pos - 1]);
    }
    printf("\n");
    return 0;
}