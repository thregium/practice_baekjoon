#include <stdio.h>

/*
���� : �տ������� �� �ڸ��� ��� �Ҽ��� �Ǵ� N(N <= 8)�ڸ� ���� ���Ѵ�.

�ذ� ��� : ������ ���� �ִ� 1���̹Ƿ� 1�������� ��� �Ҽ��� �̸� �����ش�. �� �ڷδ� ù �ڸ����� ��Ʈ��ŷ�� ����
N��° �ڸ����� ����ؼ� ��� �ڸ��� �Ҽ��� �Ǵ� ������ �����ָ� �ȴ�.

�ֿ� �˰��� : ����, �Ҽ� ����, ��Ʈ��ŷ
*/

int primes[2048], sieve[10240];
int pp = 0;

void track(int n, int c, int r) {
    if (n == c) {
        printf("%d\n", r);
        return;
    }
    int t;

    for (int i = 0; i < 10; i++) {
        if (c < 4) {
            if (sieve[r * 10 + i]) continue; //���� �ڸ��� i�� ������ �Ҽ��� �ƴ� ���
            track(n, c + 1, r * 10 + i);
        }
        else {
            t = 0;
            for (int j = 0; j < pp; j++) {
                if ((r * 10 + i) % primes[j] == 0) t++;
            }
            if (t) continue; //���� �ڸ��� i�� ������ �Ҽ��� �ƴ� ���
            track(n, c + 1, r * 10 + i);
        }
    }
}

int main(void) {
    int n;
    sieve[0] = 1;
    sieve[1] = 1;
    for (int i = 2; i <= 10000; i++) {
        if (sieve[i]) continue;
        primes[pp++] = i;
        for (int j = i * 2; j <= 10000; j += i) {
            sieve[j]++;
        }
    }
    scanf("%d", &n);
    track(n, 0, 0);
    return 0;
}