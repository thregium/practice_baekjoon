#include <stdio.h>

/*
���� : N * N(N <= 7) ũ���� ���ڷ� ī����� �þ���Ҵ�. ī���� ���� �Ʒ����� ������ ���� ���� �Ǵ� ���������� �̵��ϸ�
���� �� �ִ� ������ ���� ���� ���Ѵ�.

�ذ� ��� : ī���� ���̴� �߿����� �ʰ� ���� ������ �ʿ��ϱ� ������ ī�忡�� ���� ���� �������� ���´�.
�� ����, ���� �Ʒ����� �����ϴ� DP�� ���� ������ �������� ���� ���ϸ� �ȴ�.

�ֿ� �˰��� : DP

��ó : USACO 2007O B1��
*/

int cards[8][8], mem[8][8];
char buff[8];

int big(int a, int b) {
    return a > b ? a : b;
}

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = n; i > 0; i--) {
        for (int j = 1; j <= n; j++) {
            scanf("%s", buff);
            if (buff[0] == 'K') cards[i][j] = 13;
            else if (buff[0] == 'Q') cards[i][j] = 12;
            else if (buff[0] == 'J') cards[i][j] = 11;
            else if (buff[0] == 'T') cards[i][j] = 10;
            else if (buff[0] == 'A') cards[i][j] = 1;
            else cards[i][j] = buff[0] - '0';
            if (cards[i][j] <= 0 || cards[i][j] > 13) return 1;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            mem[i][j] = big(mem[i - 1][j], mem[i][j - 1]) + cards[i][j];
        }
    }
    printf("%d", mem[n][n]);
    return 0;
}