#include <stdio.h>
#include <stdlib.h>
#define INF 1012345678
#define INF2 12345678987654321

/*
���� : N(N <= 1000)���� ���� ���ʷ� ����, �� ���� P(P <= 100)���� ������ �����´�.
�� ���ǿ��� ������ ��ǥ �з�(<= 10^9, �ڿ���)�� �ִ�. �� ���� ������ ���ǵ��� ������ �������� �����Ͽ�
��� ������ �з��� ���ߴ� �� �ɸ��� �з� �̵� Ƚ���� �ּڰ��� ���Ѵ�. �з��� �ʱ⿡ 0�̸�
1ȸ �̵��� 1 ������ �ø��ų� ���� �� �ִ�.

�ذ� ��� : �� ���� ���� ���ǰ� �� ���ǿ� ���� �׶��� �з� �̵� ������ (�ִ� - �ּڰ�) * 2����
|���� �з� - �� �з�|�� �� �Ͱ� ����. �̸� �̿��� �� ���� ���� ������ ���·� �Ͽ�
���̳��� ���α׷����� �ϸ� �� ���� ���� ���Ǹ����� �з� �̵� Ƚ���� ���� �� �ְ�,
������ ���� �з� �̵� Ƚ�� ��� �ּڰ��� ���� ���� �ȴ�.

�ֿ� �˰��� : DP, �׸��� �˰���

��ó : GCJ 2022B B��
*/

int prod[1024][128];
long long mem[1024][128];

long long small(long long a, long long b) {
    return a < b ? a : b;
}

int main(void) {
    int t, n, p, hi, lo;
    long long res;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        scanf("%d %d", &n, &p);
        for (int i = 0; i < p; i++) mem[0][i] = INF2;
        mem[0][0] = 0;
        for (int i = 1; i <= n; i++) {
            hi = 0, lo = INF;
            for (int j = 0; j < p; j++) {
                scanf("%d", &prod[i][j]);
                if (prod[i][j] > hi) hi = prod[i][j];
                if (prod[i][j] < lo) lo = prod[i][j];
            }

            for (int j = 0; j < p; j++) {
                mem[i][j] = INF2;
                for (int k = 0; k < p; k++) {
                    mem[i][j] = small(mem[i][j], mem[i - 1][k] +
                        small(hi - lo + llabs(prod[i - 1][k] - lo) + llabs(prod[i][j] - hi),
                        hi - lo + llabs(prod[i - 1][k] - hi) + llabs(prod[i][j] - lo)));
                }
            }
        }

        res = INF2;
        for (int i = 0; i < p; i++) {
            if (mem[n][i] < res) res = mem[n][i];
        }
        printf("Case #%d: %lld\n", tt, res);
    }
    return 0;
}