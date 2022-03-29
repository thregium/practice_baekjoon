#include <stdio.h>
#define INF 1012345678

/*
���� : N(2 <= N <= 1000)���� �������� �̷���� ������Ʈ�� �� ������ ����ġ(<= 1000, �ڿ���)�� �־�����.
�̶�, 2���� ���� ������ �̾��� ��, �� ������� �׵��� �θ� �������� ����ġ ���� �ּڰ��� ���Ѵ�.
�ߺ��Ǵ� ������ ����ġ�� 1������ ���Ѵ�.

�ذ� ��� : Ʈ�� DP�� �̿��Ѵ�. �� ������ ���� 1�� ���� ���� 2�� ���� ���� ���� ����
���� ������ ��� 1���� �� ���� ��, 2���� �� ���Ѵ븦, �� ���� ��쿡�� 1���� ��
���� �� + �ڽ� ������ 1���� �� �� �� �ּڰ�, 2���� ������ ���� �� + �ڽ� ������ 2���� �� �ּڰ�
�Ǵ� 1���� �� �ּڰ��� 2��° ���� �� �� ���� ���� ������ �Ѵ�.
������Ʈ �������� ������ ���� �� 0�� ������ �ٸ� ������ ��Ʈ �������� �����ָ� �� ������ ���� ����
��ü�� ���� ���� �� �ִ�.

�ֿ� �˰��� : DP, Ʈ��DP

��ó : ECNA 2021 B��
*/

int chd[1024][1024], par[1024], page[1024], mem[1024][2];

int small(int a, int b) {
    return a < b ? a : b;
}

int dp(int x, int c) {
    int res11 = INF, res12 = INF, res2 = INF, t;
    if (mem[x][c] <= INF) return mem[x][c];
    if (c == 0) {
        if (chd[x][0] == 0) return mem[x][c] = page[x];
        for (int i = 1; i <= chd[x][0]; i++) {
            res11 = small(res11, dp(chd[x][i], 0));
        }
        return mem[x][c] = res11 + page[x];
    }
    else {
        if (chd[x][0] == 0) return mem[x][c] = INF;
        for (int i = 1; i <= chd[x][0]; i++) {
            t = dp(chd[x][i], 0);
            if (t < res11) {
                res12 = res11;
                res11 = t;
            }
            else if (t < res12) {
                res12 = t;
            }
            res2 = small(res2, dp(chd[x][i], 1));
        }
        return mem[x][c] = small(INF, small(res11 + res12, res2) + page[x]);
    }
}

int main(void) {
    int n, m, a, b;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &page[i]);
    }
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        chd[a][++chd[a][0]] = b;
        par[b] = a;
    }
    for (int i = 1; i <= n; i++) {
        if (par[i] == 0) {
            chd[0][++chd[0][0]] = i;
        }
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < 2; j++) mem[i][j] = INF + 1;
    }
    printf("%d", dp(0, 1));
    return 0;
}