#include <stdio.h>

/*
���� : N * M(N, M <= 100) ũ���� ������ ���ε鿡�� K���� ���ΰ� ���ٰ� �� ��
(0, 0)���� (N, M)���� �ִܰŸ��� �̵��ϴ� ����� �������� ���Ѵ�.

�ذ� ��� : �� ���������� �����ʰ� �Ʒ������� �� �� �ִ� �� ���θ� ������ ��
���̳��� ���α׷����� �ϸ� �ȴ�.

�ֿ� �˰��� : DP
*/

int un[128][128][2];
long long mem[128][128];

int main(void) {
    int n, m, k, x1, y1, x2, y2;
    scanf("%d %d%d", &n, &m, &k);
    for (int i = 0; i < k; i++) {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        if (x1 < x2) un[x1][y1][0] = 1;
        else if (x1 > x2) un[x2][y1][0] = 1;
        else if (y1 < y2) un[x1][y1][1] = 1;
        else if (y1 > y2) un[x1][y2][1] = 1;
        else return 1;
    }
    mem[0][0] = 1;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (!un[i][j][1]) mem[i][j + 1] += mem[i][j];
            if (!un[i][j][0]) mem[i + 1][j] += mem[i][j];
        }
    }
    printf("%lld", mem[n][m]);
    return 0;
}