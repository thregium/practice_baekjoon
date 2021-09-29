#include <stdio.h>

/*
���� : ���԰� M(M <= 1000)�̰� ����� F(F <= 10^6)�� �ڵ����� �ִ�. �� �ڵ����� ��ǰ N(N <= 20)���� �� �� �ִ�.
�� ��ǰ�� ���� M_i(M_i <= 1000)�� �߰��ϰ� ��� F_i(F_i <= 10^6)�� �߰��Ѵ�. �̶�, ���� ��� �ִ� ����� ���� ����
�޾ƾ� �ϴ� ��ǰ�� ������������ ��� ����Ѵ�. ���� �ʴ� ���� ���� �����ٸ� "NONE"�� ����Ѵ�.

�ذ� ��� : 2^N���� ����� ��Ʈ����ŷ�� ���� ���� �غ��鼭 ���� F�� �� / M�� ���� ���� ���� ������ ã�´�.
�� ������ ��ȣ�� ��Ʈ����ŷ�� ���� ������ ����, 1������ ���ʷ� ��Ʈ ������ �ϸ鼭 ����ϸ�
�ش� ������ ������������ ����� �� �ִ�.

�ֿ� �˰��� : ���Ʈ ����

��ó : USACO 2010M B1��
*/

int parts[32][2];

int main(void) {
    int f, m, ft, mt, n, bestcomb = 0;
    double best;
    scanf("%d %d %d", &f, &m, &n);
    best = (double)f / m;
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &parts[i][0], &parts[i][1]);
    }
    for (int i = 0; i < (1 << n); i++) {
        ft = f, mt = m;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                ft += parts[j][0];
                mt += parts[j][1];
            }
        }
        if ((double)ft / mt > best) {
            best = (double)ft / mt;
            bestcomb = i;
        }
    }
    if (bestcomb == 0) printf("NONE");
    else {
        for (int i = 0; i < n; i++) {
            if (bestcomb & (1 << i)) printf("%d\n", i + 1);
        }
    }
    return 0;
}