#include <stdio.h>
#include <stdlib.h>

/*
���� : N(N <= 10^6)���� ���̿� N���� ������ ���� �ִ�. ���� ���̿� ������ ���� ���°� �־��� ��,
������ ���� ���̵��� �ϱ� ���� ������ �� ���� ������ �ٲٴ� ������ �󸶳� �ؾ� �ϴ� �� ���Ѵ�.

�ذ� ��� : ����(0)�� ��ġ�ϴ� ������ ��ġ�ؾ� �ϴ� ������ ��� �� ������ �Ÿ� ���̸� ���ϸ�
�̵��ؾ� �ϴ� �ּ� �Ÿ��� �ȴ�.(�� ������ ������ �ٲ��� �ʴ� ���� ���� �����Ƿ�)
������ ���ʺ��� ���� ���� ���ʺ��� ���� ��� �� ������ ���� �� ���� ������ �ϸ� �ȴ�.

�ֿ� �˰��� : �׸��� �˰���

��ó : PA 2007 3-1��
*/

int a[1048576 * 2], shirt[1048576];

long long small(long long a, long long b) {
    return a < b ? a : b;
}

int main(void) {
    int n, sc = 0;
    long long res1 = 0, res2 = 0;
    scanf("%d", &n);
    for (int i = 0; i < n * 2; i++) {
        scanf("%d", &a[i]);
        if (a[i] == 0) shirt[sc++] = i;
    }
    if (sc != n) return 1;
    for (int i = 0; i < n; i++) {
        res1 += abs(shirt[i] - i * 2 - 1);
    }
    for (int i = 0; i < n; i++) {
        res2 += abs(shirt[i] - i * 2);
    }
    printf("%lld", small(res1, res2));
    return 0;
}