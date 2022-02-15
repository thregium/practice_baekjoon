#include <stdio.h>

/*
���� : A * B(A, B <= 16) ũ���� �����ǿ� N(N <= 40)���� ��ֹ��� �ִ�.
��ֹ����� ������ �ʰ� �������� (1, 1)���� (A, B)���� �ִܰŸ��� �̵��ϴ� ����� ���� ���Ѵ�.

�ذ� ��� : ���̳��� ���α׷����� ���� ���� �� �ִ�.
��ֹ��� �ִ� ��Ҹ� �����ϰ� ���ʰ� �Ʒ����� ���� ���س����� �ȴ�.

�ֿ� �˰��� : DP

��ó : JOI 2007�� 6��
*/

long long mem[32][32], obst[32][32];

int main(void) {
    int a, b, n, x, y;
    for (int tt = 0; tt < 1; tt++) {
        scanf("%d %d", &a, &b);
        if (a == 0) break;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d %d", &x, &y);
            obst[x][y] = 1;
        }

        mem[1][1] = 1;
        for (int i = 1; i <= a; i++) {
            for (int j = 1; j <= b; j++) {
                if (!obst[i][j + 1]) mem[i][j + 1] += mem[i][j];
                if (!obst[i + 1][j]) mem[i + 1][j] += mem[i][j];
            }
        }
        printf("%lld\n", mem[a][b]);
        for (int i = 1; i <= a + 1; i++) {
            for (int j = 1; j <= b + 1; j++) {
                mem[i][j] = 0;
                obst[i][j] = 0;
            }
        }
    }
    return 0;
}