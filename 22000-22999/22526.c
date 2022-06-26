#include <stdio.h>
#define INF 1012345678

/*
���� : N(N <= 16)���� ���������� �̷���� ������ �ִ�. �� ���������� �ƹ� �����γ� �� �� ������,
��� ���������� ���� ������ Ŭ������ �� �ִ�. �� ���������� ���� �������� �ְ�, �� ������������
�������� �� ���� ��� �� �� ������, ��� ���� ���� ���� �� ���� �ִ�.
�̶�, �� ���������� ��� �� �����ۺ� Ŭ���� �ð��� �־�����
��ü ������ Ŭ�����ϴµ� ��� �ּ� �ð��� ���Ѵ�.

�ذ� ��� : ��Ʈ�ʵ带 �̿��� DP�� �ذ� �����ϴ�. �ذ��� ���������� ����� ��Ʈ����ŷ�� ���·�
�����Ͽ� ���̳��� ���α׷����� �Ѵ�. �� �ܰ踶�� ���� ���� ���� ���������� ���� ���� �ִ�
������ ��� ���� ������ �� �� �ִ� ������ ���� �׶��� �ð����� �����صд�.
�̸� �ݺ��ϸ� ��� ���������� ���� ���� �ּ� �ð��� Ȯ���ϸ� ���� �ȴ�.

�ֿ� �˰����� : DP, ��ƮDP

��ó : JAG 2011D C��
*/

int t[32][32], bit[16], mem[65536];

int small(int a, int b) {
    return a < b ? a : b;
}

int main(void) {
    int n;
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= n; j++) {
                scanf("%d", &t[i][j]);
            }
        }
        for (int i = 1; i < (1 << n); i++) mem[i] = INF;
        for (int i = 0; i < (1 << n); i++) {
            for (int j = 0; j < n; j++) bit[j] = ((i >> j) & 1);
            for (int j = 0; j < n; j++) {
                if (bit[j]) continue;
                mem[i + (1 << j)] = small(mem[i + (1 << j)], mem[i] + t[j][0]);
                for (int k = 1; k <= n; k++) {
                    if(bit[k - 1]) mem[i + (1 << j)] = small(mem[i + (1 << j)], mem[i] + t[j][k]);
                }
            }
        }
        printf("%d\n", mem[(1 << n) - 1]);
    }
    return 0;
}