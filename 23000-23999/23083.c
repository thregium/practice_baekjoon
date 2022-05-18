#include <stdio.h>
#define MOD 1000000007

/*
���� : N * M(N, M <= 1000) ũ���� ������ ������ �־��� �������� �ִ�. �� ĭ�� ��ǥ���� �־��� ��,
(1, 1)���� (N, M)���� �̵��ϴ� ����� �������� ���Ѵ�.

�ذ� ��� : �� ��ȣ�� �پ��� �������� �̵����� �ʴ� ���� �̿��� ���̳��� ���α׷����� ���� �����Ѵ�.
�̶� ���� Ȧ¦�� ���� �̵� ������ �޶����Ƿ� �����Ѵ�.

�ֿ� �˰��� : DP

��ó : ���ϴ� 2021 K��
*/

char hole[1024][1024];
int mem[1024][1024];

int main(void) {
    int n, m, k, x, y;
    scanf("%d %d", &n, &m);
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        scanf("%d %d", &x, &y);
        hole[x][y] = 1;
    }
    mem[1][1] = 1;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (hole[j][i]) continue;
            mem[j + 1][i] = (mem[j + 1][i] + mem[j][i]) % MOD;
            mem[j][i + 1] = (mem[j][i + 1] + mem[j][i]) % MOD;
            if (i & 1) mem[j - 1][i + 1] = (mem[j - 1][i + 1] + mem[j][i]) % MOD;
            else mem[j + 1][i + 1] = (mem[j + 1][i + 1] + mem[j][i]) % MOD;
        }
    }
    printf("%d", mem[n][m]);
    return 0;
}