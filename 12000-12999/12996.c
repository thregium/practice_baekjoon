#include <stdio.h>
#include <string.h>
#define MOD 1000000007

/*
���� : S(S <= 50)���� ���� 3�� �� �Ϻ�(�Ǵ� ����)�� �۰��Ѵ�. �� ����� �۰��� ���� ���� �־��� ��,
�̷��� �۰��� ���� ���� �������� �Ҵ��ϴ� ����� ���� ���Ѵ�.

�ذ� ��� : S�� 3���� �۰��� ���� ���� ������ �ΰ� ž�ٿ� DP�� �Ѵ�. ��� ����� ���� ���ϸ� �ȴ�.

�ֿ� �˰��� : DP
*/

int mem[64][64][64][64];

int dp(int s, int d, int k, int h) {
    int r = 0;
    if (s == 0) {
        if (d == 0 && k == 0 && h == 0) return mem[s][d][k][h] = 1;
        else return mem[s][d][k][h] = 0;
    }
    if (mem[s][d][k][h] >= 0) return mem[s][d][k][h];
    if (d > 0) r = (r + dp(s - 1, d - 1, k, h)) % MOD;
    if (k > 0) r = (r + dp(s - 1, d, k - 1, h)) % MOD;
    if (h > 0) r = (r + dp(s - 1, d, k, h - 1)) % MOD;
    if (d > 0 && k > 0) r = (r + dp(s - 1, d - 1, k - 1, h)) % MOD;
    if (d > 0 && h > 0) r = (r + dp(s - 1, d - 1, k, h - 1)) % MOD;
    if (k > 0 && h > 0) r = (r + dp(s - 1, d, k - 1, h - 1)) % MOD;
    if (d > 0 && k > 0 && h > 0) r = (r + dp(s - 1, d - 1, k - 1, h - 1)) % MOD;
    return mem[s][d][k][h] = r;
}

int main(void) {
    int s, d, k, h;
    scanf("%d %d %d %d", &s, &d, &k, &h);
    memset(mem, -1, 16777216 * sizeof(int));
    printf("%d", dp(s, d, k, h));
    return 0;
}