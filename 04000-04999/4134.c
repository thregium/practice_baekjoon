#include <stdio.h>

/*
���� : 4 * 10^9 ������ ���� �ƴ� ���� N�� �־��� ��, �� ���� ���ų� ũ�鼭 �Ҽ��� ���� ���� ���� ���Ѵ�.

�ذ� ��� : �����佺�׳׽��� ü�� �̿��� 65536 ������ ��� �Ҽ��� ���� ��, N �̻��� ������ �׷��� �Ҽ���� ���� ������ ����.
���� ������ �������� ��찡 �ִٸ� �Ҽ��� �ƴ� ���̹Ƿ� ���� ���� ����, ���ٸ� �Ҽ��̹Ƿ� ����ϸ� �ȴ�.

�ֿ� �˰��� : ����, ������, �����佺�׳׽�

��ó : Waterloo 120715 B��
*/

char sieve[65536];
int prime[8192];
int pp = 0;

int main(void) {
    int t, x;
    long long n;
    for (int i = 2; i < 65536; i++) {
        if (sieve[i]) continue;
        prime[pp++] = i;
        for (int j = i * 2; j < 65536; j += i) sieve[j] = 1;
    }
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%lld", &n);
        if (n <= 1) {
            printf("2\n");
            continue;
        }
        for (long long i = n;; i++) {
            x = 1;
            for (int j = 0; (long long)prime[j] * prime[j] <= i; j++) {
                if (i % prime[j] == 0) {
                    x = 0;
                    break;
                }
                if (j >= 65536) return 1;
            }
            if (x) {
                printf("%lld\n", i);
                break;
            }
        }
    }
    return 0;
}