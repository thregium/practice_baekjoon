#include <stdio.h>

/*
���� : �ڿ��� N(N < 2^31)�� �־��� ��, N�� ¦���� 2�� ������ Ȧ���� 1�� ���ϴ� ���� �� ȸ �ݺ��ؾ� 1�� �Ǵ��� ���Ѵ�.

�ذ� ��� : N�� 1�� �� �� ���� �־��� �ൿ�� �ݺ��ϰ� �ݺ��� Ƚ���� ���ϸ� �ȴ�. � ���� Ȧ������,
1�� ���ϰ� 2�� ������ ���� �������� �پ��� ������ ���� �ſ� ���� ������ ������ �ȴ�.

�ֿ� �˰����� : ����, ����

��ó : GNY 2019 G��
*/

int main(void) {
    long long n, r = 0;
    scanf("%lld", &n);
    while (n > 1) {
        if (n & 1) n = n + 1;
        else n >>= 1;
        r++;
    }
    printf("%lld", r);
    return 0;
}