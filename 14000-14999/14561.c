#include <stdio.h>

/*
���� : �ڿ��� A(A <= 10^12)�� N(2 <= N <= 16)�� �־��� ��, A�� N�������� ��Ÿ���� ȸ������ ���Ѵ�.

�ذ� ��� : A�� �ڸ��� ������ �����ؼ� �迭�� ������ ����, �迭�� ȸ�� �������� �˻��ϸ� �ȴ�.

�ֿ� �˰��� : ����, ����

��ó : �߾Ӵ� 2017R A��
*/

int num[64];

int main(void) {
    int t, n, p, r;
    long long a;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%lld %d", &a, &n);
        for (p = 0; a; p++, a /= n) {
            num[p] = a % n;
        }
        r = 1;
        for (int i = 0, j = p - 1; i < j; i++, j--) {
            if (num[i] != num[j]) r = 0;
        }
        printf("%d\n", r);
    }
    return 0;
}