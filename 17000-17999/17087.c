#include <stdio.h>
#include <stdlib.h>

/*
���� : ���������� ��ġ S(1 <= S <= 10^9)���� N(N <= 100000)���� �ڿ���(<= 10^9) ��ġ�� ��� �̵��� �� �ִ�
���� ���� �̵� ������ ���Ѵ�.

�ذ� ��� : ��Ŭ���� ȣ������ �̿��Ͽ� S�� ��� �ڿ������� �Ÿ����� gcd�� ���ϸ� �ȴ�.

�ֿ� �˰��� : ����, ������, ��Ŭ���� ȣ����
*/

int gcd(int a, int b) {
    if (a == 0) return b;
    if (b == 0) return a;
    return a > b ? gcd(a % b, b) : gcd(a, b % a);
}

int main(void) {
    int n, s, a, g = 0;
    scanf("%d %d", &n, &s);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        if (g == 0) g = abs(s - a);
        else g = gcd(g, abs(s - a));
    }
    if (g == 0) return 1;
    printf("%d", g);
    return 0;
}