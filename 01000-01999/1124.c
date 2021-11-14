#include <stdio.h>

/*
���� : A�� B(A <= B <= 100000) ������ �� ��� ���μ��� ������ �Ҽ��� ���� ������ ���Ѵ�.

�ذ� ��� : �����佺�׳׽��� ü�� �̿��� ���μ��� ������ �Ҽ� ���θ� �̸� ���ص� ����,
A�� B ���� ������ ���鼭 ���μ��� ������ �Ҽ��� ������ ���� �ȴ�.

�ֿ� �˰��� : ����, ������, �����佺�׳׽�

��ó : SRM 442 D1A / D2B
*/

char sieve[103000];
int cnt[103000];

int main(void) {
    int a, b, r = 0;
    sieve[1] = 1;
    for (int i = 2; i <= 100000; i++) {
        if (sieve[i]) continue;
        cnt[i] = 1;
        for (int j = i * 2; j <= 100000; j += i) {
            for (int k = j; k % i == 0; k /= i) cnt[j]++;
            sieve[j] = 1;
        }
    }
    scanf("%d %d", &a, &b);
    for (int i = a; i <= b; i++) {
        if (!sieve[cnt[i]]) r++;
    }
    printf("%d", r);
    return 0;
}