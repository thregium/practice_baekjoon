#include <stdio.h>

/*
���� : N(N <= 10^6)���� �ڿ���(<= 10^9)�� �־��� ��, M(M <= 10^9) �̻��� �ڿ����� �����ϴ�
������ ������ ���Ѵ�.

�ذ� ��� : ��ü ������ ����(sum(1, N))�� ���� ����, M �̻��� �ڿ����� ���� �������� �� ������ �ȴ�.
�ڿ����� ���� ���� ������ ���̸� ���� ����, sum(1, len)�� �ϸ� �װ��� �� ������ ������ ����.

�ֿ� �˰��� : ����, ���շ�

��ó : JPOI 2009 2-3��
*/

long long getsum(long long n) {
    return (n * (n + 1)) >> 1;
}

int main(void) {
    int n, m, h, c = 0;
    long long r;
    scanf("%d %d", &n, &m);
    r = getsum(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &h);
        if (h < m) c++;
        else {
            r -= getsum(c);
            c = 0;
        }
    }
    r -= getsum(c);
    printf("%lld", r);
    return 0;
}