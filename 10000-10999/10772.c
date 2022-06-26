#include <stdio.h>

/*
���� : N(N <= 200)���� ������ K(K <= N)������ ������ �ֵ� �ڿ� ������ ������� ���ư��� ������
��� �տ� ������ ����� �������� ���� ���ư����� �ִ� ����� ���� ���Ѵ�.

�ذ� ��� : ���� ���Ұ� ����. �� ���� ���̳��� ���α׷������� ����ϸ� �ȴ�.

�ֿ� �˰����� : ����, ���շ�, DP

��ó : CCC 2015 J5��
*/

long long part[256][256];

int main(void) {
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            if (j == 1 || j == i) part[i][j] = 1;
            else part[i][j] = part[i - 1][j - 1] + part[i - j][j];
        }
    }
    printf("%lld", part[n][k]);
    return 0;
}