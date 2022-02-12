#include <stdio.h>
#define INF 1012345678

/*
���� : M(M <= 100)���� ���ο��� C(C <= 100)���� ��ǻ�͸� �ȷ��� �Ѵ�. �� ���ε��� ������� ����,
�Ĵ� ��ǻ���� �������� �Ĵ� ����(<= 100000, �ڿ���)�� �־�����. �̶�, ��ǻ�͸� �ȾƼ� ���� �� �ִ�
�ִ� ������ ���Ѵ�. ��� ��ǻ�͸� ���� �ʾƵ� �ȴ�.

�ذ� ��� : �� ��°�� ���α��� �Ⱦ��� �� ���� ��ǻ���� ���� ���·� �ϰ� �׶��� �ִ� ������
������ �Ͽ� DP�� �����ϸ� �ȴ�.

�ֿ� �˰��� : DP, ����

��ó : GCPC 2016 J��
*/

int merch[128][128], mem[128][128];

int big(int a, int b) {
    return a > b ? a : b;
}

int main(void) {
    int c, m, r = -INF;
    scanf("%d %d", &c, &m);
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= c; j++) {
            scanf("%d", &merch[i][j]);
            mem[i][j] = -INF;
            mem[0][j - 1] = -INF;
        }
        mem[i][0] = -INF;
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j <= c; j++) {
            for (int k = j; k <= c; k++) {
                mem[i][j] = big(mem[i][j], mem[i - 1][k] + merch[i][k - j]);
            }
        }
    }
    for (int i = 0; i <= c; i++) {
        r = big(r, mem[m][i]);
    }
    printf("%d", r);
    return 0;
}