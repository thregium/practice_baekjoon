#include <stdio.h>

/*
���� : N(N <= 32500)�� �־��� ��, �� ���� ���������� ���������� ���׼����� ���Ѵ�.

�ذ� ��� : 1���� N - 1���� ��� ���� ���� ������� �����ϴ��� �ð� �ʰ��� ���� �����Ƿ� ���� �����غ��� �ȴ�.

�ֿ� �˰��� : ����, ���Ʈ ����

��ó : CCC 1996 1��
*/

int main(void) {
    int t, n, r;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &n);
        r = 0;
        for (int i = 1; i < n; i++) {
            if (n % i == 0) r += i;
        }
        printf("%d is %s number.\n", n, n > r ? "a deficient" : n == r ? "a perfect" : "an abundant");
    }
    return 0;
}