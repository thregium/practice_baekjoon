#include <stdio.h>
#define MOD 1000000007

/*
���� : N(N <= 5000) ��Ʈ�� �ο� ���� �ִ�. �̶�, M(M <= 10^6)���� ��Ģ�� ��� ��Ű�� �������� ���Ѵ�.
�� ��Ģ�� [L, R] ������ ��� ���ų� �ٸ� ���� �ִٴ� �������� �̷���� �ִ�.

�ذ� ��� : �켱 �� ��ġ���� ���� ������ �� ��ġ���� ���� Ȯ���ϸ鼭 ���� ������ �׷����� ���´�.
�׷� ����, �� ��ġ���� �ٸ� ���� ���� ����� ��ġ���� �׷��� ������ ���� Ȯ���ϸ鼭
�ش� ��ġ���� �޶�� �ϴ� ���� ���� �׷� ������ �����Ѵ�.
�̸� �̿��� X��° ������ Ȯ������ �� �ֱ� Y���� ���� ���� ���·� �Ͽ� �� ���� ����� ����
���� ���̳��� ���α׷����� ���� ���ϸ� �ȴ�.

�ֿ� �˰��� : DP, ������?

��ó : MidC 2019 K��
*/

int group[5120], same[5120], diff[5120], gdiff[5120], mem[5120][5120];
char buff[16];

int main(void) {
    int n, m, a, b, r = 0;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        group[i] = i;
        gdiff[i] = 103000;
    }
    for (int i = 0; i < m; i++) {
        scanf("%d %d %s", &a, &b, buff);
        if (buff[0] == 's') {
            if (b > same[a]) same[a] = b;
        }
        else {
            if (a > diff[b]) diff[b] = a;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (group[i] != group[i - 1]) group[i] = group[i - 1] + 1;
        for (int j = i; j <= same[i]; j++) group[j] = group[i];
    }
    for (int i = 1; i <= n; i++) {
        if (group[i] - group[diff[i]] < gdiff[group[i]]) gdiff[group[i]] = group[i] - group[diff[i]];
    }
    mem[0][0] = 2;
    for (int i = 1; i <= group[n]; i++) {
        if (gdiff[i] == 0) mem[i][1] = 0;
        for (int j = 1; j <= gdiff[i]; j++) {
            mem[i][j] = (mem[i - 1][j - 1] + mem[i][j]) % MOD;
            mem[i + 1][1] = (mem[i + 1][1] + mem[i][j]) % MOD;
        }
    }
    for (int i = 1; i <= gdiff[group[n]]; i++) r = (r + mem[group[n]][i]) % MOD;
    printf("%d", r);
    return 0;
}