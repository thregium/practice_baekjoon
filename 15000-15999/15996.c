#include <stdio.h>

/*
���� : N(N < 2^31)!�� A�� �ִ� �� �� ���� �� �ִ��� ���Ѵ�.

�ذ� ��� : N / A���� A�� �������� 0�� �� �� ���� ���� ���� ���̴�.

�ֿ� �˰��� : ����, ������
*/

int main(void) {
    long long n, r = 0, a;
    scanf("%lld %lld", &n, &a);
    for (int i = n / a; i; i /= a) r += i;
    printf("%lld", r);
    return 0;
}