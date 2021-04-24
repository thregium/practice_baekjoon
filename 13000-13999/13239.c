#include <stdio.h>
#define MOD 1000000007

/*
���� : ���װ�� nCk�� ���Ѵ�.(n, k <= 1000)

�ذ� ��� : n�� k�� ������ ���� ���̳��� ���α׷����� ���� �ذ� �����ϴ�.
nCk = (n-1)C(k-1) + (n-1)Ck�� ������ �̿��Ѵ�.

�ֿ� �˰��� : ���̳��� ���α׷���, ���շ�

��ó : AIPO 2016P 6��
*/

int comb[1024][1024];

int main(void) {
    comb[0][0] = 1;
    for (int i = 1; i <= 1000; i++) {
        comb[i][0] = comb[i - 1][0];
        for (int j = 1; j <= i; j++) {
            comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % MOD;
        }
    }
    int t, n, k;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d %d", &n, &k);
        printf("%d\n", comb[n][k]);
    }
    return 0;
}