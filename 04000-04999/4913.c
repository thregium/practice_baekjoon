#include <stdio.h>

/*
���� : [L, U](-10^6 < L <= U < 10^6) ������ �Ҽ��� ������
�� �ڿ����� ������ ��Ÿ�� �� �ִ� �Ҽ��� ������ ���� ���Ѵ�. �̸� (<= 1000)ȸ �ݺ��Ѵ�.

�ذ� ��� : �� ������ �Ҽ��� ������ �����佺�׳׽��� ü�� ������ ���� �� �ְ�,
�� �ڿ����� ������ ��Ÿ�� �� �ִ� ���� ���Ʈ ������ ���� �� �ִ�.
T�� ���� ������ ���� ���� �̿��� ����� ����ȭ��Ű�� �ȴ�.
L�̳� U�� ������ ���� 0�� ���� ���� ó���� �� �ִ�.

�ֿ� �˰��� : ����, �����佺�׳׽�, ���Ʈ ����, ���� ��

��ó : Arab 2007 E��
*/

int sieve[1048576], sqrsum[1048576];

int main(void) {
    int l, u;
    for (int i = 2; i <= 1000000; i++) {
        if (sieve[i]) continue;
        for (int j = i * 2; j <= 1000000; j += i) sieve[j] = 1;
    }
    for (int i = 1; i * i <= 1000000; i++) {
        for (int j = 1; i * i + j * j <= 1000000; j++) {
            if (!sieve[i * i + j * j]) sqrsum[i * i + j * j] = 1;
        }
    }
    for (int i = 2; i <= 1000000; i++) sieve[i] = (!sieve[i]) + sieve[i - 1];
    for (int i = 2; i <= 1000000; i++) sqrsum[i] += sqrsum[i - 1];
    while (1) {
        scanf("%d %d", &l, &u);
        if (l == -1 && u == -1) break;
        printf("%d %d ", l, u);
        if (l < 1) l = 1;
        if (u < 1) u = 1;
        printf("%d %d\n", sieve[u] - sieve[l - 1], sqrsum[u] - sqrsum[l - 1]);
    }
    return 0;
}