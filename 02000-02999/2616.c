#include <stdio.h>

/*
���� : N(N <= 50000)���� ���� �ִ�. ������ K(K <= N / 3)�� ���� �̷���� ���� 3���� ���� ���� ũ���� �� ��,
�� ���� ���Ѵ�. �� ������ ���ļ��� �� �ȴ�.

�ذ� ��� : �� �������� ���� ���� �̸� ���س��´�. �� ����, �� ������ K�� �ڱ����� ������ ���ϸ� ���� �Ǵ���
���� ������ �������� DP�� �ϸ� �ȴ�. �̶�, ���� ���� �� ū ��쿡�� �� ������ �̸� ������Ʈ�� �� ��� �Ѵ�.

�ֿ� �˰��� : DP, ���� ��

��ó : ���� 2003 ��3�� // IIPC 2005 G��
*/

int a[51200], mem[51200][4];

int big(int a, int b) {
    return a > b ? a : b;
}

int small(int a, int b) {
    return a < b ? a : b;
}

int main(void) {
    int n, k;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        a[i] += a[i - 1];
    }
    scanf("%d", &k);
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= 3; j++) {
            if (i > 0) mem[i][j] = big(mem[i][j], mem[i - 1][j]);
        }
        for (int j = 0; j < 3; j++) {
            mem[small(n, i + k)][j + 1] = big(mem[small(n, i + k)][j + 1], mem[i][j] + a[small(n, i + k)] - a[i]);
        }
    }
    printf("%d", mem[n][3]);
    return 0;
}