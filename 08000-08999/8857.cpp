#include <stdio.h>

/*
���� : N(N <= 45)���� ��Ʈ�� �̷���� 1�� �����ϸ� ������ 1�� ���� ���� ������ ���Ѵ�.

�ذ� ��� : ���̳��� ���α׷����� �̿��Ѵ�. ���� 0�϶��� 1�� ���� ������
���� �Ǻ���ġ ������ ������ �� �� �ִ�.

�ֿ� �˰��� : DP

��ó : SKI 2010 1-1��
*/

long long fib[64];

int main(void) {
    int t, n;
    fib[1] = 1, fib[2] = 1;
    for (int i = 3; i <= 45; i++) fib[i] = fib[i - 1] + fib[i - 2];
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &n);
        printf("%lld\n", fib[n]);
    }
    return 0;
}