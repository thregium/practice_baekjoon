#include <stdio.h>

/*
���� : �ڿ��� ���� [A, B](A <= B <= 2 * 10^9)�� �־��� ��, �ش� ������ �ִ� ���������� ������ ���Ѵ�.

�ذ� ��� : 1���� B^(1/3)������ ���� Ȯ���ϸ鼭 �������� A���� �۴ٸ� �׷��� ���� ������ ����.

�ֿ� �˰��� : ���Ʈ ����

��ó : Khawarizmi 2010 B��
*/

int main(void) {
    int t;
    long long a, b, r;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        scanf("%lld %lld", &a, &b);
        r = 0;
        for (long long i = 1; i * i * i <= b; i++) {
            if (i * i * i >= a) r++;
        }
        printf("Case #%d: %lld\n", tt, r);
    }
    return 0;
}