#include <stdio.h>

/*
���� : N * N(N <= 1000) ���� ������ ��� (0, 0)���� ������ �ʰ� �� �� �ִ� ���� ������ ���Ѵ�.
�̸� C(C <= 1000)�� �ݺ��Ѵ�.

�ذ� ��� : �� ���� ���� X�� Y��ǥ�� ���μ��� ��� �� �� �ִ� ���̴�. 1000 * 1000���� ���� ����
N�� ���������� �� �� �ִ� �� ������ ã�� ���� ���� ���� ���� ���� �����ϰ� ����ϸ� �ȴ�.

�ֿ� �˰��� : ����, ��Ŭ���� ȣ����, ���� ��

��ó : GNY 2006 F��
*/

int res[1024];

int big(int a, int b) {
    return a > b ? a : b;
}

int gcd(int a, int b) {
    if (a == 0) return b;
    if (b == 0) return a;
    return a > b ? gcd(a % b, b) : gcd(a, b % a);
}

int main(void) {
    int c, n;
    res[0] = 2;
    for (int i = 1; i <= 1000; i++) {
        for (int j = 1; j <= 1000; j++) {
            if (gcd(i, j) == 1) res[big(i, j)]++;
        }
    }
    for (int i = 1; i <= 1000; i++) res[i] += res[i - 1];
    scanf("%d", &c);
    for (int tt = 0; tt < c; tt++) {
        scanf("%d", &n);
        printf("%d\n", res[n]);
    }
    return 0;
}