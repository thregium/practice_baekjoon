#include <stdio.h>

/*
���� : K(K <= 20)�� �־��� �� (1 + x)(1 + x + x^2)(1 + x + ... + x^k)�� ������ N(N <= K * (K - 1) / 2)������ ���Ѵ�.

�ذ� ��� : ������ ���̳��� ���α׷����� ���� ���� ���� �� �ִ�. K�� �ö� �� ���� �ش��ϴ� ���� ���س����� �ȴ�.

�ֿ� �˰��� : ����, DP

��ó : ������ 2015 D��
*/

long long mem[32][256];

int main(void) {
    int t, k, n;
    mem[1][0] = 1, mem[1][1] = 1;
    for (int i = 2; i <= 20; i++) {
        for (int j = 0; j <= i; j++) {
            for (int k = 0; k <= ((i - 1) * i) >> 1; k++) mem[i][j + k] += mem[i - 1][k];
        }
    }
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d %d", &k, &n);
        printf("%lld\n", mem[k][n]);
    }
    return 0;
}