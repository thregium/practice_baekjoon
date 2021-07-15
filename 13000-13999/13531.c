#include <stdio.h>

/*
���� : ���� N(N <= 10^12)�� 1 ~ N���� �̷���� �������� i��° �� �� �ϳ��� i�� �� Ȯ���� ���Ѵ�.

�ذ� ��� : �� ���� ���� ���غ��� ������ �����ϴ� ���� �� �� �ִ�. ����, ���� ���� ���ؼ� �̸� ���� ���ص� ��
�� �̻��� ���� ���ص� ������ ������ ����ϸ� �ȴ�.

�ֿ� �˰��� : ����, ���շ�, ��ó��

��ó : UKIEPC 2016 L��
*/

long long fact[16];
double mem[16];

int main(void) {
    long long n;
    scanf("%lld", &n);
    fact[0] = 1;
    mem[0] = 0.0;
    for (int i = 1; i < 16; i++) fact[i] = fact[i - 1] * i;
    for (int i = 1; i < 16; i++) mem[i] = mem[i - 1] + 1.0 / fact[i] * ((i & 1) ? 1 : -1);
    if (n > 15) printf("%.9f", mem[15]);
    else printf("%.9f", mem[n]);
    return 0;
}