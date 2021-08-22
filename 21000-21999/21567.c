#include <stdio.h>

/*
���� : �� �ڿ��� A, B, C(A, B, C <= 10^6)�� �־��� ��, �� ���� ���� ���� �� ������ ������ ����Ѵ�.

�ذ� ��� : �� ���� ���� ���� ����, �ڸ����� �ϳ��� ��� Ȯ���ϸ� �ȴ�.

�ֿ� �˰��� : ����, ��Ģ����
*/

int cnt[10];

int main(void) {
    long long a, b, c, d;
    scanf("%lld %lld %lld", &a, &b, &c);
    d = a * b * c;
    for (long long i = d; i; i /= 10) {
        cnt[i % 10]++;
    }
    for (int i = 0; i < 10; i++) {
        printf("%d\n", cnt[i]);
    }
    return 0;
}