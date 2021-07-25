#include <stdio.h>

/*
���� : �ڿ��� N(N <= 60000)�� �־��� ��, N�� ���������� ���������� ���׼����� ���Ѵ�.

�ذ� ��� : N �̸��� ��� ���� ���� ������� Ȯ���ϰ� ������� ���� ���Ѵ�. �� ���� N�� ���� ���� ã�Ƴ��� �ȴ�.

�ֿ� �˰��� : ���Ʈ ����, ������

��ó : Mid-At 1996 6��
*/

int main(void) {
    int n, s;
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        s = 0;
        for (int i = 1; i < n; i++) {
            if (n % i == 0) s += i;
        }
        if (s > n) printf("%d ABUNDANT\n", n);
        else if (s == n) printf("%d PERFECT\n", n);
        else printf("%d DEFICIENT\n", n);
    }
    return 0;
}