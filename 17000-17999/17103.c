#include <stdio.h>

/*
���� : 2���� ũ�� 10^6 ������ ¦�� N�� �־��� ��, ���ؼ� N�� �Ǵ� �Ҽ� ���� ������ ���Ѵ�. ������ �ٸ� ���� ���� ����̴�.

�ذ� ��� : 10^6 ������ ��� �Ҽ��� �����佺�׳׽��� ü�� ���� �ɷ�����. �׸��� 1���� N / 2���� Ȯ���ϸ�
N - i�� i�� ��� �Ҽ��� i�� ������ ���� �ȴ�.

�ֿ� �˰��� : ����, �����佺�׳׽�
*/

char sieve[1048576];

int main(void) {
    int t, n, r = 0;
    sieve[1] = 1;
    for (int i = 2; i <= 1000000; i++) {
        if (sieve[i]) continue;
        for (int j = i * 2; j <= 1000000; j += i) sieve[j] = 1;
    }
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &n);
        r = 0;
        for (int i = 1; i <= n - i; i++) {
            if (!(sieve[i] || sieve[n - i])) r++;
        }
        printf("%d\n", r);
    }
    return 0;
}