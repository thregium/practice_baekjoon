#include <stdio.h>

/*
���� : �־��� �� �� A, B(A, B <= 10^6)�� ���� �� ���� �ּҰ������ ���Ѵ�.

�ذ� ��� : ��Ŭ���� ȣ������ �̿��� �� ���� �ִ������� ���� �� �� ���� ������ ������ �ȴ�.

�ֿ� �˰��� : ����, ��Ŭ���� ȣ����

��ó : PLU 2013 A2��
*/

int gcd(int a, int b) {
    if (a == 0) return b;
    if (b == 0) return a;
    return a > b ? gcd(a % b, b) : gcd(a, b % a);
}

int main(void) {
    int n, a, b;
    scanf("%d", &n);
    for (int nn = 0; nn < n; nn++) {
        scanf("%d %d", &a, &b);
        printf("%lld\n", (long long)a * b / gcd(a, b));
    }
    return 0;
}