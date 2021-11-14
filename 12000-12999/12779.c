#include <stdio.h>

/*
���� : ���� �ƴ� ������ �� ���� (a, b](a < b <= 2^60)���� ����� Ȧ������ ���� ������ ���м��� ���Ѵ�.

�ذ� ��� : ����� Ȧ������ ���� �������̴�. ����, b ������ ������ ������ ���ϰ�, a ������ ������ ������ ���� ����
���� ���� �׷��� ���� �����̴�. �ش� �������� ��ü ���� b - a�̹Ƿ� �̰� �����̴�. �� �� ���� ��Ŭ���� ȣ������
����Ͽ� ���м��� ���� ���� ����ϸ� �ȴ�. ��, 0�� ���� 0���� ����Ѵ�.

�ֿ� �˰��� : ����, ������, ��Ŭ���� ȣ����, �Ķ��Ʈ��

��ó : ���ϴ� 2016 B��
*/

long long getroot(long long n) {
    long long l = 0, h = (1LL << 29) * 3, m;
    while (l < h) {
        m = ((l + h + 1) >> 1);
        if (m * m <= n) l = m;
        else h = m - 1;
    }
    return l;
}

long long gcd(long long a, long long b) {
    if (a == 0) return b;
    if (b == 0) return a;
    return a > b ? gcd(a % b, b) : gcd(a, b % a);
}

int main(void) {
    long long s, e, rt, g;
    scanf("%lld %lld", &s, &e);
    rt = getroot(e) - getroot(s);
    if (rt == 0) {
        printf("0");
        return 0;
    }
    g = gcd(e - s, rt);
    printf("%lld/%lld", rt / g, (e - s) / g);
    if (e > (1LL << 58)) return 1;
    return 0;
}