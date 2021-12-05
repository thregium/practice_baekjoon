#include <stdio.h>
#define MOD 1000000007

/*
���� : 0���� �������� �ʰ� �� �ڸ����� �񳻸������� N(N <= 1000)�ڸ� �ڿ��� ��� �ִ� A(A <= 1000)����
������ ���������� ���� ������ ���� ������ ���Ѵ�.

�ذ� ��� : ���� ����, A, ������ ����, �ֱ��� ���� ���� ������ ��� ���̳��� ���α׷����� �Ѵ�.
�̶�, ������ ���� �������� � ���� �� �� ������ �����ؾ� �Ѵ�.

�ֿ� �˰��� : DP

��ó : SRM 431 D1B
*/

int mem[1024][10][10][10]; //���� ����, A, ������ ����(9�� ���� ������), �ֱ��� ��

int main(void) {
    int n, a, r = 0;
    scanf("%d %d", &n, &a);
    for (int i = 1; i <= 9; i++) {
        for (int j = i; j <= 9; j++) {
            mem[2][1][j - i][j]++;
        }
    }
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= 9; j++) {
            for (int k = 0; k <= 9; k++) {
                for (int l = 1 + (k == 9 ? 0 : k); l <= 9; l++) {
                    for (int m = l; m <= 9; m++) {
                        if (k == 9) mem[i + 1][j][m - l][m] = (mem[i + 1][j][m - l][m] + mem[i][j][k][l]) % MOD;
                        else if (m == l + k) mem[i + 1][j][k][m] = (mem[i + 1][j][k][m] + mem[i][j][k][l]) % MOD;
                        else mem[i + 1][j + 1][9][m] = (mem[i + 1][j + 1][9][m] + mem[i][j][k][l]) % MOD;
                    }
                }
            }
        }
    }
    if (a > 9 || n == 1) {
        if (a > 9 || a > n) printf("0");
        else printf("9");
        return 0;
    }
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            r = (r + mem[n][a][i][j]) % MOD;
        }
    }
    printf("%d", r);
    return 0;
}