#include <stdio.h>

/*
���� : �ڿ��� N(N <= 10^18)�� �־��� ��, ��� ����(a_1 = 1�̰�, ���� �����ϸ�,
�� �ڿ��� k�� a_kȸ �ִ� ����)�� N��° ���� ���Ѵ�.

�ذ� ��� : N <= 1011������ �� ��� ������ ���� ���� ����, �� ��°�� ���� ���� �� ������ ����ŭ
�ǳ� �پ�� ������ ���� ã�Ƴ����� �ȴ�. 

�ֿ� �˰��� : ����, DP?

��ó : JPOI 2008 3-2��
*/

int a[32768];

int main(void) {
    long long n, p = 4, r = 1;
    scanf("%lld", &n);
    a[1] = 1;
    a[2] = 2;
    a[3] = 2;
    for (int i = 3; p < 30000; i++) {
        for (int j = 0; j < a[i]; j++) a[p++] = i;
    }
    p = 1;
    for (long long i0 = 1;; i0++) {
        for (long long i = 1; i <= a[i0]; i++) {
            if (n <= i0 * p) {
                for (long long j = 0; j < i0; j++) {
                    if (n <= p) {
                        printf("%lld", r);
                        return 0;
                    }
                    else {
                        n -= p;
                        r++;
                    }
                }
                break;
            }
            else {
                n -= i0 * p;
                r += i0;
            }
            p++;
        }
    }
    return 0;
}