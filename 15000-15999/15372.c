#include <stdio.h>

/*
���� : N(N <= 200000)�� ������ ���� ��� �� ���� ���� ���� ���Ѵ�.

�ذ� ��� : N�� ������ 1�� ���ϸ� �ȴ�.

�ֿ� �˰��� : ����, ��Ģ����

��ó : Manila 2016 PA��
*/

int main(void) {
    long long t, n;
    scanf("%lld", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%lld", &n);
        printf("%lld\n", n * n);
    }
    return 0;
}