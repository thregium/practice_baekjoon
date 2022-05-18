#include <stdio.h>

/*
���� : ���簢�� ������ ���̸� �ִ� 2���� ũ��� �߶� ���� ũ���� ���̸� N(N < 2^32)�� ����� ����
�߶�� �ϴ� �ּ� Ƚ���� ���Ѵ�.

�ذ� ��� : ������� ����� ���� �ذ� �����ϴ�. �ڼ��� ���� �ڵ带 �����Ѵ�.

�ֿ� �˰��� : ����, ���

��ó : ���縯�� 1ȸD2 A��
*/

long long hard[4] = { 0, 1, 3, 3 };

long long getres(long long x) {
    if (x <= 3) return hard[x];
    else if ((x >> 1) & 1) return getres(x >> 1) * 2 + 1;
    else return getres(x >> 1) * 2;
}

int main(void) {
    long long n;
    scanf("%lld", &n);
    printf("%lld", getres(n - 1));
    return 0;
}