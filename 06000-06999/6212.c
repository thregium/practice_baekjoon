#include <stdio.h>

/*
���� : M���� N(M <= N <= 2 * 10^9, N - M <= 500000)������ ���鿡 �ִ� �� ������ ������ ���Ѵ�.

�ذ� ��� : M���� N������ ��� ���� ���� �� ���ڸ� ���� �ȴ�.

�ֿ� �˰��� : ���Ʈ ����, ����

��ó : USACO 2006D B3��
*/

int cnt[10];

int main(void) {
    int m, n;
    scanf("%d %d", &m, &n);
    for (int i = m; i <= n; i++) {
        for (int j = i; j; j /= 10) cnt[j % 10]++;
    }
    for (int i = 0; i < 10; i++) printf("%d ", cnt[i]);
    return 0;
}