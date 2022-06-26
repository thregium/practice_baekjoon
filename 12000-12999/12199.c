#include <stdio.h>
#define MOD 1000000007

/*
���� : ���� N�� M(N, M <= 100)���� ���ڸ� ��� ����Ͽ� ������� ���ڿ��� �� ������ �� ���Ѵ�.

�ذ� ��� : ���̳��� ���α׷����� ���� �ذ��Ѵ�. �� ���̿� �� ������ ��������
�������� ������ �����鼭 Ǯ�� �ȴ�.

�ֿ� �˰��� : DP, ���շ�

��ó : GKS 2014B A2��
*/

long long mem[128][128];

int main(void) {
    int t, n, m;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        scanf("%d %d", &m, &n);
        mem[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                mem[i][j] = (mem[i - 1][j - 1] * (m - (j - 1)) + mem[i - 1][j] * j) % MOD;
            }
        }
        printf("Case #%d: %lld\n", tt, mem[n][m]);
    }
    return 0;
}