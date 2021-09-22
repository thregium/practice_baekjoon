#include <stdio.h>
#define INF 1012345678

/*
���� : R * C(R, C <= 100) ũ���� ���ڿ� ������ �����ִ�. ���� �� ĭ���� ������ �Ʒ� ĭ���� �̵��ϸ�
���� �� �ִ� �� �� �� �ִ��� ���Ѵ�. ��, ���� ���� 2ȸ �̻� �ӹ��� �� ����, �밢�� �Ǵ� �������� ������ ��츸 �̵� �����ϴ�.

�ذ� ��� : ���̳��� ���α׷����� ���� �ش� ���� �� �ٸ��� ���� �� �ִ� �ִ��� ���ذ��� Ǯ�� �ȴ�.

�ֿ� �˰��� : DP

��ó : USACO 2006X G4��
*/

int coins[128][128], mem[128][128];

int big(int a, int b) {
    return a > b ? a : b;
}

int main(void) {
    int r, c;
    scanf("%d %d", &r, &c);
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            scanf("%d", &coins[i][j]);
        }
    }
    for (int i = 1; i <= r + 1; i++) mem[i][0] = -INF;
    for (int i = 1; i <= c; i++) {
        for (int j = 1; j <= r; j++) {
            mem[j][i] = coins[j][i] + big(mem[j][i - 1], big(mem[j - 1][i - 1], mem[j + 1][i - 1]));
        }
        mem[r + 1][i] = -INF;
    }
    printf("%d", mem[r][c]);
    return 0;
}