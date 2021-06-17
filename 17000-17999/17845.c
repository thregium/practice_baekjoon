#include <stdio.h>

/*
���� : N(N <= 10000)��ŭ�� �ð��� �ְ�, K(K <= 1000)������ ������ �ִ�. �� ������ ���� �ð��� �߿䵵�� �־��� ��,
�־��� �ð� ���� ���θ� ���� ���� �� �ִ� �߿䵵�� �ִ�ġ�� ���Ѵ�. ��, �� ������ ������ �����ؾ� �߿䵵�� ���� �� �ִ�.

�ذ� ��� : �Ϲ����� ���� ������ ����.

�ֿ� �˰��� : DP, ����

��ó : UNIST 1ȸ H��
*/

int mem[1024][10240];

int big(int a, int b) {
    return a > b ? a : b;
}

int main(void) {
    int n, k, im, t, r = 0;
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= k; i++) {
        scanf("%d %d", &im, &t);
        for (int j = 0; j <= n; j++) {
            mem[i][j] = mem[i - 1][j];
            if (j >= t) mem[i][j] = big(mem[i][j], mem[i - 1][j - t] + im);
        }
    }
    for (int i = 0; i <= n; i++) {
        r = big(r, mem[k][i]);
    }
    printf("%d", r);
    return 0;
}