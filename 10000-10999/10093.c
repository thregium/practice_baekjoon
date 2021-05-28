#include <stdio.h>

/*
���� : A�� B ������ ������ ������ �� ������ ���� ���Ѵ�.(A, B <= 10^15)(|A - B| <= 100000)

�ذ� ��� : A�� B���� ū ��� �� ���� �ٲ��ش�. �� �������� �� �� ���� ������ ������ ���Ѵ�.
A�� B�� ���� 1 ���϶�� 0�̰�, �� �ܿ��� A�� B�� �� - 1�̴�. �� ������ A + 1���� B - 1���� ��� ���� ����ϸ� �ȴ�.

�ֿ� �˰��� : ����

��ó : BOI 2014 P1��
*/

void swap(long long* a, long long* b) {
    long long t = *a;
    *a = *b;
    *b = t;
}

int main(void) {
    long long a, b;
    scanf("%lld %lld", &a, &b);
    if (a > b) swap(&a, &b);
    if (b < a + 2) printf("0\n");
    else printf("%lld\n", b - a - 1);
    for (long long i = a + 1; i < b; i++) {
        printf("%lld ", i);
    }
    return 0;
}