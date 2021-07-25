#include <stdio.h>

/*
���� : �� �ڿ��� A, B(A, B <= 10^10)�� �־�����. �̶�, �� ���� ���� ���� �޾ƿø� Ƚ���� ���Ѵ�.

�ذ� ��� : �� ���� ������ �ڸ����� Ȯ���ϸ� �ڸ����� �� + �޾ƿø��� 10 �̻����� Ȯ���� �� �̷��� ���� ���� ���� �ȴ�.

�ֿ� �˰��� : ����, ��Ģ����

��ó : Waterloo 2000S23 C��
*/

int main(void) {
    long long a, b;
    int c, r;
    while (1) {
        scanf("%lld %lld", &a, &b);
        if (a == 0 && b == 0) break;
        c = 0, r = 0;
        for (long long i = a, j = b; i || j; i /= 10, j /= 10) {
            if (c + i % 10 + j % 10 >= 10) {
                c = 1;
                r++;
            }
            else c = 0;
        }
        printf("%d\n", r);
    }
    return 0;
}