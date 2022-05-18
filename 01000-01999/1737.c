#include <stdio.h>
#include <string.h>
#include <math.h>
#define MOD 1000000000000000000
#define PI acos(-1)

/*
���� : �ڿ��� N(N <= 1000)�� �־��� ��, p(n) = p(n - 1) + p(n - pi) (n > pi), p(n) = 1(n <= pi)��
���ǵ� �Լ��� p(n) ���� ���Ѵ�.

�ذ� ��� : [������ 1�� ����][������ ������ ����]�� 2���� DP�� �ϸ� �ȴ�. �Ǽ� ������ �����Ѵ�.

�ֿ� �˰��� : DP

��ó : IPSC 2001 F��
*/

long long mem[1024][384];

long long dp(int n, int o, int p) {
    if (n - o - p * PI < -0.00000001) return 0;
    else if (n - o - p * PI <= PI + 0.000000001) return 1;
    if (mem[o][p] >= 0) return mem[o][p];
    else return mem[o][p] = (dp(n, o + 1, p) + dp(n, o, p + 1)) % MOD;
}

int main(void) {
    int n;
    memset(mem, -1, sizeof(mem));
    scanf("%d", &n);
    printf("%lld", dp(n, 0, 0));
    return 0;
}