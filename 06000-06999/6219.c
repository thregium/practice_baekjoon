#include <stdio.h>

/*
���� : ���� [A, B](A, B <= 4 * 10^6)���� ���� D�� ���Ե� �Ҽ��� ������ ���Ѵ�.

�ذ� ��� : �����佺�׳׽��� ü�� �̿��� A���� B ������ �Ҽ����� ���� �� �ִ�. ���� �� ���� ��� ���� D�� ���Ե�
������ ã�� ����, �� ������ ������ ���ϸ� �ȴ�.

�ֿ� �˰��� : ����, �����佺�׳׽�

��ó : USACO 2007J B1��
*/

char sieve[4194304];

int main(void) {
    int a, b, d, r = 0, t;
    scanf("%d %d %d", &a, &b, &d);
    for (int i = 2; i <= b; i++) {
        if (sieve[i]) continue;
        if (i >= a) {
            t = 0;
            for (int j = i; j; j /= 10) {
                if (j % 10 == d) t = 1;
            }
            r += t;
        }
        for (int j = i * 2; j <= b; j += i) {
            sieve[j] = 1;
        }
    }
    printf("%d", r);
    return 0;
}