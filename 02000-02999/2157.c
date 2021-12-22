#include <stdio.h>

/*
���� : N(N <= 300)���� ���� �� M(2 <= M <= N)�� ���ϸ� ��ȣ ������� �̵��Ϸ��� �Ѵ�. �׷����� ������ K(K <= 100000)���̰�,
�� ������ ����ġ(<= 10000)�� ���´�. 1�� �������� N�� �������� �̵��ϸ� ����ġ ���� ���� ū ��� ����ġ ���� ���Ѵ�.
���� �Ұ����� ���� �־����� �ʴ´�. �� ������ �ڱ� �ڽ����� �̵��� �� ������ ���� ���� �ֳ��� �հų�
���������� ���� ������ ���� �� �ִ�.

�ذ� ��� : ���ÿ� �̵��� ���� ���� ������ �ΰ� DP�� �Ѵ�. ���� ��� ���� ������ �ʱ�ȭ�� ����, (1, 1)���� DP�� �����ϸ� �ȴ�.
������ ���� ��� ������ �ִ� ������ ���� ��ġ���� �����ϴ� ���� ã�� ����ġ ���� ���� ũ���� ���س�����.
���������� N��° ������ [2, M] ���� �� ��� ���� ū ���� ���� �ȴ�.
������ ���� �� ���� ���� ���� ������ �����Ѵ�.

�ֿ� �˰����� : DP, �׷��� �̷�
*/

int mem[384][384], ed[384][384];

int big(int a, int b) {
    return a > b ? a : b;
}

int main(void) {
    int n, m, k, a, b, c, r = 0;
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < k; i++) {
        scanf("%d %d %d", &a, &b, &c);
        if (c > ed[a][b]) ed[a][b] = c;
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            mem[i][j] = -1;
        }
    }
    mem[1][1] = 0;
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int l = 1; l < i; l++) {
                if (mem[l][j - 1] < 0) continue;
                if (ed[l][i]) mem[i][j] = big(mem[i][j], mem[l][j - 1] + ed[l][i]);
            }
        }
    }
    for (int i = 1; i <= m; i++) {
        r = big(r, mem[n][i]);
    }
    printf("%d", r);
    return 0;
}