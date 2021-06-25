#include <stdio.h>

/*
���� : 1�� ������ �� ���� �̷���� ��ʽ��� �־��� ��, �� ��ʽ��� ����Ѵ�.

�ذ� ��� : ��Ŭ���� ȣ������ �̿��� �ִ������� ���� ��, �� ���� �ִ������� ������ �ش�.

�ֿ� �˰��� : ����, ������, ��Ŭ���� ȣ����

��ó : ���� 2017 D��
*/

int gcd(int a, int b) {
    if (a == 0) return b;
    else if (b == 0) return a;
    return a > b ? gcd(a % b, b) : gcd(a, b % a);
}

int main(void) {
    int n, m, g;
    scanf("%d:%d", &n, &m);
    g = gcd(n, m);
    printf("%d:%d", n / g, m / g);
    return 0;
}