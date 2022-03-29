#include <stdio.h>

/*
���� : X + Y = Z �Ǵ� X * Y = Z�� �־��� ���� ������Ű�� X, Y, Z �� 2���� ���� ����
�� ���κ� ��ȯ�� �����ϰ� �����Ѵ�. �� �ڿ��� X, Y, Z(X, Y, Z < 2^31)�� �־��� ��,
�׷��� ��ȯ�� ����Ѵ�. �� ���κ� ��ȯ�� �� ���ڿ��� �տ��� 1�� �̻��� ��ü ���ڿ��� �ƴ�
���κθ� ���� ��ȯ�ϴ� ���̴�.

�ذ� ��� : (X, Y), (X, Z), (Y, Z)�� �ֵ鿡 ���� �տ������� ������ ��� ��츦 �ٲپ� ����
���� ������ ��� �� ���� ����Ѵ�. ������ ����� 10�� ����� �̿��ϸ� ���ڿ��� �̿����� �ʰ�
������ �ٲ� ����� ���� ã�� �� �ִ�.

�ֿ� �˰��� : ����, ���Ʈ ����

��ó : ECNA 2021 G��
*/

int main(void) {
    long long x, y, z, r = 1;
    char o;
    scanf("%lld %c %lld = %lld", &x, &o, &y, &z);
    for (long long i = 10; i <= x; i *= 10) {
        for (long long j = 10; j <= z; j *= 10) {
            if (o == '+') {
                if ((x % i + z / j * i) + y == (z % j + x / i * j)) {
                    printf("%lld + %lld = %lld", x % i + z / j * i, y, z % j + x / i * j);
                    r = 0;
                }
            }
            else {
                if ((x % i + z / j * i) * y == (z % j + x / i * j)) {
                    printf("%lld * %lld = %lld", x % i + z / j * i, y, z % j + x / i * j);
                    r = 0;
                }
            }
            if (!r) break;
        }
        if (!r) break;
    }
    for (long long i = 10; i <= x; i *= 10) {
        for (long long j = 10; j <= y; j *= 10) {
            if (o == '+') {
                if ((x % i + y / j * i) + (y % j + x / i * j) == z) {
                    printf("%lld + %lld = %lld", x % i + y / j * i, y % j + x / i * j, z);
                    r = 0;
                }
            }
            else {
                if ((x % i + y / j * i) * (y % j + x / i * j) == z) {
                    printf("%lld * %lld = %lld", x % i + y / j * i, y % j + x / i * j, z);
                    r = 0;
                }
            }
            if (!r) break;
        }
        if (!r) break;
    }
    for (long long i = 10; i <= y; i *= 10) {
        for (long long j = 10; j <= z; j *= 10) {
            if (o == '+') {
                if (x + (y % i + z / j * i) == (z % j + y / i * j)) {
                    printf("%lld + %lld = %lld", x, y % i + z / j * i, z % j + y / i * j);
                    r = 0;
                }
            }
            else {
                if (x * (y % i + z / j * i) == (z % j + y / i * j)) {
                    printf("%lld * %lld = %lld", x, y % i + z / j * i, z % j + y / i * j);
                    r = 0;
                }
            }
            if (!r) break;
        }
        if (!r) break;
    }
    return r;
}