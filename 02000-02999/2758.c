#include <stdio.h>

/*
���� : M(M <= 2000)���� �ڿ��� ��� N(N <= 10)���� �̴� ����� �������� ���Ѵ�. ��, ���� ���� ���� ���� 2�� �̻��̾�� �Ѵ�.

�ذ� ��� : ���̳��� ���α׷����� ���� �ذ��Ѵ�. ���������� ���� ���� ���� ���� ������ ������ �θ�,
�� ��쿡�� �̴� ���� ������ (���� �� / 2���� 1�� �� �̾��� ���� ����(���� ���� �̴� ���)) +
(���� �� - 1���� ���縸ŭ �̾��� ���� ����(���� ���� ���� ���� ���))�̴�.

�ֿ� �˰��� : DP

��ó : GNY 2004 C�� // PacNW 2004 C��
*/

long long mem[12][2048];

int main(void) {
    //freopen("E:\\PS\\ICPC\\North America\\Pacific Northwest\\2004\\sampleInput\\c.in", "r", stdin);
    for (int i = 0; i <= 2000; i++) mem[0][i] = 1;
    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= 2000; j++) {
            mem[i][j] = mem[i - 1][j >> 1] + mem[i][j - 1];
        }
    }
    int t, n, m;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d %d", &n, &m);
        printf("%lld\n", mem[n][m]);
    }
    return 0;
}