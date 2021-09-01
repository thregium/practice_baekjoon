#include <stdio.h>

/*
���� : N(N <= 100)���� �ҽ����� M(M <= 100)��� �Ϸ��� �� ��, �ʿ��� �ּ����� Į�� Ƚ���� ���Ѵ�.

�ذ� ��� : ���� �ҽ����� N / M ũ��� �ڸ���. �� �������� ���� (M - N) / M ũ�� �ҽ������� �Ǵٽ�
M��� �ϰ�, �̸� �ݺ��ϸ� �� M - gcd(N, M)ȸ �ڸ��� �ȴ�.

�ֿ� �˰��� : ����, ������

��ó : COCI 13/14#1 2��
*/

int gcd(int a, int b) {
    if (a == 0) return b;
    if (b == 0) return a;
    return a > b ? gcd(a % b, b) : gcd(a, b % a);
}

int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);
    printf("%d", m - gcd(n, m));
    return 0;
}