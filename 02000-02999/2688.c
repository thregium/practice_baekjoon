#include <stdio.h>

/*
���� : N(N <= 64)�ڸ��� �ڸ����� �پ���� �ʴ� ���� ������ ���Ѵ�.

�ذ� ��� : ������ �ڸ��� N�� ���� ������ �����صд�. ��ȭ���� ���� �ڸ��� ���� ������ �ڸ� ������ N - 1�ڸ� ���� ������ ���� ���� ���̴�.

�ֿ� �˰��� : DP

��ó : GNY 2010 E��
*/

long long mem[128][10];

int main(void) {
    int t, n;
    long long s;
    for (int i = 0; i < 10; i++) {
        mem[1][i] = 1;
    }
    for (int i = 2; i <= 64; i++) {
        for (int j = 0; j < 10; j++) {
            for (int k = 0; k <= j; k++) {
                mem[i][j] += mem[i - 1][k];
            }
        }
    }
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &n);
        s = 0;
        for (int i = 0; i < 10; i++) {
            s += mem[n][i];
        }
        printf("%lld\n", s);
    }
    return 0;
}