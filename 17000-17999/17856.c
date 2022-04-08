#include <stdio.h>
#define INF 1012345678

/*
���� : R * C(R, C <= 500) ũ���� ������ ���� �� ������ ���̰� �־�����.
���� ������ ������ ������ ������ ������ 3 ���� �� �ϳ��� �̵� �����ϰ�, pass(������ �������ٴ� ����,
�¿��� �������ٴ� ���� ��)�� ���� ��Ȯ�� N(N <= 10)�� ����ϴ� ��ΰ� �ִ� �� Ȯ���ϰ�,
�ִ� ��� �� �� ������ ���� �ּ��� ���� ���Ѵ�. -1�� ���� ������ �ƴ� ���̴�.

�ذ� ��� : ���̳��� ���α׷����� ���� �ذ��Ѵ�. pass�� ���� ���� Ȯ���� ���� ����,
�� ��ǥ�� ����� pass ������ ������ ���� �ּڰ��� ������ ������. �ʱ� ���� ���Ѵ��̰�, ���ʺ��� ���ʷ�
������ ���� ������ ���� ���� ������ ������ �ּڰ��� Ȯ���� ���Ѵ�� impossible��,
�� �ܿ��� �� ���� ����ϸ� �ȴ�.

�ֿ� �˰��� : DP

��ó : ECNA 2019 E��
*/

int topo[512][512], ispass[512][512], mem[512][512][12];

int small(int a, int b) {
    return a < b ? a : b;
}

int main(void) {
    int r, c, n, res = INF;
    scanf("%d %d %d", &r, &c, &n);
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            scanf("%d", &topo[i][j]);
        }
    }
    for (int i = 0; i <= r + 1; i++) {
        for (int j = 0; j <= c + 1; j++) {
            for (int k = 0; k <= n; k++) mem[i][j][k] = INF;
        }
    }
    for (int i = 2; i <= r - 1; i++) {
        for (int j = 2; j <= c - 1; j++) {
            if (topo[i][j - 1] < 0 || topo[i][j + 1] < 0) continue;
            if (topo[i][j - 1] < topo[i][j] && topo[i][j + 1] < topo[i][j] &&
                topo[i - 1][j] > topo[i][j] && topo[i + 1][j] > topo[i][j]) ispass[i][j] = 1;
            else ispass[i][j] = 0;
        }
    }
    for (int i = 1; i <= r; i++) {
        if (topo[i][1] >= 0) mem[i][1][0] = topo[i][1];
    }
    for (int i = 2; i <= c; i++) {
        for (int j = 1; j <= r; j++) {
            if (topo[j][i] < 0) continue;
            for (int k = 0; k <= n; k++) {
                if (ispass[j][i] && k == 0) continue;
                if (ispass[j][i]) {
                    for (int l = -1; l <= 1; l++) {
                        mem[j][i][k] = small(mem[j][i][k], mem[j + l][i - 1][k - 1] + topo[j][i]);
                    }
                }
                else {
                    for (int l = -1; l <= 1; l++) {
                        mem[j][i][k] = small(mem[j][i][k], mem[j + l][i - 1][k] + topo[j][i]);
                    }
                }
            }
        }
    }

    for (int i = 1; i <= r; i++) {
        res = small(res, mem[i][c][n]);
    }
    if (res == INF) printf("impossible");
    else printf("%d", res);
    return 0;
}