#include <stdio.h>

/*
���� : 1 �̻� 1000 �̸��� �Ҽ��� 4�ڸ� ���� �־��� ��, �� ���� ���ؼ� ���� ���� �� �� �ڸ� ���ڸ�
�� �ڷ� �ű� �Ͱ� �������� 10^8 ���� �ڿ����� ������������ ����Ѵ�.

�ذ� ��� : 10^8���� ��� ���� ���� �׷��� �Ǵ� �� Ȯ���Ѵ�. ��, ���ѽð��� ª�� �Ǽ� ������ ���� ��
�ֱ� ������ ������ ������� �����ؾ� �Ѵ�.

�ֿ� �˰��� : ���Ʈ ����, ���̽� ��ũ

��ó : NCPC 2013 C��
*/

int get10(int x) {
    if (x >= 10000000) return 10000000;
    else if (x >= 1000000) return 1000000;
    else if (x >= 100000) return 100000;
    else if (x >= 10000) return 10000;
    else if (x >= 1000) return 1000;
    else if (x >= 100) return 100;
    else if (x >= 10) return 10;
    else return 1;
}

int main(void) {
    long long c, xt, r = 0;
    double x, y;
    scanf("%lf", &x);
    if (x + 0.00000001 - (int)x < 0.000005) {
        xt = (int)(x + 0.0000001);
        for (long long a = 1; a < 10000000; a++) {
            c = a * xt;
            if (c == 10 * (a % get10(a)) + a / get10(a)) {
                printf("%lld\n", a);
                r++;
            }
        }
        for (long long a = 10000000; a < 100000000; a++) {
            c = a * xt;
            if (c == 10 * (a % 10000000) + a / 10000000) {
                printf("%lld\n", a);
                r++;
            }
        }
    }
    else {
        for (long long a = 1; a < 100000000; a++) {
            y = a * x + 0.0000001;
            if (y - (long long)y >= 0.00005) continue;
            c = y;
            if (c == 10 * (a % get10(a)) + a / get10(a)) {
                printf("%lld\n", a);
                r++;
            }
        }
    }
    if (r == 0) printf("No solution");
    return 0;
}