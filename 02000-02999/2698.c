#include <stdio.h>

/*
���� : N(N <= 100)���� ��Ʈ�� �̷���� ���ڿ� ��� �κ� ���ڿ� '11'�� K(K <= N)ȸ �����ϴ� ���ڿ��� ���� ���Ѵ�.

�ذ� ��� : �� N, K�� ������ ���ڰ� 0, 1�� ���� ���ڿ� ������ ���·� DP�� �����Ѵ�.
������ ���ڰ� 0�� ���, N - 1, K���� ���� �� �ִ� ���ڿ��� ������ �ش� ������ ���� �ȴ�.
1�� ��쿡�� K�� 0�̶�� N - 1, K���� ������ ���ڰ� 0�� ���� ������ �ǰ�, 1 �̻��̶�� �� ���� N - 1, K - 1����
������ ���ڰ� 1�� ���� ������ �ȴ�.

�ֿ� �˰����� : DP

��ó : GNY 2009 F��
*/

long long mem[128][128][2];

int main(void) {
    mem[0][0][0] = 1;
    for (int i = 1; i <= 100; i++) {
        for (int j = 0; j <= 100; j++) {
            mem[i][j][0] = mem[i - 1][j][0] + mem[i - 1][j][1];
            mem[i][j][1] = mem[i - 1][j][0] + (j > 0 ? mem[i - 1][j - 1][1] : 0);
        }
    }
    int t, n, k;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d %d", &n, &k);
        printf("%lld\n", mem[n][k][0] + mem[n][k][1]);
    }
    return 0;
}