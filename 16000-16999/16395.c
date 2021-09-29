#include <stdio.h>

/*
���� : �Ľ�Į�� �ﰢ������ N(N <= 30)���� K(K <= 30)��° ���� ���Ѵ�.

�ذ� ��� : �Ľ�Į�� �ﰢ������ ù ��° ���� 1�̰�, �Ʒ��� �� �� ���� ���� �� ���� ���ذ��ٴ� ���� �̿���
DP�� �ϸ� �ȴ�.

�ֿ� �˰��� : DP

��ó : ȫ�ʹ� 2018 B��
*/

long long mem[32][32];

int main(void) {
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i <= n; i++) {
        mem[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            mem[i][j] = mem[i - 1][j - 1] + mem[i - 1][j];
        }
    }
    printf("%lld", mem[n - 1][k - 1]);
    return 0;
}