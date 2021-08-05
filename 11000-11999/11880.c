#include <stdio.h>
#define INF 12345678987654321

/*
���� : �� ���� ���̰� A, B, C(A, B, C <= 100000)�� ������ü�� ���� ��, �� ������ü�� �� ���������� �ݴ��� ����������
������ü�� ǥ���� ���� �̵��� ���� �ִܰŸ��� ������ ���Ѵ�.

�ذ� ��� : ������ �� ���� �������� �̵��ϴ� ���� �ּ��̴�. �̷��� ����� ���⿡ ���� 3�����̰�,
���� A^2 + (B + C)^2, B^2 + (A + C)^2, C^2 + (A + B)^2�� �Ÿ��̴�. �̵� �� ���� ª�� ���� �����ϸ� �ȴ�.

�ֿ� �˰��� : ������

��ó : GA4 1��
*/

long long small(long long a, long long b) {
    return a < b ? a : b;
}

int main(void) {
    long long t, a, b, c, r;
    scanf("%lld", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%lld %lld %lld", &a, &b, &c);
        r = INF;
        r = small(r, a * a + (b + c) * (b + c));
        r = small(r, b * b + (a + c) * (a + c));
        r = small(r, c * c + (a + b) * (a + b));
        printf("%lld\n", r);
    }
    return 0;
}
