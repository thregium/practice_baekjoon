#include <stdio.h>

/*
���� : �� �� X�� K(X, K <= 10^9)�� �־��� ��, X OR Y = X + Y�� �Ǵ� K��°�� ���� �ڿ��� Y�� ���Ѵ�.

�ذ� ��� : ������ �����ϱ� ���ؼ��� X�� Y�� �̷�� ��Ʈ�� ���� �޶�� �Ѵ�.
����, K�� �������� ����� X�� ��Ʈ�� 0�� ��Ʈ�� �����ϸ� ���� �ȴ�.

�ֿ� �˰��� : ����

��ó : SRM 430 D1A / D2B
*/

int main(void) {
    long long x, y, z = 0, p = 0;
    scanf("%lld %lld", &x, &y);
    for (int i = y; i; i >>= 1) {
        while ((x >> p) & 1) p++;
        if (i & 1) z += (1LL << p);
        p++;
    }
    printf("%lld", z);
    return 0;
}