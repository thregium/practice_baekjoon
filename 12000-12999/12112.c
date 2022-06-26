#include <stdio.h>
#include <stdlib.h>

/*
���� : [A, B](A <= B <= 10^7) ������ ���� ���� �� ���� ������� ���� ���� ���Ѵ�.

�ذ� ��� : 1���� B������ �ڿ����� ���� �� ���� ����鿡 ���� ������� ���� ���Ѵ�.
�� ���� A���� B���� Ȯ���� �����鼭 ������� �հ� �� ���� ���� ���̸� ���ؼ� ���س����� ���� �ȴ�.

�ֿ� �˰��� : ����, ������, ü

��ó : COCI 16/17#6 4��
*/

int sieve[10485760];

int main(void) {
    int a, b;
    long long res = 0;
    scanf("%d %d", &a, &b);
    for (int i = 1; i <= b; i++) {
        for (int j = i * 2; j <= b; j += i) sieve[j] += i;
    }
    for (int i = a; i <= b; i++) {
        res += abs(sieve[i] - i);
    }
    printf("%lld", res);
    return 0;
}