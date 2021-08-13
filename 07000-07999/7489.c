#include <stdio.h>

/*
���� : N!(1 <= N <= 1000)�� 0�� �ƴ� ������ ���� ���Ѵ�.

�ذ� ��� : N ������ �� ��� ���μ� 5�� ���� ���ƾ� 4��(625) ���Ƿ� ������ 5�ڸ��� ���� ������ ����ϴ�.

�ֿ� �˰��� : ����, ������

��ó : AUCPC 2010S I��
*/

int main(void) {
    int t, n;
    long long r;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &n);
        r = 1;
        for (int i = 1; i <= n; i++) {
            r *= i;
            while (r % 10 == 0) r /= 10;
            r %= 100000000;
        }
        printf("%lld\n", r % 10);
    }
    return 0;
}