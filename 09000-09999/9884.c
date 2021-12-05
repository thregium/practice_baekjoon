#include <stdio.h>

/*
���� : 32767 ������ �� �ڿ����� �־��� ��, ������ �־��� ��Ŭ���� ȣ���� �˰����� �̿��Ͽ� �ִ������� ���Ѵ�.

�ذ� ��� : ��Ŭ���� ȣ������ �̿��Ѵ�.

�ֿ� �˰��� : ����, ��Ŭ���� ȣ����, ����

��ó : NOIS 2006 1��
*/

int gcd(int a, int b) {
    if (a == 0) return b;
    if (b == 0) return a;
    return a > b ? gcd(a % b, b) : gcd(a, b % a);
}

int main(void) {
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d", gcd(a, b));
    return 0;
}