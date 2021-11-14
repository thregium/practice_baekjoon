#include <stdio.h>

/*
���� : �ڿ��� N(4 <= N <= 32000)�� �־��� ��, �� �Ҽ��� ��Ÿ���� ����� ��� ���Ѵ�. ������ �ٸ� ���� �����Ѵ�.

�ذ� ��� : �����佺�׳׽��� ü�� �̿��� �̸� 32000 ������ �Ҽ� ���θ� �����ص� ����, �Ź� N�� ���� �� ����
2���� N / 2������ ���� ���� i�� N - i�� ��� �Ҽ��� ���� ã���� �ȴ�.

�ֿ� �˰��� : ����, ������, �����佺�׳׽�

��ó : NAQ 2013 C��
*/

char sieve[32768];

int main(void) {
    int t, n, r;
    for (int i = 2; i <= 32000; i++) {
        if (sieve[i]) continue;
        for (int j = i * 2; j <= 32000; j += i) sieve[j] = 1;
    }
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &n);
        r = 0;
        for (int i = 2; i <= n - i; i++) {
            if (!sieve[i] && !sieve[n - i]) r++;
        }
        printf("%d has %d representation(s)\n", n, r);
        for (int i = 2; i <= n - i; i++) {
            if (!sieve[i] && !sieve[n - i]) {
                printf("%d+%d\n", i, n - i);
            }
        }
        printf("\n");
    }
    return 0;
}