#include <stdio.h>
#define MOD 1000000

/*
���� : N(N <= 1000)�ϵ����� �⼮�� ��� ���ٻ��� ���� �� �ִ� ��츦 ��� ���Ѵ�.
3�� ���� �Ἦ �ϰų� 2ȸ �̻� ���� ���� ������ ���ٻ��� ���� �� �ִ�.

�ذ� ��� : ������ Ƚ���� �������� �Ἦ�� Ƚ���� ������ �ΰ� DP�� �Ѵ�. ����� ���� �� �����ؾ� �Ѵ�.

�ֿ� �˰��� : DP
*/

int mem[1024][6];

int main(void) {
    int n, r = 0;
    scanf("%d", &n);
    mem[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        mem[i][0] = mem[i - 1][0];
        mem[i][3] = mem[i - 1][3];
        for (int j = 3; j < 6; j++) {
            mem[i][3] = (mem[i][3] + mem[i - 1][j - 3]) % MOD;
        }
        for (int j = 1; j < 3; j++) {
            mem[i][0] = (mem[i][0] + mem[i - 1][j]) % MOD;
            mem[i][j] = (mem[i][j] + mem[i - 1][j - 1]) % MOD;
            mem[i][3] = (mem[i][3] + mem[i - 1][j + 3]) % MOD;
            mem[i][j + 3] = (mem[i][j + 3] + mem[i - 1][j + 2]) % MOD;
        }
    }
    for (int i = 0; i < 6; i++) {
        r = (r + mem[n][i]) % MOD;
    }
    printf("%d", r);
    return 0;
}