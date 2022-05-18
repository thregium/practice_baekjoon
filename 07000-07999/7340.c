#include <stdio.h>
#define INF 1012345678

/*
���� : �� 3�밡 1�� ������ �ִ�. N(N <= 30)���� ���� �ֵ鿡 ���� �̵� �ð��� �־��� ��, �� 3��� ��� ������
�������� ���� �� 3�밡 �����̴� �̵� �ð� ���� �ּڰ��� ���Ѵ�.
��, �� ������ �����������θ� �湮 �����ϴ�.

�ذ� ��� : �� 3���� ��ġ������ �ִ� �ð� ���� ������ ����, 2�� �������� N�� �������� ������������ ����
������ ������ ������. ���������� N�� ������ ���� �ִ� �������� �̵� �ð� �� ���
���� ���� ���� ���� ���� �ȴ�.

�ֿ� �˰��� : DP

��ó : Tehran 1999 F��
*/

int dist[32][32], mem[32][32][32];

int small(int a, int b) {
    return a < b ? a : b;
}

int big(int a, int b) {
    return a > b ? a : b;
}

int main(void) {
    int t, n, r;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) dist[i][j] = INF;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                scanf("%d", &dist[i][j]);
                dist[j][i] = dist[i][j];
            }
        }
        /*
        for (int k = 1; k <= n; k++) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    dist[i][j] = small(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        */

        for (int i = 0; i < 32; i++) {
            for (int j = 0; j < 32; j++) {
                for (int k = 0; k < 32; k++) mem[i][j][k] = INF;
            }
        }
        mem[1][1][1] = 0;
        r = INF;
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j < i; j++) {
                for (int k = 1; k < i; k++) {
                    for (int l = 1; l < i; l++) {
                        if (big(big(j, k), l) < i - 1) continue;
                        mem[i][k][l] = small(mem[i][k][l], mem[j][k][l] + dist[j][i]);
                        mem[j][i][l] = small(mem[j][i][l], mem[j][k][l] + dist[k][i]);
                        mem[j][k][i] = small(mem[j][k][i], mem[j][k][l] + dist[l][i]);
                        if (i == n) {
                            r = small(r, mem[i][k][l]);
                            r = small(r, mem[j][i][l]);
                            r = small(r, mem[j][k][i]);
                        }
                    }
                }
            }
        }

        if (r == INF) return 1;
        printf("%d\n", r);
    }
    return 0;
}