#include <stdio.h>

/*
���� : �ڿ��� K(7 <= K <= 1000)�� �־����� ��, �� �Ҽ��� ���ؼ� �� ���� ����� ����� ������������ ����Ѵ�.

�ذ� ��� : �̸� �Ҽ��� ã�Ƶ� ����, ��� ��츦 Ȯ���غ��� �ȴ�.

�ֿ� �˰��� : ����, �����佺�׳׽�, ���Ʈ ����

��ó : Daejeon 2015 J��
*/

char sieve[1024];

int main(void) {
    int t, k, r;
    for (int i = 2; i <= 1000; i++) {
        if (sieve[i]) continue;
        for (int j = i * 2; j <= 1000; j += i) sieve[j] = 1;
    }
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &k);
        r = 0;
        for (int i = 2; i <= k; i++) {
            if (sieve[i]) continue;
            for (int j = i; j <= k - i - j; j++) {
                if (sieve[j] || sieve[k - i - j]) continue;
                printf("%d %d %d\n", i, j, k - i - j);
                r = 1;
                break;
            }
            if (r) break;
        }
        if (!r) return 1;
    }
    return 0;
}