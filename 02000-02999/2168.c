#include <stdio.h>

/*
���� : X * Y(X, Y <= 10^9, �ڿ���) ũ���� Ÿ�Ͽ��� �밢���� ������ Ÿ���� ������ ���Ѵ�.

�ذ� ��� : ���簢���� Ÿ���� �������� ������ �ּ� ������ �����Ѵ�. �� ���� X�� Y���� ���� �ִ������� ���� ũ���̴�.
�� ũ�⿡�� �밢���� ������ Ÿ���� ������ ���� �Ʒ����� ������ �� ������ ����� ���̿� ����, �̴� X + Y - 1�̴�.
�̰��� �ִ����� �� �ݺ��ǹǷ� �ش� ���� �ִ������� ���� ���� ���� �ȴ�.

�ֿ� �˰����� : ����, ��Ŭ���� ȣ����
*/

int gcd(int a, int b) {
    if (a == 0) return b;
    if (b == 0) return a;
    return a > b ? gcd(a % b, b) : gcd(a, b % a);
}

int main(void) {
    int x, y;
    scanf("%d %d", &x, &y);
    printf("%d", gcd(x, y) * (x / gcd(x, y) + y / gcd(x, y) - 1));
    return 0;
}